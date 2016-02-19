#include "MoveAction.h"
#include "ofLog.h"

// MoveBy

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
            SAFE_RELEASE(ret);
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

const ofVec3f &MoveBy::getDeltaPosition() const
{
    return m_PositionDelta;
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
    if (isStopped() == false && m_Target) {
        m_Target->setPosition(m_StartPosition + m_PositionDelta * t);
    }
}


// MoveTo

MoveTo::MoveTo()
{

}

MoveTo *MoveTo::create(float duration, const ofVec2f &position)
{
    return MoveTo::create(duration, ofVec3f(position.x, position.y, 0));
}

MoveTo *MoveTo::create(float duration, const ofVec3f &position)
{
    MoveTo *ret = new(std::nothrow) MoveTo();

    if (ret) {
        if (ret->initWithDuration(duration, position) == false) {
            SAFE_RELEASE(ret);
        }
    }

    return ret;
}

bool MoveTo::initWithDuration(float duration, const ofVec2f &position)
{
    return initWithDuration(duration, ofVec3f(position.x, position.y, 0));
}

bool MoveTo::initWithDuration(float duration, const ofVec3f &position)
{
    bool ret = false;

    if (ActionInterval::initWithDuration(duration)) {
        m_EndPosition = position;
        ret = true;
    }

    return ret;
}

MoveTo *MoveTo::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) MoveTo();
    a->initWithDuration(m_Duration, m_EndPosition);
    return a;
}

void MoveTo::startWithTarget(ActionTarget *target)
{
    MoveBy::startWithTarget(target);
    m_PositionDelta = m_EndPosition - target->getPosition();
}

const ofVec3f MoveTo::getTargetPosition() const
{
    return m_EndPosition;
}

MoveTo *MoveTo::reverse() const
{
    ofLogWarning("ofxActionManager") << __FUNCTION__ << ": MoveTo doesn't support reverse.";
    return nullptr;
}
