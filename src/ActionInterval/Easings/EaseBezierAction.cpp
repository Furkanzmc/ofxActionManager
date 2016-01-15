#include "EaseBezierAction.h"

EaseBezierAction *EaseBezierAction::create(ActionInterval *action)
{
    EaseBezierAction *ret = new(std::nothrow) EaseBezierAction();
    if (ret) {
        if (ret->initWithAction(action) == false) {
            SAFE_RELEASE(ret);
        }
    }

    return ret;
}

void EaseBezierAction::setBezierParamer(float p0, float p1, float p2, float p3)
{
    m_P0 = p0;
    m_P1 = p1;
    m_P2 = p2;
    m_P3 = p3;
}

EaseBezierAction *EaseBezierAction::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) EaseBezierAction();
    a->initWithAction(m_Inner->clone());
    a->setBezierParamer(m_P0, m_P1, m_P2, m_P3);
    return a;
}

void EaseBezierAction::update(float time)
{
    m_Inner->update(tweenfunc::bezieratFunction(m_P0, m_P1, m_P2, m_P3, time));
}

EaseBezierAction *EaseBezierAction::reverse() const
{
    EaseBezierAction *reverseAction = EaseBezierAction::create(m_Inner->reverse());
    reverseAction->setBezierParamer(m_P3, m_P2, m_P1, m_P0);
    return reverseAction;
}
