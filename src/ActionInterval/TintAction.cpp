#include "TintAction.h"
#include "ofLog.h"
USING_NS_OFXACTIONS;

//
// TintTo
//
TintTo *TintTo::create(float duration, GLubyte red, GLubyte green, GLubyte blue)
{
    TintTo *tintTo = new(std::nothrow) TintTo();
    tintTo->initWithDuration(duration, red, green, blue);

    return tintTo;
}

TintTo *TintTo::create(float duration, const ofColor &color)
{
    return create(duration, color.r, color.g, color.b);
}

bool TintTo::initWithDuration(float duration, GLubyte red, GLubyte green, GLubyte blue)
{
    if (ActionInterval::initWithDuration(duration)) {
        m_To = ofColor(red, green, blue);
        return true;
    }

    return false;
}

TintTo *TintTo::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) TintTo();
    a->initWithDuration(m_Duration, m_To.r, m_To.g, m_To.b);

    return a;
}

TintTo *TintTo::reverse() const
{
    ofLogError("ofxActionManager") << __FUNCTION__ << ": reverse() not supported in TintTo";
    return nullptr;
}

void TintTo::startWithTarget(ActionTarget *target)
{
    ActionInterval::startWithTarget(target);
    if (m_Target) {
        m_From = m_Target->getColor();
    }
    /*_from = target->getColor();*/
}

void TintTo::update(float time)
{
    if (m_Target) {
        m_Target->setColor(ofColor(GLubyte(m_From.r + (m_To.r - m_From.r) * time),
                                   (GLubyte)(m_From.g + (m_To.g - m_From.g) * time),
                                   (GLubyte)(m_From.b + (m_To.b - m_From.b) * time)));
    }
}

//
// TintBy
//

TintBy *TintBy::create(float duration, GLshort deltaRed, GLshort deltaGreen, GLshort deltaBlue)
{
    TintBy *tintBy = new(std::nothrow) TintBy();
    tintBy->initWithDuration(duration, deltaRed, deltaGreen, deltaBlue);

    return tintBy;
}

bool TintBy::initWithDuration(float duration, GLshort deltaRed, GLshort deltaGreen, GLshort deltaBlue)
{
    if (ActionInterval::initWithDuration(duration)) {
        m_DeltaR = deltaRed;
        m_DeltaG = deltaGreen;
        m_DeltaB = deltaBlue;

        return true;
    }

    return false;
}

TintBy *TintBy::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) TintBy();
    a->initWithDuration(m_Duration, m_DeltaR, m_DeltaG, m_DeltaB);

    return a;
}

void TintBy::startWithTarget(ActionTarget *target)
{
    ActionInterval::startWithTarget(target);

    if (target) {
        ofColor color = target->getColor();
        m_FromR = color.r;
        m_FromG = color.g;
        m_FromB = color.b;
    }
}

void TintBy::update(float time)
{
    if (m_Target) {
        m_Target->setColor(ofColor((GLubyte)(m_FromR + m_DeltaR * time),
                                   (GLubyte)(m_FromG + m_DeltaG * time),
                                   (GLubyte)(m_FromB + m_DeltaB * time)));
    }
}

TintBy *TintBy::reverse() const
{
    return TintBy::create(m_Duration, -m_DeltaR, -m_DeltaG, -m_DeltaB);
}
