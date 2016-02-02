#ifndef CALLFUNC_H
#define CALLFUNC_H
#include "ActionInstant.h"

/** @class CallFunc
* @brief Calls a 'callback'.
*/
class CallFunc : public ActionInstant
{
public:
    /** Creates the action with the callback of type std::function<void()>.
     This is the pActionTargeterred way to create the callback.
     * When this function bound in js or lua ,the input param will be changed.
     * In js: var create(var func, var this, var [data]) or var create(var func).
     * In lua:local create(local funcID).
     *
     * @param func  A callback function need to be executed.
     * @return  An autoreleased CallFunc object.
     */
    static CallFunc *create(const std::function<void()> &func);

public:
    /** Executes the callback.
     */
    virtual void execute();

    //
    // Overrides
    //
    /**
     * @param time In seconds.
     */
    virtual void update(float time) override;
    virtual CallFunc *reverse() const override;
    virtual CallFunc *clone() const override;

public:
    CallFunc()
        : m_Function(nullptr)
    {
    }
    virtual ~CallFunc();

    /** initializes the action with the std::function<void()>
     * @lua NA
     */
    bool initWithFunction(const std::function<void()> &func);

protected:
    /** function that will be called */
    std::function<void()> m_Function;

private:
    DISALLOW_COPY_AND_ASSIGN(CallFunc);
};

/** @class CallFuncN
* @brief Calls a 'callback' with the node as the first argument. N means Node.
* @js NA
*/
class CallFuncN : public ActionInstant
{
public:
    /** Creates the action with the callback of type std::function<void()>.
     This is the pActionTargeterred way to create the callback.
     * When this function bound in js or lua ,the input param will be changed.
     * In js: var create(var func, var this, var [data]) or var create(var func).
     * In lua:local create(local funcID).
     *
     * @param func  A callback function need to be executed.
     * @return  An autoreleased CallFuncN object.
     */
    static CallFuncN *create(const std::function<void(ActionTarget *)> &func);

public:
    /** Executes the callback.
     */
    virtual void execute();

    //
    // Overrides
    //
    /**
     * @param time In seconds.
     */
    virtual void update(float time) override;
    virtual CallFuncN *reverse() const override;
    virtual CallFuncN *clone() const override;

public:
    CallFuncN()
        : m_Function(nullptr)
    {
    }
    virtual ~CallFuncN();

    /** initializes the action with the std::function<void()>
     * @lua NA
     */
    bool initWithFunction(const std::function<void(ActionTarget *)> &func);

protected:
    /** function that will be called */
    std::function<void(ActionTarget *)> m_Function;

private:
    DISALLOW_COPY_AND_ASSIGN(CallFuncN);
};

#endif // CALLFUNC_H
