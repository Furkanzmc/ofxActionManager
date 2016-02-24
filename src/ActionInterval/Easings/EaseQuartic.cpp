#include "EaseQuartic.h"
USING_NS_OFXACTIONS;

//
// EaseQuarticActionIn
//

EaseQuarticActionIn *EaseQuarticActionIn::create(ActionInterval *action)
{
    EaseQuarticActionIn *ret = new(std::nothrow) EaseQuarticActionIn();
    if (ret) {
        if (ret->initWithAction(action) == false) {
            SAFE_RELEASE(ret);
        }
    }

    return ret;
}

EaseQuarticActionIn *EaseQuarticActionIn::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) EaseQuarticActionIn();
    a->initWithAction(m_Inner->clone());
    return a;
}

void EaseQuarticActionIn::update(float time)
{
    m_Inner->update(tweenfunc::quartEaseIn(time));
}

EaseQuarticActionIn *EaseQuarticActionIn::reverse() const
{
    return EaseQuarticActionIn::create(m_Inner->reverse());
}

//
// EaseQuarticActionOut
//

EaseQuarticActionOut *EaseQuarticActionOut::create(ActionInterval *action)
{
    EaseQuarticActionOut *ret = new(std::nothrow) EaseQuarticActionOut();
    if (ret) {
        if (ret->initWithAction(action) == false) {
            SAFE_RELEASE(ret);
        }
    }

    return ret;
}

EaseQuarticActionOut *EaseQuarticActionOut::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) EaseQuarticActionOut();
    a->initWithAction(m_Inner->clone());

    return a;
}

void EaseQuarticActionOut::update(float time)
{
    m_Inner->update(tweenfunc::quartEaseOut(time));
}

EaseQuarticActionOut *EaseQuarticActionOut::reverse() const
{
    return EaseQuarticActionOut::create(m_Inner->reverse());
}

//
// EaseQuarticActionInOut
//

EaseQuarticActionInOut *EaseQuarticActionInOut::create(ActionInterval *action)
{
    EaseQuarticActionInOut *ret = new(std::nothrow) EaseQuarticActionInOut();
    if (ret) {
        if (ret->initWithAction(action) == false) {
            SAFE_RELEASE(ret);
        }
    }

    return ret;
}

EaseQuarticActionInOut *EaseQuarticActionInOut::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) EaseQuarticActionInOut();
    a->initWithAction(m_Inner->clone());

    return a;
}

void EaseQuarticActionInOut::update(float time)
{
    m_Inner->update(tweenfunc::quartEaseInOut(time));
}

EaseQuarticActionInOut *EaseQuarticActionInOut::reverse() const
{
    return EaseQuarticActionInOut::create(m_Inner->reverse());
}
