#include "ActionVec4.h"

ActionVec4::ActionVec4()
    : m_Value(nullptr)
{
}

ActionVec4 *ActionVec4::create(float duration, ofVec4f from, ofVec4f to, ActionVec4Callback callback)
{
    auto ref = new(std::nothrow) ActionVec4();
    if (ref && ref->initWithDuration(duration, from, to, callback)) {
        return ref;
    }
    SAFE_RELEASE(ref);
    return ref;
}

bool ActionVec4::initWithDuration(float duration, ofVec4f from, ofVec4f to, ActionVec4Callback callback)
{
    if (ActionInterval::initWithDuration(duration)) {
        m_From = from;
        m_To = to;
        m_Callback = callback;
        return true;
    }
    return false;
}

ActionVec4 *ActionVec4::create(float duration, ofVec4f from, ofVec4f to, ofVec4f *value)
{
    auto ref = new(std::nothrow) ActionVec4();
    if (ref && ref->initWithDuration(duration, from, to, value)) {
        return ref;
    }
    SAFE_RELEASE(ref);
    return ref;
}

bool ActionVec4::initWithDuration(float duration, ofVec4f from, ofVec4f to, ofVec4f *value)
{
    if (ActionInterval::initWithDuration(duration)) {
        m_From = from;
        m_To = to;
        m_Value = value;
        return true;
    }
    return false;
}


ActionVec4 *ActionVec4::clone() const
{
    auto a = new(std::nothrow) ActionVec4();
    a->initWithDuration(m_Duration, m_From, m_To, m_Callback);
    return a;
}

void ActionVec4::startWithTarget(ActionTarget *target)
{
    ActionInterval::startWithTarget(target);
    m_Delta = m_To - m_From;
}

void ActionVec4::update(float delta)
{
    const ofVec4f value(m_To.x - m_Delta.x * (1 - delta),
                        m_To.y - m_Delta.y * (1 - delta),
                        m_To.z - m_Delta.z * (1 - delta),
                        m_To.w - m_Delta.w * (1 - delta));

    if (m_Value != nullptr) {
        *m_Value = value;
    }
    else if (m_Callback) {
        m_Callback(value);
    }
}

ActionVec4 *ActionVec4::reverse() const
{
    return ActionVec4::create(m_Duration, m_To, m_From, m_Callback);
}
