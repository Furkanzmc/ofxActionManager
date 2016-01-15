#include "EaseSineOut.h"
#include "EaseSineIn.h"

EaseSineOut *EaseSineOut::create(ActionInterval *action)
{
    EaseSineOut *ret = new(std::nothrow) EaseSineOut();
    if (ret) {
        if (ret->initWithAction(action) == false) {
            SAFE_RELEASE(ret);
        }
    }

    return ret;
}

EaseSineOut *EaseSineOut::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) EaseSineOut();
    a->initWithAction(m_Inner->clone());

    return a;
}

void EaseSineOut::update(float time)
{
    m_Inner->update(tweenfunc::sineEaseOut(time));
}

ActionEase *EaseSineOut::reverse(void) const
{
    return EaseSineIn::create(m_Inner->reverse());
}
