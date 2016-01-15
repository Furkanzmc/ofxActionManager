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

#ifndef EASEQUADRATIC_H
#define EASEQUADRATIC_H
#include "../ActionEase.h"

/**
@class EaseQuadraticActionIn
@brief Ease Quadratic In
@ingroup Actions
*/
class EaseQuadraticActionIn : public ActionEase
{
public:
    /**
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseQuadraticActionIn action. If creation failed, return nil.
    */
    static EaseQuadraticActionIn *create(ActionInterval *action);

    virtual void update(float time) override;
    virtual EaseQuadraticActionIn *clone() const override;
    virtual EaseQuadraticActionIn *reverse() const override;

public:
    EaseQuadraticActionIn() {}
    virtual ~EaseQuadraticActionIn() {}

private:
    DISALLOW_COPY_AND_ASSIGN(EaseQuadraticActionIn);

};

/**
@class EaseQuadraticActionOut
@brief Ease Quadratic Out
@ingroup Actions
*/
class EaseQuadraticActionOut : public ActionEase
{
public:
    /**
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseQuadraticActionOut action. If creation failed, return nil.
    */
    static EaseQuadraticActionOut *create(ActionInterval *action);

    virtual void update(float time) override;
    virtual EaseQuadraticActionOut *clone() const override;
    virtual EaseQuadraticActionOut *reverse() const override;

public:
    EaseQuadraticActionOut() {}
    virtual ~EaseQuadraticActionOut() {}

private:
    DISALLOW_COPY_AND_ASSIGN(EaseQuadraticActionOut);

};

/**
@class EaseQuadraticActionInOut
@brief Ease Quadratic InOut
@ingroup Actions
*/
class EaseQuadraticActionInOut : public ActionEase
{
public:
    /**
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseQuadraticActionInOut action. If creation failed, return nil.
    */
    static EaseQuadraticActionInOut *create(ActionInterval *action);

    virtual void update(float time) override;
    virtual EaseQuadraticActionInOut *clone() const override;
    virtual EaseQuadraticActionInOut *reverse() const override;

public:
    EaseQuadraticActionInOut() {}
    virtual ~EaseQuadraticActionInOut() {}

private:
    DISALLOW_COPY_AND_ASSIGN(EaseQuadraticActionInOut);
};

#endif // EASEQUADRATIC_H
