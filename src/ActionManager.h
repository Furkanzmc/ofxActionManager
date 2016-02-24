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

#ifndef ACTIONMANAGER_H
#define ACTIONMANAGER_H
#include "Action.h"
class ofEventArgs;
struct _hashElement;

/** @class ActionManager
 @brief ActionManager is a singleton that manages all the actions.
 */
class ActionManager
{
public:
    ~ActionManager(void);

    static ActionManager *getInstance();

    void startAutoUpdate();
    void stopAutoUpdate();

    /** Adds an action with a target.
     If the target is already present, then the action will be added to the existing target.
     If the target is not present, a new instance of this target will be created either paused or not, and the action will be added to the newly created target.
     When the target is paused, the queued actions won't be 'ticked'.
     *
     * @param action    A certain action.
     * @param target    The target which need to be added an action.
     * @param paused    Is the target paused or not.
     */
    void addAction(ofxActions::Action *action, ActionTarget *target, bool paused);

    /** Removes all actions from all the targets.
     */
    void removeAllActions();

    /** Removes all actions from a certain target.
     All the actions that belongs to the target will be removed.
     *
     * @param target    A certain target.
     */
    void removeAllActionsFromTarget(ActionTarget *target);

    /** Removes an action given an action reference.
     *
     * @param action    A certain target.
     */
    void removeAction(ofxActions::Action *action);

    /** Removes an action given its tag and the target.
     *
     * @param tag       The action's tag.
     * @param target    A certain target.
     */
    void removeActionByTag(int tag, ActionTarget *target);

    /** Removes all actions given its tag and the target.
     *
     * @param tag       The actions' tag.
     * @param target    A certain target.
     */
    void removeAllActionsByTag(int tag, ActionTarget *target);

    /** Removes all actions matching at least one bit in flags and the target.
     *
     * @param flags     The flag field to match the actions' flags based on bitwise AND.
     * @param target    A certain target.
     */
    void removeActionsByFlags(unsigned int flags, ActionTarget *target);

    /** Gets an action given its tag an a target.
     *
     * @param tag       The action's tag.
     * @param target    A certain target.
     * @return  The Action the with the given tag.
     */
    ofxActions::Action *getActionByTag(int tag, const ActionTarget *target) const;

    /** Returns the numbers of actions that are running in a certain target.
     * Composable actions are counted as 1 action. Example:
     * - If you are running 1 Sequence of 7 actions, it will return 1.
     * - If you are running 7 Sequences of 2 actions, it will return 7.
     *
     * @param target    A certain target.
     * @return  The numbers of actions that are running in a certain target.
     */
    std::size_t getNumberOfRunningActionsInTarget(const ActionTarget *target) const;

    /** Pauses the target: all running actions and newly added actions will be paused.
     *
     * @param target    A certain target.
     */
    void pauseTarget(ActionTarget *target);

    /** Resumes the target. All queued actions will be resumed.
     *
     * @param target    A certain target.
     */
    void resumeTarget(ActionTarget *target);

    /** Pauses all running actions, returning a list of targets whose actions were paused.
     *
     * @return  A list of targets whose actions were paused.
     */
    std::vector<ActionTarget *> pauseAllRunningActions();

    /** Resume a set of targets (convenience function to reverse a pauseAllRunningActions call).
     *
     * @param targetsToResume   A set of targets need to be resumed.
     */
    void resumeTargets(const std::vector<ActionTarget *> &targetsToResume);

    void updateActions(const float &delta);

private:
    // declared in ActionManager
    ActionManager();

    void removeActionAtIndex(std::size_t index, struct _hashElement *element);
    void deleteHashElement(struct _hashElement *element);
    void actionAllocWithHashElement(struct _hashElement *element);

    void autoUpdate(ofEventArgs &eventArgs);

    /** Main loop of ActionManager.
     * @param dt    In seconds.
     */
    void update(float dt);

private:
    static ActionManager *m_Instance;
    struct _hashElement *m_Targets;
    struct _hashElement *m_CurrentTarget;
    bool m_IsCurrentTargetSalvaged, m_IsAutoUpdating;
};

#endif // ACTIONMANAGER_H
