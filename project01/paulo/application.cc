#include "application.h"

#include "game_status.h"
#include "apple.h"
#include "snake.h"
#include "game_canvas.h"

#include <cinder/gl/gl.h>

static const cinder::ivec2 WindowSize{640, 480};
static const int SquareLength = 10;

static const struct
{
	ci::ivec2 Baseline{0, SquareLength/2};
	ci::Color Color{ci::Color::white()};
	ci::Font Font{"Courier", 2 * SquareLength};
} Score;

Application::Application()
{}

void Application::prepareSettings(Settings* settings)
{
	settings->setWindowSize(WindowSize);
	settings->setFrameRate(10.0f);
	settings->setResizable(false);
	settings->setFullScreen(false);
}

void Application::keyDown(ci::app::KeyEvent event)
{
	using ci::app::KeyEvent;

	mStatus->OnAction();

	switch (event.getCode())
	{
		case KeyEvent::KEY_UP:
			mSnake->SetDirection(Direction::Up);
			break;
		case KeyEvent::KEY_DOWN:
			mSnake->SetDirection(Direction::Down);
			break;
		case KeyEvent::KEY_RIGHT:
			mSnake->SetDirection(Direction::Right);
			break;
		case KeyEvent::KEY_LEFT:
			mSnake->SetDirection(Direction::Left);
			break;
		case KeyEvent::KEY_SPACE:
			if (mStatus->Reset())
			{
				ReinitializeGame();
			}
			break;
		case KeyEvent::KEY_ESCAPE:
			quit();
	}
}

void Application::setup()
{
	const int maxScore = ReinitializeGame();
	mStatus = std::make_unique<GameStatus>(maxScore);
}

int Application::ReinitializeGame()
{
	const int width = (WindowSize.x - 2*Score.Font.getSize()) / SquareLength;
	const int height = (WindowSize.y - 2*Score.Font.getSize()) / SquareLength;
	const ci::ivec2 upperLeft{Score.Font.getSize(), Score.Font.getSize()};

	mSnake = nullptr;
	mApple = nullptr;

	mCanvas = std::make_unique<GameCanvas>(upperLeft, width, height, SquareLength);
	mSnake = std::make_unique<Snake>(*mCanvas);
	mApple = std::make_unique<Apple>(*mCanvas);

	return width * height - 1;
}

void Application::draw()
{
	ci::gl::clear();

	switch (mStatus->GetState())
	{
	case GameStatus::State::ReadyToStart:
	case GameStatus::State::InProgress:
		mCanvas->Clear();
		mSnake->Draw();
		mApple->Draw();
		break;
	case GameStatus::State::Finished:
		mCanvas->ShowMessage(
				"Well done! You got the maximum score. Press 'space' to play again...",
				ci::Color::hex(0x13B72E));
		break;
	case GameStatus::State::GameOver:
		mCanvas->ShowMessage(
				"Game over! Press 'space' to play again...",
				ci::Color::hex(0xF9473B));
		break;
	}

	ci::gl::drawString(mStatus->GetScoreToDisplay(), Score.Baseline, Score.Color, Score.Font);
}

void Application::update()
{
	if (!mStatus->IsInProgress())
		return;

	auto oldTail = mSnake->Move();
	if (oldTail)
	{
		if (mSnake->Head() == mApple->Location())
		{
			mSnake->GrowTail(*oldTail);
			mStatus->IncreaseScore();
			mApple = mStatus->IsInProgress() ? std::make_unique<Apple>(*mCanvas) : nullptr;
		}
	}
	else
	{
		mStatus->SetOver();
	}
}

CINDER_APP(Application, ci::app::RendererGl(ci::app::RendererGl::Options().msaa(16)), &Application::prepareSettings)

