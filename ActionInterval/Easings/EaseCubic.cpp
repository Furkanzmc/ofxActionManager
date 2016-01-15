#include "EaseCubic.h"

//
// EaseCubicActionIn
//

EaseCubicActionIn *EaseCubicActionIn::create(ActionInterval *action)
{
    EaseCubicActionIn *ret = new(std::nothrow) EaseCubicActionIn();
    if (ret) {
        if (ret->initWithAction(action) == false) {
            SAFE_RELEASE(ret);
        }
    }

    return ret;
}

EaseCubicActionIn *EaseCubicActionIn::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) EaseCubicActionIn();
    a->initWithAction(m_Inner->clone());
    return a;
}

void EaseCubicActionIn::update(float time)
{
    m_Inner->update(tweenfunc::cubicEaseIn(time));
}

EaseCubicActionIn *EaseCubicActionIn::reverse() const
{
    return EaseCubicActionIn::create(m_Inner->reverse());
}

//
// EaseCubicActionOut
//

EaseCubicActionOut *EaseCubicActionOut::create(ActionInterval *action)
{
    EaseCubicActionOut *ret = new(std::nothrow) EaseCubicActionOut();
    if (ret) {
        if (ret->initWithAction(action) == false) {
            SAFE_RELEASE(ret);
        }
    }

    return ret;
}

EaseCubicActionOut *EaseCubicActionOut::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) EaseCubicActionOut();
    a->initWithAction(m_Inner->clone());
    return a;
}

void EaseCubicActionOut::update(float time)
{
    m_Inner->update(tweenfunc::cubicEaseOut(time));
}

EaseCubicActionOut *EaseCubicActionOut::reverse() const
{
    return EaseCubicActionOut::create(m_Inner->reverse());
}

//
// EaseCubicActionInOut
//

EaseCubicActionInOut *EaseCubicActionInOut::create(ActionInterval *action)
{
    EaseCubicActionInOut *ret = new(std::nothrow) EaseCubicActionInOut();
    if (ret) {
        if (ret->initWithAction(action) == false) {
            SAFE_RELEASE(ret);
        }
    }

    return ret;
}

EaseCubicActionInOut *EaseCubicActionInOut::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) EaseCubicActionInOut();
    a->initWithAction(m_Inner->clone());
    return a;
}

void EaseCubicActionInOut::update(float time)
{
    m_Inner->update(tweenfunc::cubicEaseInOut(time));
}

EaseCubicActionInOut *EaseCubicActionInOut::reverse() const
{
    return EaseCubicActionInOut::create(m_Inner->reverse());
}
