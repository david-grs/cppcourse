#include "application.h"

static const cinder::ivec2 WindowSize{640, 480};
static const int BodyPartSize = 15;

Application::Application() : mGame(WindowSize, BodyPartSize), mView(WindowSize, BodyPartSize)
{}

void Application::prepareSettings(Settings* settings)
{
	settings->setWindowSize(WindowSize);
	settings->setFrameRate(35.0f);
	settings->setResizable(false);
	settings->setFullScreen(false);
}

void Application::keyDown(ci::app::KeyEvent event)
{
    if(event.getCode() == ci::app::KeyEvent::KEY_ESCAPE)
    {
        quit();
    }
    mGame.HandleInput(event.getCode());
}

void Application::setup()
{}

void Application::draw()
{
    mView.Draw(mGame.GetSnake(), mGame.GetBait());
}

void Application::update()
{
    mGame.Update();
    if (mGame.GetState() == GameState::lost)
    {
        std::cout << "Game lost! Good bye!" << std::endl;
        quit();
    }
}

CINDER_APP(Application, ci::app::RendererGl(ci::app::RendererGl::Options().msaa(16)), &Application::prepareSettings)

