#include "RotateAction.h"
#include "ofLog.h"

//
// RotateTo
//

RotateTo *RotateTo::create(float duration, float dstAngle)
{
    RotateTo *rotateTo = new(std::nothrow) RotateTo();
    rotateTo->initWithDuration(duration, dstAngle, dstAngle);

    return rotateTo;
}

RotateTo *RotateTo::create(float duration, float dstAngleX, float dstAngleY)
{
    RotateTo *rotateTo = new(std::nothrow) RotateTo();
    rotateTo->initWithDuration(duration, dstAngleX, dstAngleY);

    return rotateTo;
}

RotateTo *RotateTo::create(float duration, const ofVec3f &dstAngle3D)
{
    RotateTo *rotateTo = new(std::nothrow) RotateTo();
    rotateTo->initWithDuration(duration, dstAngle3D);

    return rotateTo;
}

RotateTo::RotateTo()
{
}

bool RotateTo::initWithDuration(float duration, float dstAngleX, float dstAngleY)
{
    if (ActionInterval::initWithDuration(duration)) {
        m_DstAngle.x = dstAngleX;
        m_DstAngle.y = dstAngleY;

        return true;
    }

    return false;
}

bool RotateTo::initWithDuration(float duration, const ofVec3f &dstAngle3D)
{
    if (ActionInterval::initWithDuration(duration)) {
        m_DstAngle = dstAngle3D;

        return true;
    }

    return false;
}

RotateTo *RotateTo::clone(void) const
{
    // no copy constructor
    auto a = new(std::nothrow) RotateTo();
    a->initWithDuration(m_Duration, m_DstAngle);
    return a;
}

void RotateTo::calculateAngles(float &startAngle, float &diffAngle, float dstAngle)
{
    if (startAngle > 0) {
        startAngle = fmodf(startAngle, 360.0f);
    }
    else {
        startAngle = fmodf(startAngle, -360.0f);
    }

    diffAngle = dstAngle - startAngle;
    if (diffAngle > 180) {
        diffAngle -= 360;
    }
    if (diffAngle < -180) {
        diffAngle += 360;
    }
}

const ofVec3f &RotateTo::getDestinationAngle() const
{
    return m_DstAngle;
}

void RotateTo::startWithTarget(ActionTarget *target)
{
    ActionInterval::startWithTarget(target);

    m_StartAngle = m_Target->getRotation();

    calculateAngles(m_StartAngle.x, m_DiffAngle.x, m_DstAngle.x);
    calculateAngles(m_StartAngle.y, m_DiffAngle.y, m_DstAngle.y);
    calculateAngles(m_StartAngle.z, m_DiffAngle.z, m_DstAngle.z);
}

void RotateTo::update(float time)
{
    if (m_Target) {
        m_Target->setRotation(ofVec3f(
                                  m_StartAngle.x + m_DiffAngle.x * time,
                                  m_StartAngle.y + m_DiffAngle.y * time,
                                  m_StartAngle.z + m_DiffAngle.z * time
                              ));
    }
}

RotateTo *RotateTo::reverse() const
{
    ofLogError("ofxActionManager") << __FUNCTION__ << ": RotateTo doesn't support the 'reverse' method";
    return nullptr;
}

//
// RotateBy
//

RotateBy *RotateBy::create(float duration, float deltaAngle)
{
    RotateBy *rotateBy = new(std::nothrow) RotateBy();
    rotateBy->initWithDuration(duration, deltaAngle);

    return rotateBy;
}

RotateBy *RotateBy::create(float duration, const ofVec3f &deltaAngle3D)
{
    RotateBy *rotateBy = new(std::nothrow) RotateBy();
    rotateBy->initWithDuration(duration, deltaAngle3D);

    return rotateBy;
}

RotateBy::RotateBy()
{
}

bool RotateBy::initWithDuration(float duration, float deltaAngle)
{
    if (ActionInterval::initWithDuration(duration)) {
        m_DeltaAngle.x = m_DeltaAngle.y = deltaAngle;
        return true;
    }

    return false;
}

bool RotateBy::initWithDuration(float duration, const ofVec3f &deltaAngle3D)
{
    if (ActionInterval::initWithDuration(duration)) {
        m_DeltaAngle = deltaAngle3D;
        return true;
    }

    return false;
}

const ofVec3f &RotateBy::getDeltaAngle() const
{
    return m_DeltaAngle;
}


RotateBy *RotateBy::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) RotateBy();
    a->initWithDuration(m_Duration, m_DeltaAngle);
    return a;
}

void RotateBy::startWithTarget(ActionTarget *target)
{
    ActionInterval::startWithTarget(target);
    m_StartAngle = target->getRotation();
}

void RotateBy::update(float time)
{
    // FIXME: shall I add % 360
    if (m_Target) {
        ofVec3f v;
        v.x = m_StartAngle.x + m_DeltaAngle.x * time;
        v.y = m_StartAngle.y + m_DeltaAngle.y * time;
        v.z = m_StartAngle.z + m_DeltaAngle.z * time;
        m_Target->setRotation(v);
    }
}

RotateBy *RotateBy::reverse() const
{
    ofVec3f v;
    v.x = - m_DeltaAngle.x;
    v.y = - m_DeltaAngle.y;
    v.z = - m_DeltaAngle.z;
    return RotateBy::create(m_Duration, v);
}
