#include "application.h"

#include <cinder/gl/gl.h>

using namespace ci;

static const ci::ivec2 WindowSize{1080, 300};

Application::Application()
: mSpaceImpact(WindowSize)
{
}

void Application::prepareSettings(Settings* settings)
{
	settings->setWindowSize(WindowSize);
	settings->setFrameRate(60.0f);
	settings->setResizable(false);
	settings->setFullScreen(false);
}

void Application::keyDown(KeyEvent event)
{
	if (event.getCode() == KeyEvent::KEY_SPACE)
		mStatus = Status::PLAYING;

	mSpaceImpact.KeyDown(event);
}

void Application::keyUp(KeyEvent event)
{
	mSpaceImpact.KeyUp(event);
}

void Application::setup()
{
	mSpaceImpact.Setup();
}

void Application::draw()
{
	switch (mStatus)
	{
	case Status::STARTUP:
		DrawStartupScreen();
		break;
	case Status::PLAYING:
		mSpaceImpact.Draw();
		break;
	case Status::LOST:
		// Ideally, I'd like to display something 
		// pretty here, but life's too short, I'll use
		// stdout and abort :)
		std::cout << "you lost" << std::endl;
		exit(-1);
	}
}

void Application::update()
{
	if (mStatus == Status::STARTUP)
		return;

	mStatus = mSpaceImpact.Update();
}

CINDER_APP(Application, ci::app::RendererGl(ci::app::RendererGl::Options().msaa(16)), &Application::prepareSettings)

