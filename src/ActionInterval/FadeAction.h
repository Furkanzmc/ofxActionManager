#ifndef FADEACTION_H
#define FADEACTION_H
#include "ActionInterval.h"
class ActionTarget;

OFXACTIONS_NS_BEGIN

/** @class FadeTo
 * @brief Fades an object that implements the RGBAProtocol protocol. It modifies the opacity from the current value to a custom one.
 @warning This action doesn't support "reverse"
 */
class FadeTo : public ActionInterval
{
public:
    /**
     * Creates an action with duration and opacity.
     * @param duration Duration time, in seconds.
     * @param opacity A certain opacity, the range is from 0 to 255.
     * @return An autoreleased FadeTo object.
     */
    static FadeTo *create(float duration, GLubyte opacity);

    //
    // Overrides
    //
    virtual FadeTo *clone() const override;
    virtual FadeTo *reverse(void) const override;
    virtual void startWithTarget(ActionTarget *target) override;
    /**
     * @param time In seconds.
     */
    virtual void update(float time) override;

public:
    FadeTo() {}
    virtual ~FadeTo() {}

    /**
     * initializes the action with duration and opacity
     * @param duration in seconds
     */
    bool initWithDuration(float duration, GLubyte opacity);

protected:
    GLubyte _toOpacity;
    GLubyte _fromOpacity;
    friend class FadeOut;
    friend class FadeIn;
private:
    DISALLOW_COPY_AND_ASSIGN(FadeTo);
};

/** @class FadeIn
 * @brief Fades In an object that implements the RGBAProtocol protocol. It modifies the opacity from 0 to 255.
 The "reverse" of this action is FadeOut
 */
class FadeIn : public FadeTo
{
public:
    /**
     * Creates the action.
     * @param d Duration time, in seconds.
     * @return An autoreleased FadeIn object.
     */
    static FadeIn *create(float d);

    //
    // Overrides
    //
    virtual void startWithTarget(ActionTarget *target) override;
    virtual FadeIn *clone() const override;
    virtual FadeTo *reverse(void) const override;

    /**
     * @js NA
     */
    void setReverseAction(FadeTo *ac);

public:
    FadeIn(): _reverseAction(nullptr) {}
    virtual ~FadeIn() {}

private:
    DISALLOW_COPY_AND_ASSIGN(FadeIn);
    FadeTo *_reverseAction;
};

/** @class FadeOut
 * @brief Fades Out an object that implements the RGBAProtocol protocol. It modifies the opacity from 255 to 0.
 The "reverse" of this action is FadeIn
*/
class FadeOut : public FadeTo
{
public:
    /**
     * Creates the action.
     * @param d Duration time, in seconds.
     */
    static FadeOut *create(float d);

    //
    // Overrides
    //
    virtual void startWithTarget(ActionTarget *target) override;
    virtual FadeOut *clone() const  override;
    virtual FadeTo *reverse(void) const override;

    /**
     * @js NA
     */
    void setReverseAction(FadeTo *ac);

public:
    FadeOut(): _reverseAction(nullptr) {}
    virtual ~FadeOut() {}
private:
    DISALLOW_COPY_AND_ASSIGN(FadeOut);
    FadeTo *_reverseAction;
};

OFXACTIONS_NS_END

#endif // FADEACTION_H
