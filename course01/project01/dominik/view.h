#ifndef VIEW_H
#define VIEW_H

#include "snake.h"
#include "bait.h"
#include <cinder/app/App.h>

class GameView
{
public:
    GameView(const cinder::ivec2& windowSize) : mWindowSize(windowSize) {}
    void Draw(const Snake&, const Bait&) const;
private:
    cinder::ivec2 mWindowSize;
};

#endif // VIEW_H
