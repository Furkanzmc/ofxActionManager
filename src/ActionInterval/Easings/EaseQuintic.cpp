#include "EaseQuintic.h"

//
// EaseQuinticActionIn
//

EaseQuinticActionIn *EaseQuinticActionIn::create(ActionInterval *action)
{
    EaseQuinticActionIn *ret = new(std::nothrow) EaseQuinticActionIn();
    if (ret) {
        if (ret->initWithAction(action) == false) {
            SAFE_RELEASE(ret);
        }
    }

    return ret;
}

EaseQuinticActionIn *EaseQuinticActionIn::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) EaseQuinticActionIn();
    a->initWithAction(m_Inner->clone());
    return a;
}

void EaseQuinticActionIn::update(float time)
{
    m_Inner->update(tweenfunc::quintEaseIn(time));
}

EaseQuinticActionIn *EaseQuinticActionIn::reverse() const
{
    return EaseQuinticActionIn::create(m_Inner->reverse());
}

//
// EaseQuinticActionOut
//

EaseQuinticActionOut *EaseQuinticActionOut::create(ActionInterval *action)
{
    EaseQuinticActionOut *ret = new(std::nothrow) EaseQuinticActionOut();
    if (ret) {
        if (ret->initWithAction(action) == false) {
            SAFE_RELEASE(ret);
        }
    }

    return ret;
}

EaseQuinticActionOut *EaseQuinticActionOut::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) EaseQuinticActionOut();
    a->initWithAction(m_Inner->clone());
    return a;
}

void EaseQuinticActionOut::update(float time)
{
    m_Inner->update(tweenfunc::quintEaseOut(time));
}

EaseQuinticActionOut *EaseQuinticActionOut::reverse() const
{
    return EaseQuinticActionOut::create(m_Inner->reverse());
}

//
// EaseQuinticActionInOut
//

EaseQuinticActionInOut *EaseQuinticActionInOut::create(ActionInterval *action)
{
    EaseQuinticActionInOut *ret = new(std::nothrow) EaseQuinticActionInOut();
    if (ret) {
        if (ret->initWithAction(action) == false) {
            SAFE_RELEASE(ret);
        }
    }

    return ret;
}

EaseQuinticActionInOut *EaseQuinticActionInOut::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) EaseQuinticActionInOut();
    a->initWithAction(m_Inner->clone());

    return a;
}

void EaseQuinticActionInOut::update(float time)
{
    m_Inner->update(tweenfunc::quintEaseInOut(time));
}

EaseQuinticActionInOut *EaseQuinticActionInOut::reverse() const
{
    return EaseQuinticActionInOut::create(m_Inner->reverse());
}
