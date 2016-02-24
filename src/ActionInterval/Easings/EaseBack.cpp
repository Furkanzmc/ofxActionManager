#include "EaseBack.h"
USING_NS_OFXACTIONS;

//
// EaseBackIn
//

EaseBackIn *EaseBackIn::create(ActionInterval *action)
{
    EaseBackIn *ret = new(std::nothrow) EaseBackIn();
    if (ret) {
        if (ret->initWithAction(action) == false) {
            SAFE_RELEASE(ret);
        }
    }

    return ret;
}

EaseBackIn *EaseBackIn::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) EaseBackIn();
    a->initWithAction(m_Inner->clone());
    return a;
}

void EaseBackIn::update(float time)
{
    m_Inner->update(tweenfunc::backEaseIn(time));
}

ActionEase *EaseBackIn::reverse() const
{
    return EaseBackOut::create(m_Inner->reverse());
}

//
// EaseBackOut
//

EaseBackOut *EaseBackOut::create(ActionInterval *action)
{
    EaseBackOut *ret = new(std::nothrow) EaseBackOut();
    if (ret) {
        if (ret->initWithAction(action) == false) {
            SAFE_RELEASE(ret);
        }
    }

    return ret;
}

EaseBackOut *EaseBackOut::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) EaseBackOut();
    a->initWithAction(m_Inner->clone());
    return a;
}

void EaseBackOut::update(float time)
{
    m_Inner->update(tweenfunc::backEaseOut(time));
}

ActionEase *EaseBackOut::reverse() const
{
    return EaseBackIn::create(m_Inner->reverse());
}

//
// EaseBackInOut
//

EaseBackInOut *EaseBackInOut::create(ActionInterval *action)
{
    EaseBackInOut *ret = new(std::nothrow) EaseBackInOut();
    if (ret) {
        if (ret->initWithAction(action) == false) {
            SAFE_RELEASE(ret);
        }
    }

    return ret;
}

EaseBackInOut *EaseBackInOut::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) EaseBackInOut();
    a->initWithAction(m_Inner->clone());
    return a;
}

void EaseBackInOut::update(float time)
{
    m_Inner->update(tweenfunc::backEaseInOut(time));
}

EaseBackInOut *EaseBackInOut::reverse() const
{
    return EaseBackInOut::create(m_Inner->reverse());
}
