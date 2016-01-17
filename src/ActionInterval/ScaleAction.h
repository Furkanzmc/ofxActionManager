#ifndef SCALEACTION_H
#define SCALEACTION_H
#include "ActionInterval.h"

/** @class ScaleTo
 @brief Scales a ActionTarget object to a zoom factor by modifying it's scale attribute.
 @warning This action doesn't support "reverse".
 @warning The physics body contained in ActionTarget doesn't support this action.
 */
class ScaleTo : public ActionInterval
{
public:
    /**
     * Creates the action with the same scale factor for X and Y.
     * @param duration Duration time, in seconds.
     * @param s Scale factor of x and y.
     * @return An autoreleased ScaleTo object.
     */
    static ScaleTo *create(float duration, float s);

    /**
     * Creates the action with and X factor and a Y factor.
     * @param duration Duration time, in seconds.
     * @param sx Scale factor of x.
     * @param sy Scale factor of y.
     * @return An autoreleased ScaleTo object.
     */
    static ScaleTo *create(float duration, float sx, float sy);

    /**
     * Creates the action with X Y Z factor.
     * @param duration Duration time, in seconds.
     * @param sx Scale factor of x.
     * @param sy Scale factor of y.
     * @param sz Scale factor of z.
     * @return An autoreleased ScaleTo object.
     */
    static ScaleTo *create(float duration, float sx, float sy, float sz);

    //
    // Overrides
    //
    virtual ScaleTo *clone() const override;
    virtual ScaleTo *reverse(void) const override;
    virtual void startWithTarget(ActionTarget *target) override;
    /**
     * @param time In seconds.
     */
    virtual void update(float time) override;

public:
    ScaleTo() {}
    virtual ~ScaleTo() {}

    /**
     * initializes the action with the same scale factor for X and Y
     * @param duration in seconds
     */
    bool initWithDuration(float duration, float s);
    /**
     * initializes the action with and X factor and a Y factor
     * @param duration in seconds
     */
    bool initWithDuration(float duration, float sx, float sy);
    /**
     * initializes the action with X Y Z factor
     * @param duration in seconds
     */
    bool initWithDuration(float duration, float sx, float sy, float sz);

protected:
    float m_ScaleX;
    float m_ScaleY;
    float m_ScaleZ;
    float m_StartScaleX;
    float m_StartScaleY;
    float m_StartScaleZ;
    float m_EndScaleX;
    float m_EndScaleY;
    float m_EndScaleZ;
    float m_DeltaX;
    float m_DeltaY;
    float m_DeltaZ;

private:
    DISALLOW_COPY_AND_ASSIGN(ScaleTo);
};

/** @class ScaleBy
 * @brief Scales a ActionTarget object a zoom factor by modifying it's scale attribute.
 @warning The physics body contained in ActionTarget doesn't support this action.
*/
class ScaleBy : public ScaleTo
{
public:
    /**
     * Creates the action with the same scale factor for X and Y.
     * @param duration Duration time, in seconds.
     * @param s Scale factor of x and y.
     * @return An autoreleased ScaleBy object.
     */
    static ScaleBy *create(float duration, float s);

    /**
     * Creates the action with and X factor and a Y factor.
     * @param duration Duration time, in seconds.
     * @param sx Scale factor of x.
     * @param sy Scale factor of y.
     * @return An autoreleased ScaleBy object.
     */
    static ScaleBy *create(float duration, float sx, float sy);

    /**
     * Creates the action with X Y Z factor.
     * @param duration Duration time, in seconds.
     * @param sx Scale factor of x.
     * @param sy Scale factor of y.
     * @param sz Scale factor of z.
     * @return An autoreleased ScaleBy object.
     */
    static ScaleBy *create(float duration, float sx, float sy, float sz);

    //
    // Overrides
    //
    virtual void startWithTarget(ActionTarget *target) override;
    virtual ScaleBy *clone() const override;
    virtual ScaleBy *reverse(void) const override;

public:
    ScaleBy() {}
    virtual ~ScaleBy() {}

private:
    DISALLOW_COPY_AND_ASSIGN(ScaleBy);
};


#endif // SCALEACTION_H
