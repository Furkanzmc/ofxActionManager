#include "ScaleAction.h"
#include "ofLog.h"

//
// ScaleTo
//
ScaleTo *ScaleTo::create(float duration, const ofVec3f &s)
{
    ScaleTo *scaleTo = new(std::nothrow) ScaleTo();
    scaleTo->initWithDuration(duration, s.x, s.y, s.z);

    return scaleTo;
}

ScaleTo *ScaleTo::create(float duration, float s)
{
    ScaleTo *scaleTo = new(std::nothrow) ScaleTo();
    scaleTo->initWithDuration(duration, s);

    return scaleTo;
}

ScaleTo *ScaleTo::create(float duration, float sx, float sy)
{
    ScaleTo *scaleTo = new(std::nothrow) ScaleTo();
    scaleTo->initWithDuration(duration, sx, sy);

    return scaleTo;
}

ScaleTo *ScaleTo::create(float duration, float sx, float sy, float sz)
{
    ScaleTo *scaleTo = new(std::nothrow) ScaleTo();
    scaleTo->initWithDuration(duration, sx, sy, sz);

    return scaleTo;
}

bool ScaleTo::initWithDuration(float duration, float s)
{
    if (ActionInterval::initWithDuration(duration)) {
        m_EndScaleX = s;
        m_EndScaleY = s;
        m_EndScaleZ = s;

        return true;
    }

    return false;
}

bool ScaleTo::initWithDuration(float duration, float sx, float sy)
{
    if (ActionInterval::initWithDuration(duration)) {
        m_EndScaleX = sx;
        m_EndScaleY = sy;
        m_EndScaleZ = 1.f;

        return true;
    }

    return false;
}

bool ScaleTo::initWithDuration(float duration, float sx, float sy, float sz)
{
    if (ActionInterval::initWithDuration(duration)) {
        m_EndScaleX = sx;
        m_EndScaleY = sy;
        m_EndScaleZ = sz;

        return true;
    }

    return false;
}

ofVec3f ScaleTo::getEndScale() const
{
    return ofVec3f(m_EndScaleX, m_EndScaleY, m_EndScaleZ);
}

ScaleTo *ScaleTo::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) ScaleTo();
    a->initWithDuration(m_Duration, m_EndScaleX, m_EndScaleY, m_EndScaleZ);
    return a;
}

ScaleTo *ScaleTo::reverse() const
{
    ofLogError("ofxActionManager") << __FUNCTION__ << ": reverse() not supported in ScaleTo";
    return nullptr;
}


void ScaleTo::startWithTarget(ActionTarget *target)
{
    ActionInterval::startWithTarget(target);
    m_StartScaleX = target->getScale().x;
    m_StartScaleY = target->getScale().y;
    m_StartScaleZ = target->getScale().z;
    m_DeltaX = m_EndScaleX - m_StartScaleX;
    m_DeltaY = m_EndScaleY - m_StartScaleY;
    m_DeltaZ = m_EndScaleZ - m_StartScaleZ;
}

void ScaleTo::update(float time)
{
    if (m_Target) {
        m_Target->setScale(ofVec3f(m_StartScaleX + m_DeltaX * time, m_StartScaleY + m_DeltaY * time, m_StartScaleZ + m_DeltaZ * time));
    }
}

//
// ScaleBy
//

ScaleBy *ScaleBy::create(float duration, float s)
{
    ScaleBy *scaleBy = new(std::nothrow) ScaleBy();
    scaleBy->initWithDuration(duration, s);

    return scaleBy;
}

ScaleBy *ScaleBy::create(float duration, const ofVec3f &scale)
{
    ScaleBy *scaleBy = new(std::nothrow) ScaleBy();
    scaleBy->initWithDuration(duration, scale.x, scale.y, scale.z);

    return scaleBy;
}

ScaleBy *ScaleBy::create(float duration, float sx, float sy)
{
    ScaleBy *scaleBy = new(std::nothrow) ScaleBy();
    scaleBy->initWithDuration(duration, sx, sy, 1.f);

    return scaleBy;
}

ScaleBy *ScaleBy::create(float duration, float sx, float sy, float sz)
{
    ScaleBy *scaleBy = new(std::nothrow) ScaleBy();
    scaleBy->initWithDuration(duration, sx, sy, sz);

    return scaleBy;
}

ScaleBy *ScaleBy::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) ScaleBy();
    a->initWithDuration(m_Duration, m_EndScaleX, m_EndScaleY, m_EndScaleZ);
    return a;
}

void ScaleBy::startWithTarget(ActionTarget *target)
{
    ScaleTo::startWithTarget(target);
    m_DeltaX = m_StartScaleX * m_EndScaleX - m_StartScaleX;
    m_DeltaY = m_StartScaleY * m_EndScaleY - m_StartScaleY;
    m_DeltaZ = m_StartScaleZ * m_EndScaleZ - m_StartScaleZ;
}

ScaleBy *ScaleBy::reverse() const
{
    return ScaleBy::create(m_Duration, 1 / m_EndScaleX, 1 / m_EndScaleY, 1 / m_EndScaleZ);
}
