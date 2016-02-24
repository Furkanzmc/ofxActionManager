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

#ifndef EASEBOUNCE_H
#define EASEBOUNCE_H
#include "../ActionEase.h"

OFXACTIONS_NS_BEGIN

/**
 @class EaseBounce
 @brief EaseBounce abstract class.
 @ingroup Actions
*/
class EaseBounce : public ActionEase
{
public:

    // Overrides
    virtual EaseBounce *clone() const override;
    virtual EaseBounce *reverse() const override;

public:
    EaseBounce() {}
    virtual ~EaseBounce() {}

private:
    DISALLOW_COPY_AND_ASSIGN(EaseBounce);
};

/**
 @class EaseBounceIn
 @brief EaseBounceIn action.
 @warning This action doesn't use a bijective function.
          Actions like Sequence might have an unexpected result when used with this action.
 @ingroup Actions
*/
class EaseBounceIn : public EaseBounce
{
public:
    /**
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseBounceIn action. If creation failed, return nil.
    */
    static EaseBounceIn *create(ActionInterval *action);

    // Overrides
    virtual void update(float time) override;
    virtual EaseBounceIn *clone() const override;
    virtual EaseBounce *reverse() const override;

public:
    EaseBounceIn() {}
    virtual ~EaseBounceIn() {}

private:
    DISALLOW_COPY_AND_ASSIGN(EaseBounceIn);
};

/**
 @class EaseBounceOut
 @brief EaseBounceOut action.
 @warning This action doesn't use a bijective function.
          Actions like Sequence might have an unexpected result when used with this action.
 @ingroup Actions
 */
class EaseBounceOut : public EaseBounce
{
public:
    /**
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseBounceOut action. If creation failed, return nil.
    */
    static EaseBounceOut *create(ActionInterval *action);

    // Overrides
    virtual void update(float time) override;
    virtual EaseBounceOut *clone() const override;
    virtual EaseBounce *reverse() const override;

public:
    EaseBounceOut() {}
    virtual ~EaseBounceOut() {}

private:
    DISALLOW_COPY_AND_ASSIGN(EaseBounceOut);
};

/**
 @class EaseBounceInOut
 @brief EaseBounceInOut action.
 @warning This action doesn't use a bijective function.
          Actions like Sequence might have an unexpected result when used with this action.
 @ingroup Actions
 */
class EaseBounceInOut : public EaseBounce
{
public:
    /**
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseBounceInOut action. If creation failed, return nil.
    */
    static EaseBounceInOut *create(ActionInterval *action);

    // Overrides
    virtual void update(float time) override;
    virtual EaseBounceInOut *clone() const override;
    virtual EaseBounceInOut *reverse() const override;

public:
    EaseBounceInOut() {}
    virtual ~EaseBounceInOut() {}

private:
    DISALLOW_COPY_AND_ASSIGN(EaseBounceInOut);
};

OFXACTIONS_NS_END

#endif // EASEBOUNCE_H
