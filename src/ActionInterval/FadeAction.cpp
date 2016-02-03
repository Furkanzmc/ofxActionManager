#include "FadeAction.h"
#include "ofLog.h"

//
// FadeIn
//

FadeIn *FadeIn::create(float d)
{
    FadeIn *action = new(std::nothrow) FadeIn();

    action->initWithDuration(d, 255.0f);

    return action;
}

FadeIn *FadeIn::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) FadeIn();
    a->initWithDuration(m_Duration, 255.0f);
    return a;
}

void FadeIn::setReverseAction(FadeTo *ac)
{
    _reverseAction = ac;
}


FadeTo *FadeIn::reverse() const
{
    auto action = FadeOut::create(m_Duration);
    action->setReverseAction(const_cast<FadeIn *>(this));
    return action;

}

void FadeIn::startWithTarget(ActionTarget *target)
{
    ActionInterval::startWithTarget(target);

    if (nullptr != _reverseAction) {
        this->_toOpacity = this->_reverseAction->_fromOpacity;
    }
    else {
        _toOpacity = 255.0f;
    }

    if (target) {
        _fromOpacity = target->getOpacity();
    }
}


//
// FadeOut
//

FadeOut *FadeOut::create(float d)
{
    FadeOut *action = new(std::nothrow) FadeOut();

    action->initWithDuration(d, 0.0f);

    return action;
}

FadeOut *FadeOut::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) FadeOut();
    a->initWithDuration(m_Duration, 0.0f);
    return a;
}

void FadeOut::startWithTarget(ActionTarget *target)
{
    ActionInterval::startWithTarget(target);

    if (nullptr != _reverseAction) {
        _toOpacity = _reverseAction->_fromOpacity;
    }
    else {
        _toOpacity = 0.0f;
    }

    if (target) {
        _fromOpacity = target->getOpacity();
    }
}

void FadeOut::setReverseAction(FadeTo *ac)
{
    _reverseAction = ac;
}


FadeTo *FadeOut::reverse() const
{
    auto action = FadeIn::create(m_Duration);
    action->setReverseAction(const_cast<FadeOut *>(this));
    return action;
}

//
// FadeTo
//

FadeTo *FadeTo::create(float duration, GLubyte opacity)
{
    FadeTo *fadeTo = new(std::nothrow) FadeTo();
    fadeTo->initWithDuration(duration, opacity);

    return fadeTo;
}

bool FadeTo::initWithDuration(float duration, GLubyte opacity)
{
    if (ActionInterval::initWithDuration(duration)) {
        _toOpacity = opacity;
        return true;
    }

    return false;
}

FadeTo *FadeTo::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) FadeTo();
    a->initWithDuration(m_Duration, _toOpacity);
    return a;
}

FadeTo *FadeTo::reverse() const
{
    ofLogWarning("ofxActionManager") << __FUNCTION__ << " reverse() not supported in FadeTo";
    return nullptr;
}

void FadeTo::startWithTarget(ActionTarget *target)
{
    ActionInterval::startWithTarget(target);

    if (target) {
        _fromOpacity = target->getOpacity();
    }
}

void FadeTo::update(float time)
{
    if (m_Target) {
        m_Target->setOpacity((GLubyte)(_fromOpacity + (_toOpacity - _fromOpacity) * time));
    }
}
