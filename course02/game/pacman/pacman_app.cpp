#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
//#include "cinder/Log.h"
#include "cinder/gl/gl.h"

#include "game_controller.h"

using namespace ci;
using namespace ci::app;

auto prepareSettings = [](App::Settings* settings)
{
	//log::makeLogger<log::LoggerFile>("pacman_app.log");
	settings->setWindowSize(Config::WINDOW_SIZE_X, Config::WINDOW_SIZE_Y);

#if defined( CINDER_COCOA_TOUCH )
	settings->setStatusBarEnabled(false); // FIXME: status bar is always visible?
#endif

#if defined( CINDER_MSW )
	settings->setConsoleWindowEnabled();
#endif
};

class PacmanApp : public App
{
public:
	void setup() override;
	void update() override;
	void draw() override;
	void keyDown(KeyEvent event) override;

private:
	Config mConfig;
	GameControllerPtr mGameController;
	bool mGameActive{ false };
};

void PacmanApp::setup()
{
	mGameController = std::make_unique<GameController>(mConfig);
	mGameController->Setup();
}

void PacmanApp::keyDown(KeyEvent event)
{	
	switch (event.getCode())
	{
	case KeyEvent::KEY_DOWN:
		mGameController->KeyDown(DOWN);
		break;
	case KeyEvent::KEY_UP:
		mGameController->KeyDown(UP);
		break;
	case KeyEvent::KEY_LEFT:
		mGameController->KeyDown(LEFT);
		break;
	case KeyEvent::KEY_RIGHT:
		mGameController->KeyDown(RIGHT);
		break;
	case KeyEvent::KEY_SPACE:
		mGameController->UpdateGameState(ACTIVE);
		break;
	case KeyEvent::KEY_ESCAPE:
		mGameController->UpdateGameState(PAUSED);
		break;
	default:
		break;
	}	
}

void PacmanApp::update()
{
	mGameController->Update(getElapsedSeconds());
}

void PacmanApp::draw()
{
	gl::clear(mConfig.BLACK);
	mGameController->Draw();
}

CINDER_APP(PacmanApp, RendererGl, prepareSettings)
