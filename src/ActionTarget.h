#ifndef ACTIONTARGET_H
#define ACTIONTARGET_H
#include "ofVec3f.h"
#include "ofColor.h"

namespace ofxActions
{
class Action;
}

class ActionTarget
{
public:
    std::function<void(const ofVec3f &)> onPositionChanged;
    std::function<void(const ofVec3f &)> onScaleChanged;
    std::function<void(const ofVec3f &)> onRotationChanged;

    std::function<void(const ofColor &)> onColorChanged;
    std::function<void(const GLubyte &)> onOpacityChanged;
    std::function<void(bool)> onVisibilityChanged;

public:
    ActionTarget();
    virtual ~ActionTarget();

    const ofVec3f &getPosition() const;
    void setPosition(const ofVec3f &positon);

    const ofVec3f &getScale() const;
    void setScale(const ofVec3f &scale);

    const ofVec3f &getRotation() const;
    void setRotation(const ofVec3f &rotation);

    const ofColor &getColor() const;
    void setColor(const ofColor &color);

    GLubyte getOpacity() const;
    void setOpacity(GLubyte alpha);

    void runAction(ofxActions::Action *action);

    ofxActions::Action *getActionByTag(int tag) const;
    size_t getNumberOfRunningActions() const;

    void stopAllActions();
    void stopActionByTag(int tag);

    void retain();
    void release();

    bool isVisible() const;
    void setVisible(bool visible);

    unsigned int getReferenceCount() const;

protected:
    ofVec3f m_Position;
    ofVec3f m_Scale;
    ofVec3f m_Rotation;
    ofColor m_Color;
    bool m_IsVisible;
    unsigned int m_ReferenceCount;
};

#endif // ACTIONTARGET_H
