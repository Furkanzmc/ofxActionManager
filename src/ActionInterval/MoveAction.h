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

#ifndef MOVEBY_H
#define MOVEBY_H
#include "ActionInterval.h"

OFXACTIONS_NS_BEGIN

/** @class MoveBy
 * @brief Moves a Node object x,y pixels by modifying it's position attribute.
 x and y are relative to the position of the object.
 Several MoveBy actions can be concurrently called, and the resulting
 movement will be the sum of individual movements.
 */
class MoveBy : public ActionInterval
{
public:
    /**
     * Creates the action.
     *
     * @param duration Duration time, in seconds.
     * @param deltaPosition The delta distance in 2d, it's a ofVec2f type.
     * @return A MoveBy object.
     */
    static MoveBy *create(float duration, const ofVec2f &deltaPosition);

    /**
     * Creates the action.
     *
     * @param duration Duration time, in seconds.
     * @param deltaPosition The delta distance in 3d, it's a ofVec3f type.
     * @return A MoveBy object.
     */
    static MoveBy *create(float duration, const ofVec3f &deltaPosition);

    //
    // Overrides
    //
    virtual MoveBy *clone() const override;
    virtual MoveBy *reverse(void) const  override;
    virtual void startWithTarget(ActionTarget *target) override;

    /**
     * @param time in seconds
     */
    virtual void update(float time) override;

public:
    MoveBy();
    virtual ~MoveBy() {}

    /** initializes the action */
    bool initWithDuration(float duration, const ofVec2f &deltaPosition);
    bool initWithDuration(float duration, const ofVec3f &deltaPosition);

    const ofVec3f &getDeltaPosition() const;

protected:
    ofVec3f m_PositionDelta;
    ofVec3f m_StartPosition;
    ofVec3f m_PreviousPosition;

private:
    DISALLOW_COPY_AND_ASSIGN(MoveBy);
};

// MoveTo

/** @class MoveTo
 * @brief Moves a Node object to the position x,y. x and y are absolute coordinates by modifying it's position attribute.
 Several MoveTo actions can be concurrently called, and the resulting
 movement will be the sum of individual movements.
 */
class MoveTo : public MoveBy
{
public:
    /**
     * Creates the action.
     * @param duration Duration time, in seconds.
     * @param position The destination position in 2d.
     * @return A MoveTo object.
     */
    static MoveTo *create(float duration, const ofVec2f &position);

    /**
     * Creates the action.
     * @param duration Duration time, in seconds.
     * @param position The destination position in 3d.
     * @return A MoveTo object.
     */
    static MoveTo *create(float duration, const ofVec3f &position);

    //
    // Overrides
    //
    virtual MoveTo *clone() const override;
    virtual MoveTo *reverse() const  override;
    virtual void startWithTarget(ActionTarget *target) override;

    const ofVec3f getTargetPosition() const;

public:
    MoveTo();
    virtual ~MoveTo() {}

    /**
     * initializes the action
     * @param duration in seconds
     */
    bool initWithDuration(float duration, const ofVec2f &position);

    /**
     * initializes the action
     * @param duration in seconds
     */
    bool initWithDuration(float duration, const ofVec3f &position);

protected:
    ofVec3f m_EndPosition;

private:
    DISALLOW_COPY_AND_ASSIGN(MoveTo);
};

OFXACTIONS_NS_END

#endif // MOVEBY_H
