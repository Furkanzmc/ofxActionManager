#ifndef TINTACTION_H
#define TINTACTION_H
#include "ActionInterval.h"
#include "ofColor.h"

OFXACTIONS_NS_BEGIN

/** @class TintTo
 * @brief Tints a ActionTarget that implements the ActionTargetRGB protocol from current tint to a custom one.
 @warning This action doesn't support "reverse"
 @since v0.7.2
*/
class TintTo : public ActionInterval
{
public:
    /**
     * Creates an action with duration and color.
     * @param duration Duration time, in seconds.
     * @param red Red Color, from 0 to 255.
     * @param green Green Color, from 0 to 255.
     * @param blue Blue Color, from 0 to 255.
     * @return An autoreleased TintTo object.
     */
    static TintTo *create(float duration, GLubyte red, GLubyte green, GLubyte blue);
    /**
     * Creates an action with duration and color.
     * @param duration Duration time, in seconds.
     * @param color It's a ofColor type.
     * @return An autoreleased TintTo object.
     */
    static TintTo *create(float duration, const ofColor &color);

    //
    // Overrides
    //
    virtual TintTo *clone() const override;
    virtual TintTo *reverse(void) const override;
    virtual void startWithTarget(ActionTarget *target) override;
    /**
     * @param time In seconds.
     */
    virtual void update(float time) override;

public:
    TintTo() {}
    virtual ~TintTo() {}

    /** initializes the action with duration and color */
    bool initWithDuration(float duration, GLubyte red, GLubyte green, GLubyte blue);

protected:
    ofColor m_To;
    ofColor m_From;

private:
    DISALLOW_COPY_AND_ASSIGN(TintTo);
};

/** @class TintBy
 @brief Tints a ActionTarget that implements the ActionTargetRGB protocol from current tint to a custom one.
 @since v0.7.2
 */
class TintBy : public ActionInterval
{
public:
    /**
     * Creates an action with duration and color.
     * @param duration Duration time, in seconds.
     * @param deltaRed Delta red color.
     * @param deltaGreen Delta green color.
     * @param deltaBlue Delta blue color.
     * @return An autoreleased TintBy object.
     */
    static TintBy *create(float duration, GLshort deltaRed, GLshort deltaGreen, GLshort deltaBlue);

    //
    // Overrides
    //
    virtual TintBy *clone() const override;
    virtual TintBy *reverse() const override;
    virtual void startWithTarget(ActionTarget *target) override;
    /**
     * @param time In seconds.
     */
    virtual void update(float time) override;

public:
    TintBy() {}
    virtual ~TintBy() {}

    /** initializes the action with duration and color */
    bool initWithDuration(float duration, GLshort deltaRed, GLshort deltaGreen, GLshort deltaBlue);

protected:
    GLshort m_DeltaR;
    GLshort m_DeltaG;
    GLshort m_DeltaB;

    GLshort m_FromR;
    GLshort m_FromG;
    GLshort m_FromB;

private:
    DISALLOW_COPY_AND_ASSIGN(TintBy);
};

OFXACTIONS_NS_END

#endif // TINTACTION_H
