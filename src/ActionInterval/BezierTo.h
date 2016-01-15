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

#ifndef BEZIERTO_H
#define BEZIERTO_H
#include "BezierBy.h"

/** @class BezierTo
 * @brief An action that moves the target with a cubic Bezier curve to a destination point.
 */
class BezierTo : public BezierBy
{
public:
    /** Creates the action with a duration and a bezier configuration.
     * @param t Duration time, in seconds.
     * @param c Bezier config.
     * @return An autoreleased BezierTo object.
     */
    static BezierTo *create(float t, const BezierConfig &c);

    //
    // Overrides
    //
    virtual void startWithTarget(ActionTarget *target) override;
    virtual BezierTo *clone() const override;
    virtual BezierTo *reverse(void) const override;

public:
    BezierTo();
    virtual ~BezierTo() {}

    /**
     * @param t In seconds.
     */
    bool initWithDuration(float t, const BezierConfig &c);

protected:
    BezierConfig m_ToConfig;

private:
    DISALLOW_COPY_AND_ASSIGN(BezierTo);
};
#endif // BEZIERTO_H
