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

#ifndef SEQUENCE_H
#define SEQUENCE_H
#include "ActionInterval.h"

OFXACTIONS_NS_BEGIN

/** @class Sequence
 * @brief Runs actions sequentially, one after another.
 */
class Sequence : public ActionInterval
{
public:
    /** Helper constructor to create an array of sequenceable actions.
     *
     * @return A Sequence object.
     */
    static Sequence *create(FiniteTimeAction *action1, ...);

    /** Helper constructor to create an array of sequenceable actions given an array.
     * @param arrayOfActions An array of sequenceable actions.
     * @return A Sequence object.
     */
    static Sequence *create(const std::vector<FiniteTimeAction *> &arrayOfActions);

    /** Helper constructor to create an array of sequence-able actions.
     *
     * @param action1 The first sequenceable action.
     * @param args The va_list variable.
     * @return A Sequence object.
     */
    static Sequence *createWithVariableList(FiniteTimeAction *action1, va_list args);

    /** Creates the action.
     * @param actionOne The first sequenceable action.
     * @param actionTwo The second sequenceable action.
     * @return A Sequence object.
     */
    static Sequence *createWithTwoActions(FiniteTimeAction *actionOne, FiniteTimeAction *actionTwo);

    //
    // Overrides
    //
    virtual Sequence *clone() const override;
    virtual Sequence *reverse() const override;
    virtual void startWithTarget(ActionTarget *target) override;
    virtual void stop(void) override;

    /**
     * @param t In seconds.
     */
    virtual void update(float t) override;

public:
    Sequence();
    virtual ~Sequence(void);

    /** initializes the action */
    bool initWithTwoActions(FiniteTimeAction *pActionOne, FiniteTimeAction *pActionTwo);

protected:
    FiniteTimeAction *m_Actions[2];
    float m_Split;
    int m_Last;

private:
    DISALLOW_COPY_AND_ASSIGN(Sequence);
};

OFXACTIONS_NS_END

#endif // SEQUENCE_H
