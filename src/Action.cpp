#include "Action.h"
#include "ofMain.h"

Action::Action()
    : m_Tag(-1)
    , m_RefCount(1)
    , m_OriginalTarget(nullptr)
    , m_Target(nullptr)
{

}

std::string Action::description() const
{
    return "Action | Tag = " + std::to_string(m_Tag);
}

Action *Action::clone() const
{
    return nullptr;
}

Action *Action::reverse() const
{
    return nullptr;
}

bool Action::isDone() const
{
    return true;
}

void Action::startWithTarget(ActionTarget *aTarget)
{
    m_OriginalTarget = m_Target = aTarget;
}

void Action::stop()
{
    m_Target = nullptr;
}

bool Action::isStopped() const
{
    return m_Target == nullptr;
}

void Action::step(float dt)
{
    ofLogNotice("ofxAction") << __FUNCTION__ << ": Override me!";
}

void Action::update(float time)
{
    ofLogNotice("ofxAction") << __FUNCTION__ << ": Override me!";
}

void Action::retain()
{
    m_RefCount++;
}

void Action::release()
{
    m_RefCount--;
    if (m_RefCount <= 0) {
        delete this;
    }
}
