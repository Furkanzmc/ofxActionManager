#include "EaseElastic.h"
#include "ofLog.h"
USING_NS_OFXACTIONS;

bool EaseElastic::initWithAction(ActionInterval *action, float period/* = 0.3f*/)
{
    if (ActionEase::initWithAction(action)) {
        m_Period = period;
        return true;
    }

    return false;
}

EaseElastic *EaseElastic::clone() const
{
    ofLogError("ofxActionManager") << __FUNCTION__ << ": EaseElastic doesn't support clone.";
    return nullptr;
}

EaseElastic *EaseElastic::reverse() const
{
    ofLogError("ofxActionManager") << __FUNCTION__ << ": EaseElastic doesn't support reverse.";
    return nullptr;
}

//
// EaseElasticIn
//

EaseElasticIn *EaseElasticIn::create(ActionInterval *action)
{
    return EaseElasticIn::create(action, 0.3f);
}

EaseElasticIn *EaseElasticIn::create(ActionInterval *action, float period/* = 0.3f*/)
{
    EaseElasticIn *ret = new(std::nothrow) EaseElasticIn();
    if (ret) {
        if (ret->initWithAction(action, period) == false) {
            SAFE_RELEASE(ret);
        }
    }

    return ret;
}

EaseElasticIn *EaseElasticIn::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) EaseElasticIn();
    a->initWithAction(m_Inner->clone(), m_Period);
    return a;
}

void EaseElasticIn::update(float time)
{
    m_Inner->update(tweenfunc::elasticEaseIn(time, m_Period));
}

EaseElastic *EaseElasticIn::reverse() const
{
    return EaseElasticOut::create(m_Inner->reverse(), m_Period);
}

//
// EaseElasticOut
//

EaseElasticOut *EaseElasticOut::create(ActionInterval *action)
{
    return EaseElasticOut::create(action, 0.3f);
}

EaseElasticOut *EaseElasticOut::create(ActionInterval *action, float period/* = 0.3f*/)
{
    EaseElasticOut *ret = new(std::nothrow) EaseElasticOut();
    if (ret) {
        if (ret->initWithAction(action, period) == false) {
            SAFE_RELEASE(ret);
        }
    }

    return ret;
}

EaseElasticOut *EaseElasticOut::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) EaseElasticOut();
    a->initWithAction(m_Inner->clone(), m_Period);
    return a;
}

void EaseElasticOut::update(float time)
{
    m_Inner->update(tweenfunc::elasticEaseOut(time, m_Period));
}

EaseElastic *EaseElasticOut::reverse() const
{
    return EaseElasticIn::create(m_Inner->reverse(), m_Period);
}

//
// EaseElasticInOut
//

EaseElasticInOut *EaseElasticInOut::create(ActionInterval *action)
{
    return EaseElasticInOut::create(action, 0.3f);
}

EaseElasticInOut *EaseElasticInOut::create(ActionInterval *action, float period/* = 0.3f*/)
{
    EaseElasticInOut *ret = new(std::nothrow) EaseElasticInOut();
    if (ret) {
        if (ret->initWithAction(action, period) == false) {
            SAFE_RELEASE(ret);
        }
    }

    return ret;
}

EaseElasticInOut *EaseElasticInOut::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) EaseElasticInOut();
    a->initWithAction(m_Inner->clone(), m_Period);
    return a;
}

void EaseElasticInOut::update(float time)
{
    m_Inner->update(tweenfunc::elasticEaseInOut(time, m_Period));
}

EaseElasticInOut *EaseElasticInOut::reverse() const
{
    return EaseElasticInOut::create(m_Inner->reverse(), m_Period);
}
