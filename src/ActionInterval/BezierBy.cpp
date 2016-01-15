#include "BezierBy.h"

BezierBy::BezierBy()
{

}

BezierBy *BezierBy::create(float t, const BezierConfig &c)
{
    BezierBy *bezierBy = new(std::nothrow) BezierBy();
    bezierBy->initWithDuration(t, c);

    return bezierBy;
}

bool BezierBy::initWithDuration(float t, const BezierConfig &c)
{
    if (ActionInterval::initWithDuration(t)) {
        m_Config = c;
        return true;
    }

    return false;
}

void BezierBy::startWithTarget(ActionTarget *target)
{
    ActionInterval::startWithTarget(target);
    m_PreviousPosition = m_StartPosition = target->getPositon();
}

BezierBy *BezierBy::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) BezierBy();
    a->initWithDuration(m_Duration, m_Config);
    return a;
}

void BezierBy::update(float time)
{
    if (isStopped() == false) {
        float xa = 0;
        float xb = m_Config.controlPoint_1.x;
        float xc = m_Config.controlPoint_2.x;
        float xd = m_Config.endPosition.x;

        float ya = 0;
        float yb = m_Config.controlPoint_1.y;
        float yc = m_Config.controlPoint_2.y;
        float yd = m_Config.endPosition.y;

        float x = bezierat(xa, xb, xc, xd, time);
        float y = bezierat(ya, yb, yc, yd, time);

        const ofVec2f currentPos = m_Target->getPositon();
        const ofVec2f diff = currentPos - m_PreviousPosition;
        m_StartPosition = m_StartPosition + diff;

        const ofVec2f newPos = m_StartPosition + ofVec2f(x, y);
        m_Target->setPositon(newPos);

        m_PreviousPosition = newPos;
    }
}

BezierBy *BezierBy::reverse() const
{
    BezierConfig r;

    r.endPosition = -m_Config.endPosition;
    r.controlPoint_1 = m_Config.controlPoint_2 + (-m_Config.endPosition);
    r.controlPoint_2 = m_Config.controlPoint_1 + (-m_Config.endPosition);

    BezierBy *action = BezierBy::create(m_Duration, r);
    return action;
}

// Bezier cubic formula:
//    ((1 - t) + t)3 = 1
// Expands to ...
//   (1 - t)3 + 3t(1-t)2 + 3t2(1 - t) + t3 = 1
float BezierBy::bezierat(float a, float b, float c, float d, float t)
{
    return (powf(1 - t, 3) * a +
            3 * t * (powf(1 - t, 2)) * b +
            3 * powf(t, 2) * (1 - t) * c +
            powf(t, 3) * d);
}
