#include "Spawn.h"
#include "Sequence.h"
#include "DelayTime.h"
#include "ofLog.h"

//
// Spawn
//

Spawn *Spawn::create(FiniteTimeAction *action1, ...)
{
    va_list params;
    va_start(params, action1);

    Spawn *ret = Spawn::createWithVariableList(action1, params);

    va_end(params);

    return ret;
}

Spawn *Spawn::createWithVariableList(FiniteTimeAction *action1, va_list args)
{
    FiniteTimeAction *now;
    FiniteTimeAction *prev = action1;
    bool oneAction = true;

    while (action1) {
        now = va_arg(args, FiniteTimeAction *);
        if (now) {
            prev = createWithTwoActions(prev, now);
            oneAction = false;
        }
        else {
            // If only one action is added to Spawn, make up a Spawn by adding a simplest finite time action.
            if (oneAction) {
                prev = createWithTwoActions(prev, ExtraAction::create());
            }
            break;
        }
    }

    return ((Spawn *)prev);
}

Spawn *Spawn::create(const std::vector<FiniteTimeAction *> &arrayOfActions)
{
    Spawn *ret = nullptr;
    do {
        auto count = arrayOfActions.size();
        if (count == 0) {
            break;
        }

        auto prev = arrayOfActions.at(0);
        if (count > 1) {
            for (int i = 1; i < arrayOfActions.size(); ++i) {
                prev = createWithTwoActions(prev, arrayOfActions.at(i));
            }
        }
        else {
            // If only one action is added to Spawn, make up a Spawn by adding a simplest finite time action.
            prev = createWithTwoActions(prev, ExtraAction::create());
        }
        ret = static_cast<Spawn *>(prev);
    }
    while (0);

    return ret;
}

Spawn *Spawn::createWithTwoActions(FiniteTimeAction *action1, FiniteTimeAction *action2)
{
    Spawn *spawn = new(std::nothrow) Spawn();
    spawn->initWithTwoActions(action1, action2);

    return spawn;
}

bool Spawn::initWithTwoActions(FiniteTimeAction *action1, FiniteTimeAction *action2)
{
    if (action1 == nullptr) {
        ofLogError("ofxActionError") << __FUNCTION__ << ": action1 can't be nullptr!";
        return false;
    }

    if (action2 == nullptr) {
        ofLogError("ofxActionError") << __FUNCTION__ << ": action2 can't be nullptr!";
        return false;
    }

    bool ret = false;

    float d1 = action1->getDuration();
    float d2 = action2->getDuration();

    if (ActionInterval::initWithDuration(MAX(d1, d2))) {
        m_One = action1;
        m_Two = action2;

        if (d1 > d2) {
            m_Two = Sequence::createWithTwoActions(action2, DelayTime::create(d1 - d2));
        }
        else if (d1 < d2) {
            m_One = Sequence::createWithTwoActions(action1, DelayTime::create(d2 - d1));
        }

        m_One->retain();
        m_Two->retain();

        ret = true;
    }

    return ret;
}

Spawn *Spawn::clone(void) const
{
    // no copy constructor
    auto a = new(std::nothrow) Spawn();
    a->initWithTwoActions(m_One->clone(), m_Two->clone());

    return a;
}

Spawn::~Spawn(void)
{
    SAFE_RELEASE(m_One);
    SAFE_RELEASE(m_Two);
}

void Spawn::startWithTarget(ActionTarget *target)
{
    ActionInterval::startWithTarget(target);
    m_One->startWithTarget(target);
    m_Two->startWithTarget(target);
}

void Spawn::stop(void)
{
    m_One->stop();
    m_Two->stop();
    ActionInterval::stop();
}

void Spawn::update(float time)
{
    if (m_One) {
        m_One->update(time);
    }
    if (m_Two) {
        m_Two->update(time);
    }
}

Spawn *Spawn::reverse() const
{
    return Spawn::createWithTwoActions(m_One->reverse(), m_Two->reverse());
}
