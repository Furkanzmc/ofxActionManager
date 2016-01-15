#include "DelayTime.h"

DelayTime::DelayTime()
{

}

DelayTime *DelayTime::create(float d)
{
    DelayTime *action = new(std::nothrow) DelayTime();

    action->initWithDuration(d);
    return action;
}

DelayTime *DelayTime::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) DelayTime();
    a->initWithDuration(m_Duration);
    return a;
}

void DelayTime::update(float time)
{
    (void)time;
    return;
}

DelayTime *DelayTime::reverse() const
{
    return DelayTime::create(m_Duration);
}
