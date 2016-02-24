#ifndef REPEATACTION_H
#define REPEATACTION_H
#include "ActionInterval.h"

OFXACTIONS_NS_BEGIN

/** @class Repeat
 * @brief Repeats an action a number of times.
 * To repeat an action forever use the RepeatForever action.
 */
class Repeat : public ActionInterval
{
public:
    /** Creates a Repeat action. Times is an unsigned integer between 1 and pow(2,30).
     *
     * @param action The action needs to repeat.
     * @param times The repeat times.
     * @return An autoreleased Repeat object.
     */
    static Repeat *create(FiniteTimeAction *action, unsigned int times);

    /** Sets the inner action.
     *
     * @param action The inner action.
     */
    inline void setInnerAction(FiniteTimeAction *action)
    {
        if (m_InnerAction != action) {
            SAFE_RELEASE(m_InnerAction);
            m_InnerAction = action;
        }
    }

    /** Gets the inner action.
     *
     * @return The inner action.
     */
    inline FiniteTimeAction *getInnerAction()
    {
        return m_InnerAction;
    }

    //
    // Overrides
    //
    virtual Repeat *clone() const override;
    virtual Repeat *reverse() const override;
    virtual void startWithTarget(ActionTarget *target) override;
    virtual void stop(void) override;
    /**
     * @param dt In seconds.
     */
    virtual void update(float dt) override;
    virtual bool isDone(void) const override;

public:
    Repeat() {}
    virtual ~Repeat();

    /** initializes a Repeat action. Times is an unsigned integer between 1 and pow(2,30) */
    bool initWithAction(FiniteTimeAction *pAction, unsigned int times);

protected:
    unsigned int m_Times;
    unsigned int m_Total;
    float m_NextDt;
    bool m_ActionInstant;
    /** Inner action */
    FiniteTimeAction *m_InnerAction;

private:
    DISALLOW_COPY_AND_ASSIGN(Repeat);
};

/** @class RepeatForever
 * @brief Repeats an action for ever.
 To repeat the an action for a limited number of times use the Repeat action.
 * @warning This action can't be Sequenceable because it is not an IntervalAction.
 */
class RepeatForever : public ActionInterval
{
public:
    /** Creates the action.
     *
     * @param action The action need to repeat forever.
     * @return An autoreleased RepeatForever object.
     */
    static RepeatForever *create(ActionInterval *action);

    /** Sets the inner action.
     *
     * @param action The inner action.
     */
    inline void setInnerAction(ActionInterval *action)
    {
        if (m_InnerAction != action) {
            SAFE_RELEASE(m_InnerAction);
            m_InnerAction = action;
        }
    }

    /** Gets the inner action.
     *
     * @return The inner action.
     */
    inline ActionInterval *getInnerAction()
    {
        return m_InnerAction;
    }

    //
    // Overrides
    //
    virtual RepeatForever *clone() const override;
    virtual RepeatForever *reverse(void) const override;
    virtual void startWithTarget(ActionTarget *target) override;
    /**
     * @param dt In seconds.
     */
    virtual void step(float dt) override;
    virtual bool isDone(void) const override;

public:
    RepeatForever()
        : m_InnerAction(nullptr)
    {}
    virtual ~RepeatForever();

    /** initializes the action */
    bool initWithAction(ActionInterval *action);

protected:
    /** Inner action */
    ActionInterval *m_InnerAction;

private:
    DISALLOW_COPY_AND_ASSIGN(RepeatForever);
};

OFXACTIONS_NS_END

#endif // REPEATACTION_H
