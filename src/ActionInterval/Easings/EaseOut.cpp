#include "EaseOut.h"
USING_NS_OFXACTIONS;

EaseOut::EaseOut()
{

}

EaseOut *EaseOut::create(ActionInterval *action, float rate)
{
    EaseOut *easeOut = new(std::nothrow) EaseOut();
    if (easeOut) {
        if (easeOut->initWithAction(action, rate) == false) {
            SAFE_RELEASE(easeOut);
        }
    }

    return easeOut;
}

EaseOut *EaseOut::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) EaseOut();
    a->initWithAction(m_Inner->clone(), m_Rate);
    return a;
}

void EaseOut::update(float time)
{
    m_Inner->update(tweenfunc::easeOut(time, m_Rate));
}

EaseOut *EaseOut::reverse() const
{
    return EaseOut::create(m_Inner->reverse(), 1 / m_Rate);
}
