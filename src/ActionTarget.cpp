#include "ActionTarget.h"
#include "ActionManager.h"

ActionTarget::ActionTarget()
    : m_Position(0, 0, 0)
    , m_Scale(1, 1, 1)
    , m_Rotation(0, 0, 0)
    , m_Color(ofColor::white)
{

}

ActionTarget::~ActionTarget()
{

}

const ofVec3f &ActionTarget::getPosition() const
{
    return m_Position;
}

void ActionTarget::setPosition(const ofVec3f &positon)
{
    m_Position = positon;
}

const ofVec3f &ActionTarget::getScale() const
{
    return m_Scale;
}

void ActionTarget::setScale(const ofVec3f &scale)
{
    m_Scale = scale;
}

const ofVec3f &ActionTarget::getRotation() const
{
    return m_Rotation;
}

void ActionTarget::setRotation(const ofVec3f &rotation)
{
    m_Rotation = rotation;
}

const ofColor &ActionTarget::getColor() const
{
    return m_Color;
}

void ActionTarget::setColor(const ofColor &color)
{
    m_Color = color;
}

GLubyte ActionTarget::getOpacity() const
{
    return m_Color.a;
}

void ActionTarget::setOpacity(GLubyte alpha)
{
    m_Color.a = alpha;
}

void ActionTarget::runAction(Action *action)
{
    ActionManager::getInstance()->addAction(action, this, false);
}

Action *ActionTarget::getActionByTag(int tag) const
{
    return ActionManager::getInstance()->getActionByTag(tag, this);
}

std::size_t ActionTarget::getNumberOfRunningActions() const
{
    return ActionManager::getInstance()->getNumberOfRunningActionsInTarget(this);
}

void ActionTarget::stopAllActions()
{
    ActionManager::getInstance()->removeAllActionsFromTarget(this);
}

void ActionTarget::stopActionByTag(int tag)
{
    ActionManager::getInstance()->removeActionByTag(tag, this);
}

void ActionTarget::release()
{
    delete this;
}
