#include "EaseExponential.h"

EaseExponentialIn::EaseExponentialIn()
{

}

EaseExponentialIn *EaseExponentialIn::create(ActionInterval *action)
{
    EaseExponentialIn *ret = new(std::nothrow) EaseExponentialIn();
    if (ret) {
        if (ret->initWithAction(action) == false) {
            SAFE_RELEASE(ret);
        }
    }

    return ret;
}

EaseExponentialIn *EaseExponentialIn::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) EaseExponentialIn();
    a->initWithAction(m_Inner->clone());
    return a;
}

void EaseExponentialIn::update(float time)
{
    m_Inner->update(tweenfunc::expoEaseIn(time));
}

ActionEase *EaseExponentialIn::reverse() const
{
    return EaseExponentialOut::create(m_Inner->reverse());
}

// EaseExponentialInOut

EaseExponentialInOut::EaseExponentialInOut()
{

}

EaseExponentialInOut *EaseExponentialInOut::create(ActionInterval *action)
{
    EaseExponentialInOut *ret = new(std::nothrow) EaseExponentialInOut();
    if (ret) {
        if (ret->initWithAction(action) == false) {
            SAFE_RELEASE(ret);
        }
    }

    return ret;
}

EaseExponentialInOut *EaseExponentialInOut::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) EaseExponentialInOut();
    a->initWithAction(m_Inner->clone());
    return a;
}

void EaseExponentialInOut::update(float time)
{
    m_Inner->update(tweenfunc::expoEaseInOut(time));
}

EaseExponentialInOut *EaseExponentialInOut::reverse() const
{
    return EaseExponentialInOut::create(m_Inner->reverse());
}

//EaseExponentialOut

EaseExponentialOut::EaseExponentialOut()
{

}

EaseExponentialOut *EaseExponentialOut::create(ActionInterval *action)
{
    EaseExponentialOut *ret = new(std::nothrow) EaseExponentialOut();
    if (ret) {
        if (ret->initWithAction(action) == false) {
            SAFE_RELEASE(ret);
        }
    }

    return ret;
}

EaseExponentialOut *EaseExponentialOut::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) EaseExponentialOut();
    a->initWithAction(m_Inner->clone());
    return a;
}

void EaseExponentialOut::update(float time)
{
    m_Inner->update(tweenfunc::expoEaseOut(time));
}

ActionEase *EaseExponentialOut::reverse() const
{
    return EaseExponentialIn::create(m_Inner->reverse());
}
