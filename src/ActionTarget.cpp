#include "ActionTarget.h"
#include "ActionManager.h"

ActionTarget::ActionTarget()
    : m_Position(0, 0, 0)
    , m_Scale(1, 1, 1)
    , m_Rotation(0, 0, 0)
    , m_Color(ofColor::white)
    , m_ReferenceCount(1)
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
    if (onPositionChanged) {
        onPositionChanged(m_Position);
    }
}

const ofVec3f &ActionTarget::getScale() const
{
    return m_Scale;
}

void ActionTarget::setScale(const ofVec3f &scale)
{
    m_Scale = scale;
    if (onScaleChanged) {
        onScaleChanged(m_Scale);
    }
}

const ofVec3f &ActionTarget::getRotation() const
{
    return m_Rotation;
}

void ActionTarget::setRotation(const ofVec3f &rotation)
{
    m_Rotation = rotation;
    if (onRotationChanged) {
        onRotationChanged(m_Rotation);
    }
}

const ofColor &ActionTarget::getColor() const
{
    return m_Color;
}

void ActionTarget::setColor(const ofColor &color)
{
    m_Color = color;
    if (onColorChanged) {
        onColorChanged(m_Color);
    }
}

GLubyte ActionTarget::getOpacity() const
{
    return m_Color.a;
}

void ActionTarget::setOpacity(GLubyte alpha)
{
    m_Color.a = alpha;
    if (onOpacityChanged) {
        onOpacityChanged(m_Color.a);
    }
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

void ActionTarget::retain()
{
    m_ReferenceCount++;
}

void ActionTarget::release()
{
    m_ReferenceCount--;
    if (m_ReferenceCount == 0) {
        delete this;
    }
}

bool ActionTarget::isVisible() const
{
    return m_IsVisible;
}

void ActionTarget::setVisible(bool visible)
{
    m_IsVisible = visible;
    if (onVisibilityChanged) {
        onVisibilityChanged(m_IsVisible);
    }
}

unsigned int ActionTarget::getReferenceCount() const
{
    return m_ReferenceCount;
}
