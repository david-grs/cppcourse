#include "controller.h"
using namespace ci::app;

void Controller::keyUp(KeyEvent &event)
{
    auto key = event.getChar();
    mKeyMap[key] = false;
}

void Controller::keyDown(KeyEvent &event)
{
    auto key = event.getChar();
    mKeyMap[key] = true;
}

bool Controller::held(const char key) const
{
    if(mKeyMap.find(key) != mKeyMap.end())
        return mKeyMap.at(key);
    return false;
}

