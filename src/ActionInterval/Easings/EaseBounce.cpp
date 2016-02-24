#include "EaseBounce.h"
#include "ofLog.h"

//
// EaseBounce
//

EaseBounce *EaseBounce::clone() const
{
    ofLogError("ofxActionManager") << __FUNCTION__ << ": EaseBounce doesn support clone.";
    return nullptr;
}

EaseBounce *EaseBounce::reverse() const
{
    ofLogError("ofxActionManager") << __FUNCTION__ << ": EaseBounce doesn support reverse.";
    return nullptr;
}

//
// EaseBounceIn
//

EaseBounceIn *EaseBounceIn::create(ActionInterval *action)
{
    EaseBounceIn *ret = new(std::nothrow) EaseBounceIn();
    if (ret) {
        if (ret->initWithAction(action) == false) {
            SAFE_RELEASE(ret);
        }
    }

    return ret;
}

EaseBounceIn *EaseBounceIn::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) EaseBounceIn();
    a->initWithAction(m_Inner->clone());
    return a;
}

void EaseBounceIn::update(float time)
{
    m_Inner->update(tweenfunc::bounceEaseIn(time));
}

EaseBounce *EaseBounceIn::reverse() const
{
    return EaseBounceOut::create(m_Inner->reverse());
}

//
// EaseBounceOut
//

EaseBounceOut *EaseBounceOut::create(ActionInterval *action)
{
    EaseBounceOut *ret = new(std::nothrow) EaseBounceOut();
    if (ret) {
        if (ret->initWithAction(action) == false) {
            SAFE_RELEASE(ret);
        }
    }

    return ret;
}

EaseBounceOut *EaseBounceOut::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) EaseBounceOut();
    a->initWithAction(m_Inner->clone());
    return a;
}

void EaseBounceOut::update(float time)
{
    m_Inner->update(tweenfunc::bounceEaseOut(time));
}

EaseBounce *EaseBounceOut::reverse() const
{
    return EaseBounceIn::create(m_Inner->reverse());
}

//
// EaseBounceInOut
//

EaseBounceInOut *EaseBounceInOut::create(ActionInterval *action)
{
    EaseBounceInOut *ret = new(std::nothrow) EaseBounceInOut();
    if (ret) {
        if (ret->initWithAction(action) == false) {
            SAFE_RELEASE(ret);
        }
    }

    return ret;
}

EaseBounceInOut *EaseBounceInOut::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) EaseBounceInOut();
    a->initWithAction(m_Inner->clone());
    return a;
}

void EaseBounceInOut::update(float time)
{
    m_Inner->update(tweenfunc::bounceEaseInOut(time));
}

EaseBounceInOut *EaseBounceInOut::reverse() const
{
    return EaseBounceInOut::create(m_Inner->reverse());
}
