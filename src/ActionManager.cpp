#include "ActionManager.h"
#include "uthash.h"
#include "ofLog.h"
#include "Array.h"
//OF Includes
#include "ofEvents.h"
#include "ofAppRunner.h"

//
// singleton stuff
//
ActionManager *ActionManager::m_Instance = nullptr;

typedef struct _hashElement {
    struct Array *actions;
    ActionTarget *target;
    int actionIndex;
    Action *currentAction;
    bool currentActionSalvaged;
    bool paused;
    UT_hash_handle hh;
} tHashElement;

ActionManager::ActionManager()
    : m_Targets(nullptr)
    , m_CurrentTarget(nullptr)
    , m_IsCurrentTargetSalvaged(false)
    , m_IsAutoUpdating(false)
{

}

ActionManager::~ActionManager()
{
    ofLogNotice("ofxActionManager") << ": Deallocing ActionManager";
    removeAllActions();
}

ActionManager *ActionManager::getInstance()
{
    if (m_Instance == nullptr) {
        m_Instance = new ActionManager();
    }

    return m_Instance;
}

void ActionManager::startAutoUpdate()
{

    if (!m_IsAutoUpdating) {
        m_IsAutoUpdating = true;
        ofAddListener(ofEvents().update, this, &ActionManager::autoUpdate);
    }
}

void ActionManager::stopAutoUpdate()
{
    if (m_IsAutoUpdating) {
        m_IsAutoUpdating = false;
        ofRemoveListener(ofEvents().update, this, &ActionManager::autoUpdate);
    }
}

// private

void ActionManager::deleteHashElement(tHashElement *element)
{
    ArrayFree(element->actions);
    HASH_DEL(m_Targets, element);
    free(element);
}

void ActionManager::actionAllocWithHashElement(tHashElement *element)
{
    // 4 actions per ActionTarget by default
    if (element->actions == nullptr) {
        element->actions = ArrayNew(4);
    }
    else if (element->actions->num == element->actions->max) {
        ArrayDoubleCapacity(element->actions);
    }
}

void ActionManager::removeActionAtIndex(std::size_t index, tHashElement *element)
{
    Action *action = (Action *)element->actions->arr[index];

    if (action == element->currentAction && (! element->currentActionSalvaged)) {
        element->currentActionSalvaged = true;
    }

    ArrayRemoveObjectAtIndex(element->actions, index, true);

    // update actionIndex in case we are in tick. looping over the actions
    if (element->actionIndex >= index) {
        element->actionIndex--;
    }

    if (element->actions->num == 0) {
        if (m_CurrentTarget == element) {
            m_IsCurrentTargetSalvaged = true;
        }
        else {
            deleteHashElement(element);
        }
    }
}

void ActionManager::autoUpdate(ofEventArgs &eventArgs)
{
    (void)eventArgs;

    update(ofGetLastFrameTime());
}

// pause / resume

void ActionManager::pauseTarget(ActionTarget *target)
{
    tHashElement *element = nullptr;
    HASH_FIND_PTR(m_Targets, &target, element);
    if (element) {
        element->paused = true;
    }
}

void ActionManager::resumeTarget(ActionTarget *target)
{
    tHashElement *element = nullptr;
    HASH_FIND_PTR(m_Targets, &target, element);
    if (element) {
        element->paused = false;
    }
}

std::vector<ActionTarget *> ActionManager::pauseAllRunningActions()
{
    std::vector<ActionTarget *> idsWithActions;

    for (tHashElement *element = m_Targets; element != nullptr; element = (tHashElement *)element->hh.next) {
        if (! element->paused) {
            element->paused = true;
            idsWithActions.push_back(element->target);
        }
    }

    return idsWithActions;
}

void ActionManager::resumeTargets(const std::vector<ActionTarget *> &targetsToResume)
{
    for (const auto &ActionTarget : targetsToResume) {
        this->resumeTarget(ActionTarget);
    }
}

void ActionManager::updateActions(const float &delta)
{
    if (m_IsAutoUpdating == false) {
        update(delta);
    }
}

// run

void ActionManager::addAction(Action *action, ActionTarget *target, bool paused)
{
    if (target == nullptr) {
        ofLogError("ofxActionManager") << __FUNCTION__ << ": target can't be nullptr!";
        return;
    }
    if (action == nullptr) {
        ofLogError("ofxActionManager") << __FUNCTION__ << ": action can't be nullptr!";
        return;
    }

    tHashElement *element = nullptr;
    // we should convert it to Ref*, because we save it as Ref*
    ActionTarget *tmp = target;
    HASH_FIND_PTR(m_Targets, &tmp, element);
    if (! element) {
        element = (tHashElement *)calloc(sizeof(*element), 1);
        element->paused = paused;
        element->target = target;
        HASH_ADD_PTR(m_Targets, target, element);
    }

    actionAllocWithHashElement(element);

    if (ArrayContainsObject(element->actions, action)) {
        ofLogError("ofxActionManager") << __FUNCTION__ << ": Action is already added";
        return;
    }

    ArrayAppendObject(element->actions, action);
    action->startWithTarget(target);
}

// remove

void ActionManager::removeAllActions()
{
    for (tHashElement *element = m_Targets; element != nullptr;) {
        auto target = element->target;
        element = (tHashElement *)element->hh.next;
        removeAllActionsFromTarget(target);
    }
}

void ActionManager::removeAllActionsFromTarget(ActionTarget *target)
{
    // explicit null handling
    if (target == nullptr) {
        return;
    }

    tHashElement *element = nullptr;
    HASH_FIND_PTR(m_Targets, &target, element);
    if (element) {
        if (ArrayContainsObject(element->actions, element->currentAction) && (! element->currentActionSalvaged)) {
            element->currentActionSalvaged = true;
        }

        ArrayRemoveAllObjects(element->actions);
        if (m_CurrentTarget == element) {
            m_IsCurrentTargetSalvaged = true;
        }
        else {
            deleteHashElement(element);
        }
    }
    else {
        ofLogNotice("ofxActionManager") << __FUNCTION__ << ": Target not found";
    }
}

void ActionManager::removeAction(Action *action)
{
    // explicit null handling
    if (action == nullptr) {
        return;
    }

    tHashElement *element = nullptr;
    ActionTarget *target = action->getOriginalTarget();
    HASH_FIND_PTR(m_Targets, &target, element);
    if (element) {
        auto i = ArrayGetIndexOfObject(element->actions, action);
        if (i != INVALID_INDEX) {
            removeActionAtIndex(i, element);
        }
    }
    else {
        ofLogNotice("ofxActionManager") << __FUNCTION__ << ": Target not found";
    }
}

void ActionManager::removeActionByTag(int tag, ActionTarget *target)
{
    if (tag == Action::INVALID_TAG) {
        ofLogError("ofxActionManager") << __FUNCTION__ << ": Invalid tag value.";
        return;
    }
    if (target == nullptr) {
        ofLogError("ofxActionManager") << __FUNCTION__ << ": target can't be nullptr!";
        return;
    }

    tHashElement *element = nullptr;
    HASH_FIND_PTR(m_Targets, &target, element);

    if (element) {
        auto limit = element->actions->num;
        for (int i = 0; i < limit; ++i) {
            Action *action = (Action *)element->actions->arr[i];

            if (action->getTag() == (int)tag && action->getOriginalTarget() == target) {
                removeActionAtIndex(i, element);
                break;
            }
        }
    }
}

void ActionManager::removeAllActionsByTag(int tag, ActionTarget *target)
{
    if (tag == Action::INVALID_TAG) {
        ofLogError("ofxActionManager") << __FUNCTION__ << ": Invalid tag value.";
        return;
    }
    if (target == nullptr) {
        ofLogError("ofxActionManager") << __FUNCTION__ << ": target can't be nullptr!";
        return;
    }

    tHashElement *element = nullptr;
    HASH_FIND_PTR(m_Targets, &target, element);

    if (element) {
        auto limit = element->actions->num;
        for (int i = 0; i < limit;) {
            Action *action = (Action *)element->actions->arr[i];

            if (action->getTag() == (int)tag && action->getOriginalTarget() == target) {
                removeActionAtIndex(i, element);
                --limit;
            }
            else {
                ++i;
            }
        }
    }
}

void ActionManager::removeActionsByFlags(unsigned int flags, ActionTarget *target)
{
    if (flags == 0) {
        return;
    }
    if (target == nullptr) {
        ofLogError("ofxActionManager") << __FUNCTION__ << ": Invalid tag value.";
        return;
    }

    tHashElement *element = nullptr;
    HASH_FIND_PTR(m_Targets, &target, element);

    if (element) {
        auto limit = element->actions->num;
        for (int i = 0; i < limit;) {
            Action *action = (Action *)element->actions->arr[i];

            if ((action->getFlags() & flags) != 0 && action->getOriginalTarget() == target) {
                removeActionAtIndex(i, element);
                --limit;
            }
            else {
                ++i;
            }
        }
    }
}

// get

// FIXME: Passing "const O *" instead of "const O&" because HASH_FIND_IT requires the address of a pointer
// and, it is not possible to get the address of a reference
Action *ActionManager::getActionByTag(int tag, const ActionTarget *target) const
{
    if (tag == Action::INVALID_TAG) {
        ofLogError("ofxActionManager") << __FUNCTION__ << ": Invalid tag value.";
        return nullptr;
    }

    tHashElement *element = nullptr;
    HASH_FIND_PTR(m_Targets, &target, element);

    if (element) {
        if (element->actions != nullptr) {
            auto limit = element->actions->num;
            for (int i = 0; i < limit; ++i) {
                Action *action = (Action *)element->actions->arr[i];

                if (action->getTag() == (int)tag) {
                    return action;
                }
            }
        }
        //CCLOG("cocos2d : getActionByTag(tag = %d): Action not found", tag);
    }
    else {
        // CCLOG("cocos2d : getActionByTag: Target not found");
    }

    return nullptr;
}

// FIXME: Passing "const O *" instead of "const O&" because HASH_FIND_IT requires the address of a pointer
// and, it is not possible to get the address of a reference
std::size_t ActionManager::getNumberOfRunningActionsInTarget(const ActionTarget *target) const
{
    tHashElement *element = nullptr;
    HASH_FIND_PTR(m_Targets, &target, element);
    if (element) {
        return element->actions ? element->actions->num : 0;
    }

    return 0;
}

// main loop
void ActionManager::update(float dt)
{
    for (tHashElement *elt = m_Targets; elt != nullptr;) {
        m_CurrentTarget = elt;
        m_IsCurrentTargetSalvaged = false;

        if (! m_CurrentTarget->paused) {
            // The 'actions' MutableArray may change while inside this loop.
            for (m_CurrentTarget->actionIndex = 0; m_CurrentTarget->actionIndex < m_CurrentTarget->actions->num;
                 m_CurrentTarget->actionIndex++) {
                m_CurrentTarget->currentAction = (Action *)m_CurrentTarget->actions->arr[m_CurrentTarget->actionIndex];
                if (m_CurrentTarget->currentAction == nullptr) {
                    continue;
                }

                m_CurrentTarget->currentActionSalvaged = false;

                m_CurrentTarget->currentAction->step(dt);

                if (m_CurrentTarget->currentActionSalvaged) {
                    // The currentAction told the ActionTarget to remove it. To prevent the action from
                    // accidentally deallocating itself before finishing its step, we retained
                    // it. Now that step is done, it's safe to release it.
                    m_CurrentTarget->currentAction->release();
                }
                else if (m_CurrentTarget->currentAction->isDone()) {
                    m_CurrentTarget->currentAction->stop();

                    Action *action = m_CurrentTarget->currentAction;
                    // Make currentAction nil to prevent removeAction from salvaging it.
                    m_CurrentTarget->currentAction = nullptr;
                    removeAction(action);
                }

                m_CurrentTarget->currentAction = nullptr;
            }
        }

        // elt, at this moment, is still valid
        // so it is safe to ask this here (issue #490)
        elt = (tHashElement *)(elt->hh.next);

        // only delete currentTarget if no actions were scheduled during the cycle (issue #481)
        if (m_IsCurrentTargetSalvaged && m_CurrentTarget->actions->num == 0) {
            deleteHashElement(m_CurrentTarget);
        }
    }

    // issue #635
    m_CurrentTarget = nullptr;
}
