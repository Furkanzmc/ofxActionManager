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

#ifndef ACTIONEASE_H
#define ACTIONEASE_H
#include "ActionInterval.h"
#include "TweenFunction.h"

OFXACTIONS_NS_BEGIN

/**
 @class ActionEase
 @brief Base class for Easing actions.
 @details Ease actions are created from other interval actions.
         The ease action will change the timeline of the inner action.
 @ingroup Actions
 */
class ActionEase : public ActionInterval
{
public:

    /**
    @brief Get the pointer of the inner action.
    @return The pointer of the inner action.
    */
    virtual ActionInterval *getInnerAction();

    //
    // Overrides
    //
    virtual ActionEase *clone() const override;
    virtual ActionEase *reverse() const override;

    virtual void startWithTarget(ActionTarget *target) override;
    virtual void stop() override;
    virtual void update(float time) override;

public:
    ActionEase();
    virtual ~ActionEase();

    /**
     @brief Initializes the action.
     @return Return true when the initialization success, otherwise return false.
    */
    bool initWithAction(ActionInterval *action);

protected:
    /** The inner action */
    ActionInterval *m_Inner;
private:
    DISALLOW_COPY_AND_ASSIGN(ActionEase);
};

/**
 @class EaseRateAction
 @brief Base class for Easing actions with rate parameters.
 @details Ease the inner action with specified rate.
 @ingroup Actions
 */
class EaseRateAction : public ActionEase
{
public:
    /**
     @brief Creates the action with the inner action and the rate parameter.
     @param action A given ActionInterval
     @param rate A given rate
     @return An autoreleased EaseRateAction object.
    **/
    static EaseRateAction *create(ActionInterval *action, float rate);

    /**
     @brief Set the rate value for the ease rate action.
     @param rate The value will be set.
     */
    inline void setRate(float rate)
    {
        m_Rate = rate;
    }

    /**
     @brief Get the rate value of the ease rate action.
     @return Return the rate value of the ease rate action.
     */
    inline float getRate() const
    {
        return m_Rate;
    }

    //
    // Overrides
    //
    virtual EaseRateAction *clone() const override;
    virtual EaseRateAction *reverse() const override;

public:
    EaseRateAction();
    virtual ~EaseRateAction();

    /**
     @brief Initializes the action with the inner action and the rate parameter.
     @param pAction The pointer of the inner action.
     @param fRate The value of the rate parameter.
     @return Return true when the initialization success, otherwise return false.
     */
    bool initWithAction(ActionInterval *pAction, float fRate);

protected:
    float m_Rate;

private:
    DISALLOW_COPY_AND_ASSIGN(EaseRateAction);
};

OFXACTIONS_NS_END

#endif // ACTIONEASE_H
