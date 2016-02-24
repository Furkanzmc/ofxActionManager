#include "CallFunc.h"
USING_NS_OFXACTIONS;

//
// CallFunc
//

CallFunc *CallFunc::create(const std::function<void()> &func)
{
    CallFunc *ret = new(std::nothrow) CallFunc();

    if ((ret && ret->initWithFunction(func)) == false) {
        SAFE_RELEASE(ret);
    }
    return ret;
}

bool CallFunc::initWithFunction(const std::function<void()> &func)
{
    m_Function = func;
    return true;
}


CallFunc::~CallFunc()
{

}

CallFunc *CallFunc::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) CallFunc();
    if (m_Function) {
        a->initWithFunction(m_Function);
        return a;
    }

    SAFE_RELEASE(a);
    return a;
}

CallFunc *CallFunc::reverse() const
{
    // no reverse here, just return a clone
    return this->clone();
}

void CallFunc::update(float time)
{
    (void)time;
    this->execute();
}

void CallFunc::execute()
{
    if (m_Function) {
        m_Function();
    }
}

//
// CallFuncN
//

CallFuncN *CallFuncN::create(const std::function<void(ActionTarget *)> &func)
{
    CallFuncN *ret = new(std::nothrow) CallFuncN();

    if ((ret && ret->initWithFunction(func)) == false) {
        SAFE_RELEASE(ret);
    }
    return ret;
}

bool CallFuncN::initWithFunction(const std::function<void(ActionTarget *)> &func)
{
    m_Function = func;
    return true;
}


CallFuncN::~CallFuncN()
{

}

CallFuncN *CallFuncN::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) CallFuncN();
    if (m_Function) {
        a->initWithFunction(m_Function);
        return a;
    }

    SAFE_RELEASE(a);
    return a;
}

CallFuncN *CallFuncN::reverse() const
{
    // no reverse here, just return a clone
    return this->clone();
}

void CallFuncN::update(float time)
{
    (void)time;
    this->execute();
}

void CallFuncN::execute()
{
    if (m_Function) {
        m_Function(m_Target);
    }
}
