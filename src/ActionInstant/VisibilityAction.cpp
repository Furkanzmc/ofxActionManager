#include "VisibilityAction.h"

//
// Show
//

Show *Show::create()
{
    Show *ret = new(std::nothrow) Show();
    return ret;
}

void Show::update(float time)
{
    (void)time;
    m_Target->setVisible(true);
}

ActionInstant *Show::reverse() const
{
    return Hide::create();
}

Show *Show::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) Show();
    return a;
}

//
// Hide
//
Hide *Hide::create()
{
    Hide *ret = new(std::nothrow) Hide();
    return ret;
}

void Hide::update(float time)
{
    (void)time;
    m_Target->setVisible(false);
}

ActionInstant *Hide::reverse() const
{
    return Show::create();
}

Hide *Hide::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) Hide();
    return a;
}

//
// ToggleVisibility
//
ToggleVisibility *ToggleVisibility::create()
{
    ToggleVisibility *ret = new(std::nothrow) ToggleVisibility();
    return ret;
}

void ToggleVisibility::update(float time)
{
    (void)time;
    m_Target->setVisible(!m_Target->isVisible());
}

ToggleVisibility *ToggleVisibility::reverse() const
{
    return ToggleVisibility::create();
}

ToggleVisibility *ToggleVisibility::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) ToggleVisibility();
    return a;
}
