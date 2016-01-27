#include "ActionFloat.h"

ActionFloat::ActionFloat()
    : m_Value(nullptr)
{
}

ActionFloat *ActionFloat::create(float duration, float from, float to, ActionFloatCallback callback)
{
    auto ref = new(std::nothrow) ActionFloat();
    if (ref && ref->initWithDuration(duration, from, to, callback)) {
        return ref;
    }
    SAFE_RELEASE(ref);
    return ref;
}

bool ActionFloat::initWithDuration(float duration, float from, float to, ActionFloatCallback callback)
{
    if (ActionInterval::initWithDuration(duration)) {
        m_From = from;
        m_To = to;
        m_Callback = callback;
        return true;
    }
    return false;
}

ActionFloat *ActionFloat::create(float duration, float from, float to, float *value)
{
    auto ref = new(std::nothrow) ActionFloat();
    if (ref && ref->initWithDuration(duration, from, to, value)) {
        return ref;
    }
    SAFE_RELEASE(ref);
    return ref;
}

bool ActionFloat::initWithDuration(float duration, float from, float to, float *value)
{
    if (ActionInterval::initWithDuration(duration)) {
        m_From = from;
        m_To = to;
        m_Value = value;
        return true;
    }
    return false;
}


ActionFloat *ActionFloat::clone() const
{
    auto a = new(std::nothrow) ActionFloat();
    a->initWithDuration(m_Duration, m_From, m_To, m_Callback);
    return a;
}

void ActionFloat::startWithTarget(ActionTarget *target)
{
    ActionInterval::startWithTarget(target);
    m_Delta = m_To - m_From;
}

void ActionFloat::update(float delta)
{
    const float value = m_To - m_Delta * (1 - delta);

    if (m_Value != nullptr) {
        *m_Value = value;
    }
    else if (m_Callback) {
        m_Callback(value);
    }
}

ActionFloat *ActionFloat::reverse() const
{
    return ActionFloat::create(m_Duration, m_To, m_From, m_Callback);
}
