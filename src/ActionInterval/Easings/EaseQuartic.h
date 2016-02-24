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

#ifndef EASEQUARTIC_H
#define EASEQUARTIC_H
#include "../ActionEase.h"

OFXACTIONS_NS_BEGIN

/**
@class EaseQuarticActionIn
@brief Ease Quartic In
@ingroup Actions
*/
class EaseQuarticActionIn : public ActionEase
{
public:
    /**
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseQuarticActionIn action. If creation failed, return nil.
    */
    static EaseQuarticActionIn *create(ActionInterval *action);

    virtual void update(float time) override;
    virtual EaseQuarticActionIn *clone() const override;
    virtual EaseQuarticActionIn *reverse() const override;

public:
    EaseQuarticActionIn() {}
    virtual ~EaseQuarticActionIn() {}

private:
    DISALLOW_COPY_AND_ASSIGN(EaseQuarticActionIn);
};

/**
@class EaseQuarticActionOut
@brief Ease Quartic Out
@ingroup Actions
*/
class EaseQuarticActionOut : public ActionEase
{
public:
    /**
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseQuarticActionOut action. If creation failed, return nil.
    */
    static EaseQuarticActionOut *create(ActionInterval *action);

    virtual void update(float time) override;
    virtual EaseQuarticActionOut *clone() const override;
    virtual EaseQuarticActionOut *reverse() const override;

public:
    EaseQuarticActionOut() {}
    virtual ~EaseQuarticActionOut() {}

private:
    DISALLOW_COPY_AND_ASSIGN(EaseQuarticActionOut);
};

/**
@class EaseQuarticActionInOut
@brief Ease Quartic InOut
@ingroup Actions
*/
class EaseQuarticActionInOut : public ActionEase
{
public:
    /**
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseQuarticActionInOut action. If creation failed, return nil.
    */
    static EaseQuarticActionInOut *create(ActionInterval *action);

    virtual void update(float time) override;
    virtual EaseQuarticActionInOut *clone() const override;
    virtual EaseQuarticActionInOut *reverse() const override;

public:
    EaseQuarticActionInOut() {}
    virtual ~EaseQuarticActionInOut() {}

private:
    DISALLOW_COPY_AND_ASSIGN(EaseQuarticActionInOut);
};

OFXACTIONS_NS_END

#endif // EASEQUARTIC_H
