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

#ifndef EASECIRCLE_H
#define EASECIRCLE_H
#include "../ActionEase.h"

/**
@class EaseCircleActionIn
@brief Ease Circle In
@ingroup Actions
*/
class EaseCircleActionIn : public ActionEase
{
public:
    /**
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseCircleActionIn action. If creation failed, return nil.
    */
    static EaseCircleActionIn *create(ActionInterval *action);

    virtual void update(float time) override;
    virtual EaseCircleActionIn *clone() const override;
    virtual EaseCircleActionIn *reverse() const override;

public:
    EaseCircleActionIn() {}
    virtual ~EaseCircleActionIn() {}

private:
    DISALLOW_COPY_AND_ASSIGN(EaseCircleActionIn);
};

/**
@class EaseCircleActionOut
@brief Ease Circle Out
@ingroup Actions
*/
class EaseCircleActionOut : public ActionEase
{
public:
    /**
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseCircleActionOut action. If creation failed, return nil.
    */
    static EaseCircleActionOut *create(ActionInterval *action);

    virtual void update(float time) override;
    virtual EaseCircleActionOut *clone() const override;
    virtual EaseCircleActionOut *reverse() const override;

public:
    EaseCircleActionOut() {}
    virtual ~EaseCircleActionOut() {}

private:
    DISALLOW_COPY_AND_ASSIGN(EaseCircleActionOut);
};

/**
@class EaseCircleActionInOut
@brief Ease Circle InOut
@ingroup Actions
*/
class EaseCircleActionInOut: public ActionEase
{
public:
    /**
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseCircleActionInOut action. If creation failed, return nil.
    */
    static EaseCircleActionInOut *create(ActionInterval *action);

    virtual void update(float time) override;
    virtual EaseCircleActionInOut *clone() const override;
    virtual EaseCircleActionInOut *reverse() const override;

public:
    EaseCircleActionInOut() {}
    virtual ~EaseCircleActionInOut() {}

private:
    DISALLOW_COPY_AND_ASSIGN(EaseCircleActionInOut);
};

#endif // EASECIRCLE_H
