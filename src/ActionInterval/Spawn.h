#ifndef SPAWNACTION_H
#define SPAWNACTION_H
#include "ActionInterval.h"

OFXACTIONS_NS_BEGIN

/** @class Spawn
 * @brief Spawn a new action immediately
 */
class Spawn : public ActionInterval
{
public:
    static Spawn *create(FiniteTimeAction *action1, ...);

    /** Helper constructor to create an array of spawned actions.
     *
     * @param action1   The first sequenceable action.
     * @param args  The va_list variable.
     * @return  An autoreleased Spawn object.
     * @js NA
     */
    static Spawn *createWithVariableList(FiniteTimeAction *action1, va_list args);

    /** Helper constructor to create an array of spawned actions given an array.
     *
     * @param arrayOfActions    An array of spawned actions.
     * @return  An autoreleased Spawn object.
     */
    static Spawn *create(const std::vector<FiniteTimeAction *> &arrayOfActions);

    /** Creates the Spawn action.
     *
     * @param action1   The first spawned action.
     * @param action2   THe second spawned action.
     * @return An autoreleased Spawn object.
     * @js NA
     */
    static Spawn *createWithTwoActions(FiniteTimeAction *action1, FiniteTimeAction *action2);

    //
    // Overrides
    //
    virtual Spawn *clone() const override;
    virtual Spawn *reverse(void) const override;
    virtual void startWithTarget(ActionTarget *target) override;
    virtual void stop(void) override;
    /**
     * @param time In seconds.
     */
    virtual void update(float time) override;

public:
    Spawn() {}
    virtual ~Spawn();

    /** initializes the Spawn action with the 2 actions to spawn */
    bool initWithTwoActions(FiniteTimeAction *action1, FiniteTimeAction *action2);

protected:
    FiniteTimeAction *m_One;
    FiniteTimeAction *m_Two;

private:
    DISALLOW_COPY_AND_ASSIGN(Spawn);
};

OFXACTIONS_NS_END

#endif // SPAWNACTION_H
