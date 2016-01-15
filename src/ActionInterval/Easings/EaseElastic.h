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

#ifndef EASEELASTIC_H
#define EASEELASTIC_H
#include "../ActionEase.h"

/**
 @class EaseElastic
 @brief Ease Elastic abstract class
 @ingroup Actions
 */
class EaseElastic : public ActionEase
{
public:

    /**
     @brief Get period of the wave in radians. Default value is 0.3.
     @return Return the period of the wave in radians.
    */
    inline float getPeriod() const
    {
        return m_Period;
    }
    /**
     @brief Set period of the wave in radians.
     @param fPeriod The value will be set.
    */
    inline void setPeriod(float fPeriod)
    {
        m_Period = fPeriod;
    }

    //
    // Overrides
    //
    virtual EaseElastic *clone() const override;
    virtual EaseElastic *reverse() const override;

public:
    EaseElastic() {}
    virtual ~EaseElastic() {}
    /**
     @brief Initializes the action with the inner action and the period in radians.
     @param action The pointer of the inner action.
     @param period Period of the wave in radians. Default is 0.3.
     @return Return true when the initialization success, otherwise return false.
    */
    bool initWithAction(ActionInterval *action, float period = 0.3f);

protected:
    float m_Period;

private:
    DISALLOW_COPY_AND_ASSIGN(EaseElastic);
};

/**
 @class EaseElasticIn
 @brief Ease Elastic In action.
 @details If time == 0 or time == 1, the timeline of inner action will not be changed.
         Else, the timeline of inner action will be changed by:
         \f$-{ 2 }^{ 10*(time-1) }*sin((time-1-\frac { period }{ 4 } )*\pi *2/period)\f$.

 @warning This action doesn't use a bijective function.
          Actions like Sequence might have an unexpected result when used with this action.
 @ingroup Actions
 */
class EaseElasticIn : public EaseElastic
{
public:
    /**
     @brief Create the EaseElasticIn action with the inner action and the period in radians.
     @param action The pointer of the inner action.
     @param period Period of the wave in radians.
     @return A pointer of EaseElasticIn action. If creation failed, return nil.
    */
    static EaseElasticIn *create(ActionInterval *action, float period);

    /**
     @brief Create the EaseElasticIn action with the inner action and period value is 0.3.
     @param action The pointer of the inner action.
     @return A pointer of EaseElasticIn action. If creation failed, return nil.
    */
    static EaseElasticIn *create(ActionInterval *action);

    // Overrides
    virtual void update(float time) override;
    virtual EaseElasticIn *clone() const override;
    virtual EaseElastic *reverse() const override;

public:
    EaseElasticIn() {}
    virtual ~EaseElasticIn() {}

private:
    DISALLOW_COPY_AND_ASSIGN(EaseElasticIn);
};

/**
 @class EaseElasticOut
 @brief Ease Elastic Out action.
 @details If time == 0 or time == 1, the timeline of inner action will not be changed.
         Else, the timeline of inner action will be changed by:
         \f${ 2 }^{ -10*time }*sin((time-\frac { period }{ 4 } )*\pi *2/period)+1\f$.
 @warning This action doesn't use a bijective function.
          Actions like Sequence might have an unexpected result when used with this action.
 @ingroup Actions
 */
class EaseElasticOut : public EaseElastic
{
public:
    /**
     @brief Create the EaseElasticOut action with the inner action and the period in radians.
     @param action The pointer of the inner action.
     @param period Period of the wave in radians.
     @return A pointer of EaseElasticOut action. If creation failed, return nil.
    */
    static EaseElasticOut *create(ActionInterval *action, float period);

    /**
     @brief Create the EaseElasticOut action with the inner action and period value is 0.3.
     @param action The pointer of the inner action.
     @return A pointer of EaseElasticOut action. If creation failed, return nil.
    */
    static EaseElasticOut *create(ActionInterval *action);

    // Overrides
    virtual void update(float time) override;
    virtual EaseElasticOut *clone() const override;
    virtual EaseElastic *reverse() const override;

public:
    EaseElasticOut() {}
    virtual ~EaseElasticOut() {}

private:
    DISALLOW_COPY_AND_ASSIGN(EaseElasticOut);
};

/**
 @class EaseElasticInOut
 @brief Ease Elastic InOut action.
 @warning This action doesn't use a bijective function.
          Actions like Sequence might have an unexpected result when used with this action.
 @ingroup Actions
 */
class EaseElasticInOut : public EaseElastic
{
public:
    /**
     @brief Create the EaseElasticInOut action with the inner action and the period in radians.
     @param action The pointer of the inner action.
     @param period Period of the wave in radians.
     @return A pointer of EaseElasticInOut action. If creation failed, return nil.
    */
    static EaseElasticInOut *create(ActionInterval *action, float period);

    /**
     @brief Create the EaseElasticInOut action with the inner action and period value is 0.3.
     @param action The pointer of the inner action.
     @return A pointer of EaseElasticInOut action. If creation failed, return nil.
    */
    static EaseElasticInOut *create(ActionInterval *action);

    // Overrides
    virtual void update(float time) override;
    virtual EaseElasticInOut *clone() const override;
    virtual EaseElasticInOut *reverse() const override;

public:
    EaseElasticInOut() {}
    virtual ~EaseElasticInOut() {}

private:
    DISALLOW_COPY_AND_ASSIGN(EaseElasticInOut);
};

#endif // EASEELASTIC_H
