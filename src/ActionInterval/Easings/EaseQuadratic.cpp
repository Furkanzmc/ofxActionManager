#include "EaseQuadratic.h"
USING_NS_OFXACTIONS;

//
// EaseQuadraticActionIn
//

EaseQuadraticActionIn *EaseQuadraticActionIn::create(ActionInterval *action)
{
    EaseQuadraticActionIn *ret = new(std::nothrow) EaseQuadraticActionIn();
    if (ret) {
        if (ret->initWithAction(action) == false) {
            SAFE_RELEASE(ret);
        }
    }

    return ret;
}

EaseQuadraticActionIn *EaseQuadraticActionIn::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) EaseQuadraticActionIn();
    a->initWithAction(m_Inner->clone());
    return a;
}

void EaseQuadraticActionIn::update(float time)
{
    m_Inner->update(tweenfunc::quadraticIn(time));
}

EaseQuadraticActionIn *EaseQuadraticActionIn::reverse() const
{
    return EaseQuadraticActionIn::create(m_Inner->reverse());
}

//
// EaseQuadraticActionOut
//

EaseQuadraticActionOut *EaseQuadraticActionOut::create(ActionInterval *action)
{
    EaseQuadraticActionOut *ret = new(std::nothrow) EaseQuadraticActionOut();
    if (ret) {
        if (ret->initWithAction(action) == false) {
            SAFE_RELEASE(ret);
        }
    }

    return ret;
}

EaseQuadraticActionOut *EaseQuadraticActionOut::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) EaseQuadraticActionOut();
    a->initWithAction(m_Inner->clone());
    return a;
}

void EaseQuadraticActionOut::update(float time)
{
    m_Inner->update(tweenfunc::quadraticOut(time));
}

EaseQuadraticActionOut *EaseQuadraticActionOut::reverse() const
{
    return EaseQuadraticActionOut::create(m_Inner->reverse());
}

//
// EaseQuadraticActionInOut
//

EaseQuadraticActionInOut *EaseQuadraticActionInOut::create(ActionInterval *action)
{
    EaseQuadraticActionInOut *ret = new(std::nothrow) EaseQuadraticActionInOut();
    if (ret) {
        if (ret->initWithAction(action) == false) {
            SAFE_RELEASE(ret);
        }
    }

    return ret;
}

EaseQuadraticActionInOut *EaseQuadraticActionInOut::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) EaseQuadraticActionInOut();
    a->initWithAction(m_Inner->clone());
    return a;
}

void EaseQuadraticActionInOut::update(float time)
{
    m_Inner->update(tweenfunc::quadraticInOut(time));
}

EaseQuadraticActionInOut *EaseQuadraticActionInOut::reverse() const
{
    return EaseQuadraticActionInOut::create(m_Inner->reverse());
}
