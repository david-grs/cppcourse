#ifndef VIEW_H
#define VIEW_H

#include "snake.h"
#include "bait.h"
#include <cinder/app/App.h>

class GameView
{
public:
    GameView(const cinder::ivec2&, const int);
    void Draw(const Snake&, const Bait&) const;
private:
    cinder::ivec2 mWindowSize;
    const int mSnakeBodyPartSize;
    const ci::Rectf mBodyPartRect;
};

#endif // VIEW_H
