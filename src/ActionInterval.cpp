#include "ActionInterval.h"
USING_NS_OFXACTIONS;

ActionInterval::ActionInterval()
    : m_Elapsed(0.f)
    , m_IsFirstTick(false)
{

}

bool ActionInterval::initWithDuration(float d)
{
    m_Duration = d;

    // prevent division by 0
    // This comparison could be in step:, but it might decrease the performance
    // by 3% in heavy based action games.
    if (m_Duration == 0) {
        m_Duration = FLT_EPSILON;
    }

    m_Elapsed = 0;
    m_IsFirstTick = true;

    return true;
}

bool ActionInterval::isDone() const
{
    return m_Elapsed >= m_Duration;
}

void ActionInterval::step(float dt)
{
    if (m_IsFirstTick) {
        m_IsFirstTick = false;
        m_Elapsed = 0;
    }
    else {
        m_Elapsed += dt;
    }


    float updateDt = MAX(0,                                   // needed for rewind. elapsed could be negative
                         MIN(1, m_Elapsed /
                             MAX(m_Duration, FLT_EPSILON)   // division by 0
                            )
                        );

    this->update(updateDt);
}

void ActionInterval::startWithTarget(ActionTarget *target)
{
    FiniteTimeAction::startWithTarget(target);
    m_Elapsed = 0.0f;
    m_IsFirstTick = true;
}

/* ----------- ExtraAction ----------- */

ExtraAction *ExtraAction::create()
{
    ExtraAction *ret = new(std::nothrow) ExtraAction();
    return ret;
}
ExtraAction *ExtraAction::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) ExtraAction();
    return a;
}

ExtraAction *ExtraAction::reverse() const
{
    return ExtraAction::create();
}

void ExtraAction::update(float time)
{
    (void)time;
}

void ExtraAction::step(float dt)
{
    (void)dt;
}
