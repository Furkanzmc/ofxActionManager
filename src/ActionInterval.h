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

#ifndef ACTIONINTERVAL_H
#define ACTIONINTERVAL_H
#include "Action.h"

OFXACTIONS_NS_BEGIN

/**
 * @addtogroup actions
 * @{
 */

/** @class ActionInterval
@brief An interval action is an action that takes place within a certain period of time.
It has an start time, and a finish time. The finish time is the parameter
duration plus the start time.

These ActionInterval actions have some interesting properties, like:
- They can run normally (default)
- They can run reversed with the reverse method
- They can run with the time altered with the Accelerate, AccelDeccel and Speed actions.

For example, you can simulate a Ping Pong effect running the action normally and
then running it again in Reverse mode.

Example:

Action *pingPongAction = Sequence::actions(action, action->reverse(), nullptr);
*/
class ActionInterval : public FiniteTimeAction
{
public:
    ActionInterval();

    /** How many seconds had elapsed since the actions started to run.
     *
     * @return The seconds had elapsed since the actions started to run.
     */
    inline float getElapsed(void)
    {
        return m_Elapsed;
    }

    //
    // Overrides
    //
    virtual bool isDone(void) const override;

    /**
     * @param dt in seconds
     */
    virtual void step(float dt) override;
    virtual void startWithTarget(ActionTarget *target) override;
    virtual ActionInterval *reverse() const override
    {
        return nullptr;
    }

    virtual ActionInterval *clone() const override
    {
        return nullptr;
    }

public:
    /** initializes the action */
    bool initWithDuration(float d);

protected:
    float m_Elapsed;
    bool m_IsFirstTick;
};

// Extra action for making a Sequence or Spawn when only adding one action to it.
class ExtraAction : public FiniteTimeAction
{
public:
    static ExtraAction *create();
    virtual ExtraAction *clone() const;
    virtual ExtraAction *reverse(void) const;
    virtual void update(float time);
    virtual void step(float dt);
};

OFXACTIONS_NS_END

#endif // ACTIONINTERVAL_H
