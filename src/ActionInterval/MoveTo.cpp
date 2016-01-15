#include "MoveTo.h"
#include "ofLog.h"

MoveTo::MoveTo()
{

}

MoveTo *MoveTo::create(float duration, const ofVec2f &position)
{
    return MoveTo::create(duration, ofVec3f(position.x, position.y, 0));
}

MoveTo *MoveTo::create(float duration, const ofVec3f &position)
{
    MoveTo *ret = new(std::nothrow) MoveTo();

    if (ret) {
        if (ret->initWithDuration(duration, position)) {
        }
        else {
            delete ret;
            ret = nullptr;
        }
    }

    return ret;
}

bool MoveTo::initWithDuration(float duration, const ofVec2f &position)
{
    return initWithDuration(duration, ofVec3f(position.x, position.y, 0));
}

bool MoveTo::initWithDuration(float duration, const ofVec3f &position)
{
    bool ret = false;

    if (ActionInterval::initWithDuration(duration)) {
        m_EndPosition = position;
        ret = true;
    }

    return ret;
}

MoveTo *MoveTo::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) MoveTo();
    a->initWithDuration(m_Duration, m_EndPosition);
    return a;
}

void MoveTo::startWithTarget(ActionTarget *target)
{
    MoveBy::startWithTarget(target);
    m_PositionDelta = m_EndPosition - target->getPositon();
}

MoveTo *MoveTo::reverse() const
{
    ofLogWarning("ofxActionManager") << __FUNCTION__ << ": MoveTo doesn't support reverse.";
    return nullptr;
}
