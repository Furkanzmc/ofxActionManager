#include "ActionTarget.h"
#include "ActionManager.h"

ActionTarget::ActionTarget()
{

}

ActionTarget::~ActionTarget()
{

}

ofVec3f ActionTarget::getPosition() const
{
    return m_Position;
}

void ActionTarget::setPosition(const ofVec3f &positon)
{
    m_Position = positon;
}

ofVec3f ActionTarget::getScale() const
{
    return m_Scale;
}

void ActionTarget::setScale(const ofVec3f &scale)
{
    m_Scale = scale;
}

ofVec3f ActionTarget::getRotation() const
{
    return m_Rotation;
}

void ActionTarget::setRotation(const ofVec3f &rotation)
{
    m_Rotation = rotation;
}

ofColor ActionTarget::getColor() const
{
    return m_Color;
}

void ActionTarget::setColor(const ofColor &color)
{
    m_Color = color;
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
