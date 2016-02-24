#include "ActionVec3.h"
USING_NS_OFXACTIONS;

ActionVec3::ActionVec3()
    : m_Value(nullptr)
{
}

ActionVec3 *ActionVec3::create(float duration, ofVec3f from, ofVec3f to, ActionVec3Callback callback)
{
    auto ref = new(std::nothrow) ActionVec3();
    if (ref && ref->initWithDuration(duration, from, to, callback)) {
        return ref;
    }
    SAFE_RELEASE(ref);
    return ref;
}

bool ActionVec3::initWithDuration(float duration, ofVec3f from, ofVec3f to, ActionVec3Callback callback)
{
    if (ActionInterval::initWithDuration(duration)) {
        m_From = from;
        m_To = to;
        m_Callback = callback;
        return true;
    }
    return false;
}

ActionVec3 *ActionVec3::create(float duration, ofVec3f from, ofVec3f to, ofVec3f *value)
{
    auto ref = new(std::nothrow) ActionVec3();
    if (ref && ref->initWithDuration(duration, from, to, value)) {
        return ref;
    }
    SAFE_RELEASE(ref);
    return ref;
}

bool ActionVec3::initWithDuration(float duration, ofVec3f from, ofVec3f to, ofVec3f *value)
{
    if (ActionInterval::initWithDuration(duration)) {
        m_From = from;
        m_To = to;
        m_Value = value;
        return true;
    }
    return false;
}


ActionVec3 *ActionVec3::clone() const
{
    auto a = new(std::nothrow) ActionVec3();
    a->initWithDuration(m_Duration, m_From, m_To, m_Callback);
    return a;
}

void ActionVec3::startWithTarget(ActionTarget *target)
{
    ActionInterval::startWithTarget(target);
    m_Delta = m_To - m_From;
}

void ActionVec3::update(float delta)
{
    const ofVec3f value(m_To.x - m_Delta.x * (1 - delta),
                        m_To.y - m_Delta.y * (1 - delta),
                        m_To.z - m_Delta.z * (1 - delta));

    if (m_Value != nullptr) {
        *m_Value = value;
    }
    else if (m_Callback) {
        m_Callback(value);
    }
}

ActionVec3 *ActionVec3::reverse() const
{
    if (m_Value) {
        return ActionVec3::create(m_Duration, m_To, m_From, m_Value);
    }
    return ActionVec3::create(m_Duration, m_To, m_From, m_Callback);
}
