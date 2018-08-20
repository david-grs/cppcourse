#include "application.h"

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

		case KeyEvent::KEY_ESCAPE:
			quit();
		case KeyEvent::KEY_SPACE: break;
	}
}

void Application::setup()
{
	const int width = (WindowSize.x - 2*Score.Font.getSize()) / SquareLength;
	const int height = (WindowSize.y - 2*Score.Font.getSize()) / SquareLength;
	const ci::ivec2 upperLeft{Score.Font.getSize(), Score.Font.getSize()};

	mCanvas = std::make_unique<GameCanvas>(upperLeft, width, height, SquareLength);
	mSnake = std::make_unique<Snake>(*mCanvas);
}

void Application::draw()
{
	ci::gl::clear();
	mCanvas->Clear();
	mSnake->Draw();

	ci::gl::drawString("Score: --", Score.Baseline, Score.Color, Score.Font);
}

void Application::update()
{
	auto dropped = mSnake->Move();
	if (dropped)
	{
		if (mSnake->Head() == mFruit)
		{
			mSnake->GrowTail(*dropped);
		}
	}
	else
	{
		mGameOver = true;
	}
}

CINDER_APP(Application, ci::app::RendererGl(ci::app::RendererGl::Options().msaa(16)), &Application::prepareSettings)

