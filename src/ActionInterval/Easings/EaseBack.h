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

#ifndef EASEBACK_H
#define EASEBACK_H
#include "../ActionEase.h"

OFXACTIONS_NS_BEGIN

/**
 @class EaseBackIn
 @brief EaseBackIn action.
 @warning This action doesn't use a bijective function.
          Actions like Sequence might have an unexpected result when used with this action.
 @ingroup Actions
 */
class EaseBackIn : public ActionEase
{
public:
    /**
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseBackIn action. If creation failed, return nil.
    */
    static EaseBackIn *create(ActionInterval *action);

    // Overrides
    virtual void update(float time) override;
    virtual EaseBackIn *clone() const override;
    virtual ActionEase *reverse() const override;

public:
    EaseBackIn() {}
    virtual ~EaseBackIn() {}

private:
    DISALLOW_COPY_AND_ASSIGN(EaseBackIn);
};

/**
 @class EaseBackOut
 @brief EaseBackOut action.
 @warning This action doesn't use a bijective function.
          Actions like Sequence might have an unexpected result when used with this action.
 @ingroup Actions
 */
class EaseBackOut : public ActionEase
{
public:
    /**
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseBackOut action. If creation failed, return nil.
    */
    static EaseBackOut *create(ActionInterval *action);

    // Overrides
    virtual void update(float time) override;
    virtual EaseBackOut *clone() const override;
    virtual ActionEase *reverse() const override;

public:
    EaseBackOut() {}
    virtual ~EaseBackOut() {}

private:
    DISALLOW_COPY_AND_ASSIGN(EaseBackOut);
};

/**
 @class EaseBackInOut
 @brief EaseBackInOut action.
 @warning This action doesn't use a bijective function.
          Actions like Sequence might have an unexpected result when used with this action.
 @ingroup Actions
 */
class EaseBackInOut : public ActionEase
{
public:
    /**
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseBackInOut action. If creation failed, return nil.
    */
    static EaseBackInOut *create(ActionInterval *action);

    // Overrides
    virtual void update(float time) override;
    virtual EaseBackInOut *clone() const override;
    virtual EaseBackInOut *reverse() const override;

public:
    EaseBackInOut() {}
    virtual ~EaseBackInOut() {}

private:
    DISALLOW_COPY_AND_ASSIGN(EaseBackInOut);
};

OFXACTIONS_NS_END

#endif // EASEBACK_H
