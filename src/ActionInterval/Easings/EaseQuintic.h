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

#ifndef EASEQUINTIC_H
#define EASEQUINTIC_H
#include "../ActionEase.h"

OFXACTIONS_NS_BEGIN

/**
@class EaseQuinticActionIn
@brief Ease Quintic In
@ingroup Actions
*/
class EaseQuinticActionIn : public ActionEase
{
public:
    /**
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseQuinticActionIn action. If creation failed, return nil.
    */
    static EaseQuinticActionIn *create(ActionInterval *action);

    virtual void update(float time) override;
    virtual EaseQuinticActionIn *clone() const override;
    virtual EaseQuinticActionIn *reverse() const override;

public:
    EaseQuinticActionIn() {}
    virtual ~EaseQuinticActionIn() {}

private:
    DISALLOW_COPY_AND_ASSIGN(EaseQuinticActionIn);
};

/**
@class EaseQuinticActionOut
@brief Ease Quintic Out
@ingroup Actions
*/
class EaseQuinticActionOut : public ActionEase
{
public:
    /**
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseQuinticActionOut action. If creation failed, return nil.
    */
    static EaseQuinticActionOut *create(ActionInterval *action);

    virtual void update(float time) override;
    virtual EaseQuinticActionOut *clone() const override;
    virtual EaseQuinticActionOut *reverse() const override;

public:
    EaseQuinticActionOut() {}
    virtual ~EaseQuinticActionOut() {}

private:
    DISALLOW_COPY_AND_ASSIGN(EaseQuinticActionOut);
};

/**
@class EaseQuinticActionInOut
@brief Ease Quintic InOut
@ingroup Actions
*/
class EaseQuinticActionInOut : public ActionEase
{
public:
    /**
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseQuinticActionInOut action. If creation failed, return nil.
    */
    static EaseQuinticActionInOut *create(ActionInterval *action);

    virtual void update(float time) override;
    virtual EaseQuinticActionInOut *clone() const override;
    virtual EaseQuinticActionInOut *reverse() const override;

public:
    EaseQuinticActionInOut() {}
    virtual ~EaseQuinticActionInOut() {}

private:
    DISALLOW_COPY_AND_ASSIGN(EaseQuinticActionInOut);
};

OFXACTIONS_NS_END

#endif // EASEQUINTIC_H
