#include "application.h"

static const cinder::ivec2 WindowSize{640, 480};

Application::Application()
{}

void Application::prepareSettings(Settings* settings)
{
	settings->setWindowSize(WindowSize);
	settings->setFrameRate(35.0f);
	settings->setResizable(false);
	settings->setFullScreen(false);
}

void Application::keyDown(ci::app::KeyEvent)
{}

void Application::setup()
{}

void Application::draw()
{}

void Application::update()
{}

CINDER_APP(Application, ci::app::RendererGl(ci::app::RendererGl::Options().msaa(16)), &Application::prepareSettings)

