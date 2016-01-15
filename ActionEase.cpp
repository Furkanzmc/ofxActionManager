#include "ActionEase.h"
#include "ofLog.h"
#ifndef M_PI_X_2
#define M_PI_X_2 (float)M_PI * 2.0f
#endif

ActionEase::ActionEase()
{

}

bool ActionEase::initWithAction(ActionInterval *action)
{
    if (action == nullptr) {
        ofLogError("ofxActionManager") << __FUNCTION__ << ": action couldn't be nullptr!";
        return false;
    }

    if (ActionInterval::initWithDuration(action->getDuration())) {
        m_Inner = action;
        return true;
    }

    return false;
}

ActionEase::~ActionEase(void)
{
    SAFE_RELEASE(m_Inner);
}

void ActionEase::startWithTarget(ActionTarget *target)
{
    ActionInterval::startWithTarget(target);
    m_Inner->startWithTarget(m_Target);
}

void ActionEase::stop(void)
{
    m_Inner->stop();
    ActionInterval::stop();
}

void ActionEase::update(float time)
{
    m_Inner->update(time);
}

ActionInterval *ActionEase::getInnerAction()
{
    return m_Inner;
}

ActionEase *ActionEase::clone() const
{
    ofLogError("ofxActionManager") << __FUNCTION__ << ": ActionEase doesn't support clone.";
    return nullptr;
}

ActionEase *ActionEase::reverse() const
{
    ofLogError("ofxActionManager") << __FUNCTION__ << ": ActionEase doesn't support reverse.";
    return nullptr;
}

/* ----------- EaseRateAction ----------- */

EaseRateAction::EaseRateAction()
{

}

EaseRateAction *EaseRateAction::create(ActionInterval *action, float rate)
{
    EaseRateAction *easeRateAction = new(std::nothrow) EaseRateAction();
    if (easeRateAction) {
        if (easeRateAction->initWithAction(action, rate) == false) {
            SAFE_RELEASE(easeRateAction);
        }
    }

    return easeRateAction;
}

bool EaseRateAction::initWithAction(ActionInterval *action, float rate)
{
    if (ActionEase::initWithAction(action)) {
        m_Rate = rate;
        return true;
    }

    return false;
}

EaseRateAction::~EaseRateAction()
{
}

EaseRateAction *EaseRateAction::clone() const
{
    ofLogError("ofxActionManager") << __FUNCTION__ << ": EaseRateAction doesn't support clone.";
    return nullptr;
}

EaseRateAction *EaseRateAction::reverse() const
{
    ofLogError("ofxActionManager") << __FUNCTION__ << ": EaseRateAction doesn't support reverse.";
    return nullptr;
}
