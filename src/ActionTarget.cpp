#include "ActionTarget.h"
#include "ActionManager.h"

ActionTarget::ActionTarget()
{

}

ofVec3f ActionTarget::getPositon() const
{
    return m_Positon;
}

void ActionTarget::setPositon(const ofVec3f &positon)
{
    m_Positon = positon;
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

void ActionTarget::release()
{
    delete this;
}
