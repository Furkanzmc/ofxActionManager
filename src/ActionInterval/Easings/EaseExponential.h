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

#ifndef EASEEXPONENTIALIN_H
#define EASEEXPONENTIALIN_H
#include "../ActionEase.h"

OFXACTIONS_NS_BEGIN

/**
 @class EaseExponentialIn
 @brief Ease Exponential In action.
 @details The timeline of inner action will be changed by:
         \f${ 2 }^{ 10*(time-1) }-1*0.001\f$.
 @ingroup Actions
 */
class EaseExponentialIn : public ActionEase
{
public:
    /**
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseExponentialIn action. If creation failed, return nil.
    */
    static EaseExponentialIn *create(ActionInterval *action);

    // Overrides
    virtual void update(float time) override;
    virtual EaseExponentialIn *clone() const override;
    virtual ActionEase *reverse() const override;

public:
    EaseExponentialIn();
    virtual ~EaseExponentialIn() {}

private:
    DISALLOW_COPY_AND_ASSIGN(EaseExponentialIn);
};

//EaseExponentialInOut

/**
 @class EaseExponentialInOut
 @brief Ease Exponential InOut
 @details If time * 2 < 1, the timeline of inner action will be changed by:
         \f$0.5*{ 2 }^{ 10*(time-1) }\f$.
         else, the timeline of inner action will be changed by:
         \f$0.5*(2-{ 2 }^{ -10*(time-1) })\f$.
 @ingroup Actions
 */
class EaseExponentialInOut : public ActionEase
{
public:
    /**
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseExponentialInOut action. If creation failed, return nil.
    */
    static EaseExponentialInOut *create(ActionInterval *action);

    // Overrides
    virtual void update(float time) override;
    virtual EaseExponentialInOut *clone() const override;
    virtual EaseExponentialInOut *reverse() const override;

public:
    EaseExponentialInOut();
    virtual ~EaseExponentialInOut() {}

private:
    DISALLOW_COPY_AND_ASSIGN(EaseExponentialInOut);
};

//EaseExponentialOut

/**
 @class EaseExponentialOut
 @brief Ease Exponential Out
 @details The timeline of inner action will be changed by:
         \f$1-{ 2 }^{ -10*(time-1) }\f$.
 @ingroup Actions
 */
class EaseExponentialOut : public ActionEase
{
public:
    /**
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseExponentialOut action. If creation failed, return nil.
    */
    static EaseExponentialOut *create(ActionInterval *action);

    // Overrides
    virtual void update(float time) override;
    virtual EaseExponentialOut *clone() const override;
    virtual ActionEase *reverse() const override;

public:
    EaseExponentialOut();
    virtual ~EaseExponentialOut() {}

private:
    DISALLOW_COPY_AND_ASSIGN(EaseExponentialOut);
};

OFXACTIONS_NS_END

#endif // EASEEXPONENTIALIN_H
