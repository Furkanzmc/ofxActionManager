#ifndef ACTIONFLOAT_H
#define ACTIONFLOAT_H
#include "ActionInterval.h"

/**
 * @class ActionFloat
 * @brief Action used to animate any value in range [from,to] over specified time interval
 */
class ActionFloat : public ActionInterval
{
public:
    /**
     *  Callback function used to report back result
     */
    typedef std::function<void(float value)> ActionFloatCallback;

    /**
     * Creates FloatAction with specified duration, from value, to value and callback to report back
     * results
     * @param duration of the action
     * @param from value to start from
     * @param to value to be at the end of the action
     * @param callback to report back result
     *
     * @return An autoreleased ActionFloat object
     */
    static ActionFloat *create(float duration, float from, float to, ActionFloatCallback callback);
    static ActionFloat *create(float duration, float from, float to, float *value);

    /**
     * Overridden ActionInterval methods
     */
    void startWithTarget(ActionTarget *target) override;
    void update(float delta) override;
    ActionFloat *reverse() const override;
    ActionFloat *clone() const override;

public:
    ActionFloat();
    virtual ~ActionFloat() {}

    bool initWithDuration(float duration, float from, float to, ActionFloatCallback callback);
    bool initWithDuration(float duration, float from, float to, float *value);

protected:
    /* From value */
    float m_From;
    /* To value */
    float m_To;
    /* delta time */
    float m_Delta;

    /* The value to change */
    float *m_Value;

    /* Callback to report back results */
    ActionFloatCallback m_Callback;
private:
    DISALLOW_COPY_AND_ASSIGN(ActionFloat);
};

#endif // ACTIONFLOAT_H
