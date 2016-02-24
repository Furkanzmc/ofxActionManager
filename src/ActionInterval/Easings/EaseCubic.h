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

#ifndef EASECUBIC_H
#define EASECUBIC_H
#include "../ActionEase.h"

OFXACTIONS_NS_BEGIN

/**
@class EaseCubicActionIn
@brief Ease Cubic In
@ingroup Actions
*/
class EaseCubicActionIn: public ActionEase
{
public:
    /**
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseCubicActionIn action. If creation failed, return nil.
    */
    static EaseCubicActionIn *create(ActionInterval *action);

    virtual void update(float time) override;
    virtual EaseCubicActionIn *clone() const override;
    virtual EaseCubicActionIn *reverse() const override;

public:
    EaseCubicActionIn() {}
    virtual ~EaseCubicActionIn() {}

private:
    DISALLOW_COPY_AND_ASSIGN(EaseCubicActionIn);
};

/**
@class EaseCubicActionOut
@brief Ease Cubic Out
@ingroup Actions
*/
class EaseCubicActionOut : public ActionEase
{
public:
    /**
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseCubicActionOut action. If creation failed, return nil.
    */
    static EaseCubicActionOut *create(ActionInterval *action);

    virtual void update(float time) override;
    virtual EaseCubicActionOut *clone() const override;
    virtual EaseCubicActionOut *reverse() const override;

public:
    EaseCubicActionOut() {}
    virtual ~EaseCubicActionOut() {}

private:
    DISALLOW_COPY_AND_ASSIGN(EaseCubicActionOut);
};

/**
@class EaseCubicActionInOut
@brief Ease Cubic InOut
@ingroup Actions
*/
class EaseCubicActionInOut : public ActionEase
{
public:
    /**
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseCubicActionInOut action. If creation failed, return nil.
    */
    static EaseCubicActionInOut *create(ActionInterval *action);

    virtual void update(float time) override;
    virtual EaseCubicActionInOut *clone() const override;
    virtual EaseCubicActionInOut *reverse() const override;

public:
    EaseCubicActionInOut() {}
    virtual ~EaseCubicActionInOut() {}

private:
    DISALLOW_COPY_AND_ASSIGN(EaseCubicActionInOut);
};

OFXACTIONS_NS_END

#endif // EASECUBIC_H
