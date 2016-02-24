/****************************************************************************
Copyright (c) 2008-2010 Ricardo Quesada
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2011      Zynga Inc.
Copyright (c) 2013-2014 Chukong Technologies Inc.

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#ifndef ACTION_H
#define ACTION_H
#include "ActionTarget.h"

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName &) = delete; \
    TypeName &operator =(const TypeName &) = delete

#define SAFE_RELEASE(p) do { if(p) { (p)->release(); (p) = nullptr; } } while(0)
#define OFXACTIONS_NS_BEGIN namespace ofxActions {
#define OFXACTIONS_NS_END }

OFXACTIONS_NS_BEGIN

/**
 * @brief Base class for Action objects
 */
class Action
{
public:
    /** Default tag used for all the actions. */
    static const int INVALID_TAG = -1;

public:
    Action();

    virtual std::string description() const;

    /** Returns a clone of action.
     *
     * @return A clone action.
     */
    virtual Action *clone() const;

    /** Returns a new action that performs the exactly the reverse action.
     *
     * @return A new action that performs the exactly the reverse action.
     */
    virtual Action *reverse() const;

    /** Return true if the action has finished.
     *
     * @return Is true if the action has finished.
     */
    virtual bool isDone() const;

    /** Called before the action start. It will also set the target.
     *
     * @param target A certain target.
     */
    virtual void startWithTarget(ActionTarget *target);

    /**
     * Called after the action has finished. It will set the 'target' to nil.
     * IMPORTANT: You should never call "Action::stop()" manually. Instead, use: "target->stopAction(action);".
     */
    virtual void stop();
    bool isStopped() const;

    /** Called every frame with it's delta time, dt in seconds. DON'T override unless you know what you are doing.
     *
     * @param dt In seconds.
     */
    virtual void step(float dt);

    /**
     * Called once per frame. time a value between 0 and 1.

     * For example:
     * - 0 Means that the action just started.
     * - 0.5 Means that the action is in the middle.
     * - 1 Means that the action is over.
     *
     * @param time A value between 0 and 1.
     */
    virtual void update(float time);

    void retain();
    void release();

    /** Return certain target.
     *
     * @return A certain target.
     */
    inline const ActionTarget *getTarget() const
    {
        return m_Target;
    }

    /** The action will modify the target properties.
     *
     * @param target A certain target.
     */
    inline void setTarget(ActionTarget *target)
    {
        m_Target = target;
    }

    /** Return a original Target.
     *
     * @return A original Target.
     */
    inline ActionTarget *getOriginalTarget() const
    {
        return m_OriginalTarget;
    }

    /**
     * Set the original target, since target can be nil.
     * Is the target that were used to run the action. Unless you are doing something complex, like ActionManager, you should NOT call this method.
     * The target is 'assigned', it is not 'retained'.
     *
     * @param originalTarget Is 'assigned', it is not 'retained'.
     */
    inline void setOriginalTarget(ActionTarget *originalTarget)
    {
        m_OriginalTarget = originalTarget;
    }

    /** Returns a tag that is used to identify the action easily.
     *
     * @return A tag.
     */
    inline int getTag() const
    {
        return m_Tag;
    }

    /** Changes the tag that is used to identify the action easily.
     *
     * @param tag Used to identify the action easily.
     */
    inline void setTag(int tag)
    {
        m_Tag = tag;
    }

    /** Returns a flag field that is used to group the actions easily.
     *
     * @return A tag.
     */
    inline unsigned int getFlags() const
    {
        return m_Flags;
    }
    /** Changes the flag field that is used to group the actions easily.
     *
     * @param tag Used to identify the action easily.
     */
    inline void setFlags(unsigned int flags)
    {
        m_Flags = flags;
    }

private:
    int m_Tag, m_RefCount;

protected:
    ActionTarget *m_OriginalTarget,
                 *m_Target;
    /** The action flag field. To categorize action into certain groups.*/
    unsigned int m_Flags;
};

OFXACTIONS_NS_END

OFXACTIONS_NS_BEGIN

/** @class FiniteTimeAction
 * @brief
 * Base class actions that do have a finite time duration.
 * Possible actions:
 * - An action with a duration of 0 seconds.
 * - An action with a duration of 35.5 seconds.
 * Infinite time actions are valid.
 */
class FiniteTimeAction : public Action
{
public:
    /** Get duration in seconds of the action.
     *
     * @return The duration in seconds of the action.
     */
    inline float getDuration() const
    {
        return m_Duration;
    }
    /** Set duration in seconds of the action.
     *
     * @param duration In seconds of the action.
     */
    inline void setDuration(float duration)
    {
        m_Duration = duration;
    }

    //
    // Overrides
    //
    virtual FiniteTimeAction *reverse() const override
    {
        return nullptr;
    }

    virtual FiniteTimeAction *clone() const override
    {
        return nullptr;
    }

public:
    FiniteTimeAction()
        : m_Duration(0)
    {}

    virtual ~FiniteTimeAction() {}

protected:
    //! Duration in seconds.
    float m_Duration;

private:
    DISALLOW_COPY_AND_ASSIGN(FiniteTimeAction);
};

OFXACTIONS_NS_END

//For making sure we can use actions without using the ofxActions namespace
using namespace ofxActions;

#endif // ACTION_H
