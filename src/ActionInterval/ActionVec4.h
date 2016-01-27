#ifndef ACTIONVEC4_H
#define ACTIONVEC4_H
#include "ActionInterval.h"

/**
 * @class ActionVec4
 * @brief Action used to animate any value in range [from,to] over specified time interval
 */
class ActionVec4 : public ActionInterval
{
public:
    /**
     *  Callback function used to report back result
     */
    typedef std::function<void(ofVec4f value)> ActionVec4Callback;

    /**
     * Creates Vec3 Action with specified duration, from value, to value and callback to report back
     * results
     * @param duration of the action
     * @param from value to start from
     * @param to value to be at the end of the action
     * @param callback to report back result
     *
     * @return An autoreleased ActionVec4 object
     */
    static ActionVec4 *create(float duration, ofVec4f from, ofVec4f to, ActionVec4Callback callback);
    static ActionVec4 *create(float duration, ofVec4f from, ofVec4f to, ofVec4f *value);

    /**
     * Overridden ActionInterval methods
     */
    void startWithTarget(ActionTarget *target) override;
    void update(float delta) override;
    ActionVec4 *reverse() const override;
    ActionVec4 *clone() const override;

public:
    ActionVec4();
    virtual ~ActionVec4() {}

    bool initWithDuration(float duration, ofVec4f from, ofVec4f to, ActionVec4Callback callback);
    bool initWithDuration(float duration, ofVec4f from, ofVec4f to, ofVec4f *value);

protected:
    /* From value */
    ofVec4f m_From;
    /* To value */
    ofVec4f m_To;
    /* delta time */
    ofVec4f m_Delta;

    /* The value to change */
    ofVec4f *m_Value;

    /* Callback to report back results */
    ActionVec4Callback m_Callback;
private:
    DISALLOW_COPY_AND_ASSIGN(ActionVec4);
};

#endif // ACTIONVEC4_H
