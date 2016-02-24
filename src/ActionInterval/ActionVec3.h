#ifndef ACTIONVEC3_H
#define ACTIONVEC3_H
#include "ActionInterval.h"

OFXACTIONS_NS_BEGIN

/**
 * @class ActionVec3
 * @brief Action used to animate any value in range [from,to] over specified time interval
 */
class ActionVec3 : public ActionInterval
{
public:
    /**
     *  Callback function used to report back result
     */
    typedef std::function<void(ofVec3f value)> ActionVec3Callback;

    /**
     * Creates Vec3 Action with specified duration, from value, to value and callback to report back
     * results
     * @param duration of the action
     * @param from value to start from
     * @param to value to be at the end of the action
     * @param callback to report back result
     *
     * @return An autoreleased ActionVec3 object
     */
    static ActionVec3 *create(float duration, ofVec3f from, ofVec3f to, ActionVec3Callback callback);
    static ActionVec3 *create(float duration, ofVec3f from, ofVec3f to, ofVec3f *value);

    /**
     * Overridden ActionInterval methods
     */
    void startWithTarget(ActionTarget *target) override;
    void update(float delta) override;
    ActionVec3 *reverse() const override;
    ActionVec3 *clone() const override;

public:
    ActionVec3();
    virtual ~ActionVec3() {}

    bool initWithDuration(float duration, ofVec3f from, ofVec3f to, ActionVec3Callback callback);
    bool initWithDuration(float duration, ofVec3f from, ofVec3f to, ofVec3f *value);

protected:
    /* From value */
    ofVec3f m_From;
    /* To value */
    ofVec3f m_To;
    /* delta time */
    ofVec3f m_Delta;

    /* The value to change */
    ofVec3f *m_Value;

    /* Callback to report back results */
    ActionVec3Callback m_Callback;
private:
    DISALLOW_COPY_AND_ASSIGN(ActionVec3);
};

OFXACTIONS_NS_END

#endif // ACTIONVEC3_H
