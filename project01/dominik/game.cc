#include "game.h"

static const int REWARD_FOR_BAIT = 10;

Game::Game(const cinder::ivec2& screenSize, const int snakeBodyPartSize)
    : mFieldSize(screenSize),
      mSnake(mFieldSize, snakeBodyPartSize),
      mBait(mFieldSize),
      mState(GameState::running),
      mScore(0)
{}

void Game::Update()
{
    mSnake.Move();

    if (mSnake.HeadClashedWithBody() || mSnake.HeadOutsideField())
    {
        std::cout << "Head clashed with body or outside field!" << std::endl;
        mState = GameState::lost;
        return;
    }
    if (mSnake.DistanceHeadToVector(mBait.GetPosition()) < (mBait.GetRadius() + mSnake.GetSize())/2)
    {
        mScore += REWARD_FOR_BAIT;
        std::cout << "Snake ate bait. New score: " << mScore << std::endl;
        mSnake.Grow();

        if(mScore % 20 == 0)
        {
            mSnake.IncreaseSpeed();
            std::cout << "Increasing Speed" << std::endl;
        }

        do {
            mBait.PositionRandomly();
        } while(mSnake.ObjectClashedWithBody(mBait.GetPosition()));
    }
}

void Game::HandleInput(const int& keyCode)
{
    switch(keyCode)
    {
    case ci::app::KeyEvent::KEY_UP:
        mSnake.ChangeMovingDirection(SnakeMovingDirection::up);
        break;
    case ci::app::KeyEvent::KEY_DOWN:
        mSnake.ChangeMovingDirection(SnakeMovingDirection::down);
        break;
    case ci::app::KeyEvent::KEY_LEFT:
        mSnake.ChangeMovingDirection(SnakeMovingDirection::left);
        break;
    case ci::app::KeyEvent::KEY_RIGHT:
        mSnake.ChangeMovingDirection(SnakeMovingDirection::right);
        break;
    default:
        break;
    }
}
