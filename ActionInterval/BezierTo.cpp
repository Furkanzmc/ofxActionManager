#include "BezierTo.h"
#include "ofLog.h"

BezierTo::BezierTo()
{

}

BezierTo *BezierTo::create(float t, const BezierConfig &c)
{
    BezierTo *bezierTo = new(std::nothrow) BezierTo();
    bezierTo->initWithDuration(t, c);

    return bezierTo;
}

bool BezierTo::initWithDuration(float t, const BezierConfig &c)
{
    if (ActionInterval::initWithDuration(t)) {
        m_ToConfig = c;
        return true;
    }

    return false;
}

BezierTo *BezierTo::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) BezierTo();
    a->initWithDuration(m_Duration, m_ToConfig);
    return a;
}

void BezierTo::startWithTarget(ActionTarget *target)
{
    BezierBy::startWithTarget(target);
    m_Config.controlPoint_1 = m_ToConfig.controlPoint_1 - m_StartPosition;
    m_Config.controlPoint_2 = m_ToConfig.controlPoint_2 - m_StartPosition;
    m_Config.endPosition = m_ToConfig.endPosition - m_StartPosition;
}

BezierTo *BezierTo::reverse() const
{
    ofLogWarning("ofxActionManager") << __FUNCTION__ << ": BezierTo doesn't support the 'reverse' method";
    return nullptr;
}
