#ifndef GAME_H
#define GAME_H

#include "bait.h"
#include "snake.h"
#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>

enum class GameState
{
    running, lost
};

class Game
{
public:
    Game(const cinder::ivec2&, const int);

    void Update();
    void HandleInput(const int&);

    Snake GetSnake() const { return mSnake; }
    Bait GetBait() const { return mBait; }
    GameState GetState() const { return mState;}
private:
    cinder::ivec2 mFieldSize;
    Snake mSnake;
    Bait mBait;
    GameState mState;
};

#endif // GAME_H
