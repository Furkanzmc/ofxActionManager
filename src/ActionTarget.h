#ifndef ACTIONTARGET_H
#define ACTIONTARGET_H
#include "ofVec3f.h"
#include "ofColor.h"
class Action;

class ActionTarget
{
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

    void runAction(Action *action);

    Action *getActionByTag(int tag) const;
    size_t getNumberOfRunningActions() const;

    void stopAllActions();
    void stopActionByTag(int tag);

    void release();

protected:
    ofVec3f m_Position;
    ofVec3f m_Scale;
    ofVec3f m_Rotation;
    ofColor m_Color;
};

#endif // ACTIONTARGET_H
