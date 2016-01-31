#ifndef ROTATEACTION_H
#define ROTATEACTION_H
#include "ActionInterval.h"

/** @class RotateTo
 * @brief Rotates a ActionTarget object to a certain angle by modifying it's rotation attribute.
 The direction will be decided by the shortest angle.
*/
class RotateTo : public ActionInterval
{
public:
    /**
     * Creates the action with separate rotation angles.
     *
     * @param duration Duration time, in seconds.
     * @param dstAngleX In degreesCW.
     * @param dstAngleY In degreesCW.
     * @return An autoreleased RotateTo object.
     */
    static RotateTo *create(float duration, float dstAngleX, float dstAngleY);

    /**
     * Creates the action.
     *
     * @param duration Duration time, in seconds.
     * @param dstAngle In degreesCW.
     * @return An autoreleased RotateTo object.
     */
    static RotateTo *create(float duration, float dstAngle);

    /**
     * Creates the action with 3D rotation angles.
     * @param duration Duration time, in seconds.
     * @param dstAngle3D A ofVec3f angle.
     * @return An autoreleased RotateTo object.
     */
    static RotateTo *create(float duration, const ofVec3f &dstAngle3D);

    //
    // Overrides
    //
    virtual RotateTo *clone() const override;
    virtual RotateTo *reverse() const override;
    virtual void startWithTarget(ActionTarget *target) override;
    /**
     * @param time In seconds.
     */
    virtual void update(float time) override;

public:
    RotateTo();
    virtual ~RotateTo() {}

    /**
     * initializes the action
     * @param duration in seconds
     * @param dstAngleX in degreesCW
     * @param dstAngleY in degreesCW
     */
    bool initWithDuration(float duration, float dstAngleX, float dstAngleY);
    /**
     * initializes the action
     * @param duration in seconds
     */
    bool initWithDuration(float duration, const ofVec3f &dstAngle3D);

    /**
     * calculates the start and diff angles
     * @param dstAngle in degreesCW
     */
    void calculateAngles(float &startAngle, float &diffAngle, float dstAngle);

    const ofVec3f &getDestinationAngle() const;

protected:
    ofVec3f m_DstAngle;
    ofVec3f m_StartAngle;
    ofVec3f m_DiffAngle;

private:
    DISALLOW_COPY_AND_ASSIGN(RotateTo);
};

/** @class RotateBy
 * @brief Rotates a ActionTarget object clockwise a number of degrees by modifying it's rotation attribute.
*/
class RotateBy : public ActionInterval
{
public:
    /**
     * Creates the action.
     *
     * @param duration Duration time, in seconds.
     * @param deltaAngle In degreesCW.
     * @return An autoreleased RotateBy object.
     */
    static RotateBy *create(float duration, float deltaAngle);

    /** Creates the action with 3D rotation angles.
     *
     * @param duration Duration time, in seconds.
     * @param deltaAngle3D A ofVec3f angle.
     * @return An autoreleased RotateBy object.
     */
    static RotateBy *create(float duration, const ofVec3f &deltaAngle3D);

    //
    // Override
    //
    virtual RotateBy *clone() const override;
    virtual RotateBy *reverse(void) const override;
    virtual void startWithTarget(ActionTarget *target) override;
    /**
     * @param time In seconds.
     */
    virtual void update(float time) override;

public:
    RotateBy();
    virtual ~RotateBy() {}

    /** initializes the action */
    bool initWithDuration(float duration, float deltaAngle);

    bool initWithDuration(float duration, const ofVec3f &deltaAngle3D);

    const ofVec3f &getDeltaAngle() const;

protected:
    ofVec3f m_DeltaAngle;
    ofVec3f m_StartAngle;

private:
    DISALLOW_COPY_AND_ASSIGN(RotateBy);
};
#endif // ROTATEACTION_H
