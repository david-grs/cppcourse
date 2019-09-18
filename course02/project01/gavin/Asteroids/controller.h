#pragma once
#include <cinder/app/App.h>
#include <unordered_map>
class Controller {
public:
    void keyUp(ci::app::KeyEvent &event);
    void keyDown(ci::app::KeyEvent &event);
    bool held(char key) const;
private:
    std::unordered_map<char, bool> mKeyMap;
};


