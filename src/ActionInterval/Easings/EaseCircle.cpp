#include "EaseCircle.h"

//
// EaseCircleActionIn
//

EaseCircleActionIn *EaseCircleActionIn::create(ActionInterval *action)
{
    EaseCircleActionIn *ret = new(std::nothrow) EaseCircleActionIn();
    if (ret) {
        if (ret->initWithAction(action) == false) {
            SAFE_RELEASE(ret);
        }
    }

    return ret;
}

EaseCircleActionIn *EaseCircleActionIn::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) EaseCircleActionIn();
    a->initWithAction(m_Inner->clone());
    return a;
}

void EaseCircleActionIn::update(float time)
{
    m_Inner->update(tweenfunc::circEaseIn(time));
}

EaseCircleActionIn *EaseCircleActionIn::reverse() const
{
    return EaseCircleActionIn::create(m_Inner->reverse());
}

//
// EaseCircleActionOut
//

EaseCircleActionOut *EaseCircleActionOut::create(ActionInterval *action)
{
    EaseCircleActionOut *ret = new(std::nothrow) EaseCircleActionOut();
    if (ret) {
        if (ret->initWithAction(action) == false) {
            SAFE_RELEASE(ret);
        }
    }

    return ret;
}

EaseCircleActionOut *EaseCircleActionOut::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) EaseCircleActionOut();
    a->initWithAction(m_Inner->clone());
    return a;
}

void EaseCircleActionOut::update(float time)
{
    m_Inner->update(tweenfunc::circEaseOut(time));
}

EaseCircleActionOut *EaseCircleActionOut::reverse() const
{
    return EaseCircleActionOut::create(m_Inner->reverse());
}

//
// EaseCircleActionInOut
//

EaseCircleActionInOut *EaseCircleActionInOut::create(ActionInterval *action)
{
    EaseCircleActionInOut *ret = new(std::nothrow) EaseCircleActionInOut();
    if (ret) {
        if (ret->initWithAction(action) == false) {
            SAFE_RELEASE(ret);
        }
    }

    return ret;
}

EaseCircleActionInOut *EaseCircleActionInOut::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) EaseCircleActionInOut();
    a->initWithAction(m_Inner->clone());
    return a;
}

void EaseCircleActionInOut::update(float time)
{
    m_Inner->update(tweenfunc::circEaseInOut(time));
}

EaseCircleActionInOut *EaseCircleActionInOut::reverse() const
{
    return EaseCircleActionInOut::create(m_Inner->reverse());
}
