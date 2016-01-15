#include "MoveBy.h"

MoveBy::MoveBy()
{

}

MoveBy *MoveBy::create(float duration, const ofVec2f &deltaPosition)
{
    return MoveBy::create(duration, ofVec3f(deltaPosition.x, deltaPosition.y, 0));
}

MoveBy *MoveBy::create(float duration, const ofVec3f &deltaPosition)
{
    MoveBy *ret = new(std::nothrow) MoveBy();

    if (ret) {
        if (ret->initWithDuration(duration, deltaPosition) == false) {
            delete ret;
            ret = nullptr;
        }
    }

    return ret;
}

bool MoveBy::initWithDuration(float duration, const ofVec2f &deltaPosition)
{
    return MoveBy::initWithDuration(duration, ofVec3f(deltaPosition.x, deltaPosition.y, 0));
}

bool MoveBy::initWithDuration(float duration, const ofVec3f &deltaPosition)
{
    bool ret = false;

    if (ActionInterval::initWithDuration(duration)) {
        m_PositionDelta = deltaPosition;
        ret = true;
    }

    return ret;
}

MoveBy *MoveBy::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) MoveBy();
    a->initWithDuration(m_Duration, m_PositionDelta);
    return a;
}

void MoveBy::startWithTarget(ActionTarget *target)
{
    ActionInterval::startWithTarget(target);
    m_PreviousPosition = m_StartPosition = target->getPosition();
}

MoveBy *MoveBy::reverse() const
{
    return MoveBy::create(m_Duration, -m_PositionDelta);
}

void MoveBy::update(float t)
{
    if (isStopped() == false) {
        m_Target->setPosition(m_StartPosition + m_PositionDelta * t);
    }
}
