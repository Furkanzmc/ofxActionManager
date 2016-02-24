#include "Sequence.h"
#include "ofLog.h"

Sequence::Sequence()
{

}

Sequence *Sequence::createWithTwoActions(FiniteTimeAction *actionOne, FiniteTimeAction *actionTwo)
{
    Sequence *sequence = new(std::nothrow) Sequence();
    if (sequence) {
        sequence->initWithTwoActions(actionOne, actionTwo);
    }
    return sequence;
}

Sequence *Sequence::create(FiniteTimeAction *action1, ...)
{
    va_list params;
    va_start(params, action1);

    Sequence *ret = Sequence::createWithVariableList(action1, params);

    va_end(params);

    return ret;
}

Sequence *Sequence::createWithVariableList(FiniteTimeAction *action1, va_list args)
{
    FiniteTimeAction *now;
    FiniteTimeAction *prev = action1;
    bool bOneAction = true;

    while (action1) {
        now = va_arg(args, FiniteTimeAction *);
        if (now) {
            prev = createWithTwoActions(prev, now);
            bOneAction = false;
        }
        else {
            // If only one action is added to Sequence, make up a Sequence by adding a simplest finite time action.
            if (bOneAction) {
                prev = createWithTwoActions(prev, ExtraAction::create());
            }
            break;
        }
    }

    return ((Sequence *)prev);
}

Sequence *Sequence::create(const std::vector<FiniteTimeAction *> &arrayOfActions)
{
    Sequence *ret = nullptr;
    do {
        auto count = arrayOfActions.size();
        if (count == 0) {
            break;
        }

        auto prev = arrayOfActions.at(0);

        if (count > 1) {
            for (int i = 1; i < count; ++i) {
                prev = createWithTwoActions(prev, arrayOfActions.at(i));
            }
        }
        else {
            // If only one action is added to Sequence, make up a Sequence by adding a simplest finite time action.
            prev = createWithTwoActions(prev, ExtraAction::create());
        }
        ret = static_cast<Sequence *>(prev);
    }
    while (0);
    return ret;
}

bool Sequence::initWithTwoActions(FiniteTimeAction *actionOne, FiniteTimeAction *actionTwo)
{
    if (actionOne == nullptr) {
        ofLogError("ofxActionManager::Sequence") << __FUNCTION__ << "actionOne can't be nullptr!";
        return false;
    }
    if (actionTwo == nullptr) {
        ofLogError("ofxActionManager::Sequence") << __FUNCTION__ << "actionTwo can't be nullptr!";
        return false;
    }

    float d = actionOne->getDuration() + actionTwo->getDuration();
    ActionInterval::initWithDuration(d);

    m_Actions[0] = actionOne;
    actionOne->retain();
    m_Actions[1] = actionTwo;
    actionTwo->retain();

    return true;
}

Sequence *Sequence::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) Sequence();
    a->initWithTwoActions(m_Actions[0]->clone(), m_Actions[1]->clone());
    return a;
}

Sequence::~Sequence(void)
{
    SAFE_RELEASE(m_Actions[0]);
    SAFE_RELEASE(m_Actions[1]);
}

void Sequence::startWithTarget(ActionTarget *target)
{
    ActionInterval::startWithTarget(target);
    m_Split = m_Actions[0]->getDuration() / m_Duration;
    m_Last = -1;
}

void Sequence::stop(void)
{
    if (m_Last != - 1) {
        m_Actions[m_Last]->stop();
    }

    ActionInterval::stop();
}

void Sequence::update(float t)
{
    int found = 0;
    float new_t = 0.0f;

    if (t < m_Split) {
        // action[0]
        found = 0;
        if (m_Split != 0)
            new_t = t / m_Split;
        else
            new_t = 1;

    }
    else {
        // action[1]
        found = 1;
        if (m_Split == 1)
            new_t = 1;
        else
            new_t = (t - m_Split) / (1 - m_Split);
    }

    if (found == 1) {

        if (m_Last == -1) {
            // action[0] was skipped, execute it.
            m_Actions[0]->startWithTarget(m_Target);
            m_Actions[0]->update(1.0f);
            m_Actions[0]->stop();
        }
        else if (m_Last == 0) {
            m_Actions[0]->update(1.0f);
            m_Actions[0]->stop();
        }
    }
    else if (found == 0 && m_Last == 1) {
        m_Actions[1]->update(0.0f);
        m_Actions[1]->stop();
    }
    // Last action found and it is done.
    if (found == m_Last && m_Actions[found]->isDone()) {
        return;
    }

    // Last action found and it is done
    if (found != m_Last) {
        m_Actions[found]->startWithTarget(m_Target);
    }
    m_Actions[found]->update(new_t);
    m_Last = found;
}

Sequence *Sequence::reverse() const
{
    return Sequence::createWithTwoActions(m_Actions[1]->reverse(), m_Actions[0]->reverse());
}
