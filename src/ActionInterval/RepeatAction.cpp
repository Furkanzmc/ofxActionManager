#include "RepeatAction.h"
#include "ActionInstant.h"
#include "ofLog.h"

//
// Repeat
//

Repeat *Repeat::create(FiniteTimeAction *action, unsigned int times)
{
    Repeat *repeat = new(std::nothrow) Repeat();
    repeat->initWithAction(action, times);

    return repeat;
}

bool Repeat::initWithAction(FiniteTimeAction *action, unsigned int times)
{
    float d = action->getDuration() * times;

    if (ActionInterval::initWithDuration(d)) {
        m_Times = times;
        m_InnerAction = action;
        action->retain();

        m_ActionInstant = dynamic_cast<ActionInstant *>(action) ? true : false;
        //an instant action needs to be executed one time less in the update method since it uses startWithTarget to execute the action
        if (m_ActionInstant) {
            m_Times -= 1;
        }
        m_Total = 0;

        return true;
    }

    return false;
}

Repeat *Repeat::clone(void) const
{
    // no copy constructor
    auto a = new(std::nothrow) Repeat();
    a->initWithAction(m_InnerAction->clone(), m_Times);
    return a;
}

Repeat::~Repeat(void)
{
    SAFE_RELEASE(m_InnerAction);
}

void Repeat::startWithTarget(ActionTarget *target)
{
    m_Total = 0;
    m_NextDt = m_InnerAction->getDuration() / m_Duration;
    ActionInterval::startWithTarget(target);
    m_InnerAction->startWithTarget(target);
}

void Repeat::stop(void)
{
    m_InnerAction->stop();
    ActionInterval::stop();
}

// issue #80. Instead of hooking step:, hook update: since it can be called by any
// container action like Repeat, Sequence, Ease, etc..
void Repeat::update(float dt)
{
    if (dt >= m_NextDt) {
        while (dt > m_NextDt && m_Total < m_Times) {
            m_InnerAction->update(1.0f);
            m_Total++;

            m_InnerAction->stop();
            m_InnerAction->startWithTarget(m_Target);
            m_NextDt = m_InnerAction->getDuration() / m_Duration * (m_Total + 1);
        }

        // fix for issue #1288, incorrect end value of repeat
        if (dt >= 1.0f && m_Total < m_Times) {
            m_Total++;
        }

        // don't set an instant action back or update it, it has no use because it has no duration
        if (!m_ActionInstant) {
            if (m_Total == m_Times) {
                m_InnerAction->update(1);
                m_InnerAction->stop();
            }
            else {
                m_InnerAction->update(dt - (m_NextDt - m_InnerAction->getDuration() / m_Duration));
            }
        }
    }
    else {
        m_InnerAction->update(fmodf(dt * m_Times, 1.0f));
    }
}

bool Repeat::isDone(void) const
{
    return m_Total == m_Times;
}

Repeat *Repeat::reverse() const
{
    return Repeat::create(m_InnerAction->reverse(), m_Times);
}

//
// RepeatForever
//
RepeatForever::~RepeatForever()
{
    SAFE_RELEASE(m_InnerAction);
}

RepeatForever *RepeatForever::create(ActionInterval *action)
{
    RepeatForever *ret = new(std::nothrow) RepeatForever();
    if (ret && ret->initWithAction(action)) {
        return ret;
    }
    SAFE_RELEASE(ret);
    return nullptr;
}

bool RepeatForever::initWithAction(ActionInterval *action)
{
    if (action == nullptr) {
        ofLogError("ofxActionManager") << __FUNCTION__ << ": action can't be nullptr!";
        return false;
    }

    action->retain();
    m_InnerAction = action;
    return true;
}

RepeatForever *RepeatForever::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) RepeatForever();
    a->initWithAction(m_InnerAction->clone());
    return a;
}

void RepeatForever::startWithTarget(ActionTarget *target)
{
    ActionInterval::startWithTarget(target);
    m_InnerAction->startWithTarget(target);
}

void RepeatForever::step(float dt)
{
    m_InnerAction->step(dt);
    if (m_InnerAction->isDone()) {
        float diff = m_InnerAction->getElapsed() - m_InnerAction->getDuration();
        if (diff > m_InnerAction->getDuration())
            diff = fmodf(diff, m_InnerAction->getDuration());
        m_InnerAction->startWithTarget(m_Target);
        // to prevent jerk. issue #390, 1247
        m_InnerAction->step(0.0f);
        m_InnerAction->step(diff);
    }
}

bool RepeatForever::isDone() const
{
    return false;
}

RepeatForever *RepeatForever::reverse() const
{
    return RepeatForever::create(m_InnerAction->reverse());
}
