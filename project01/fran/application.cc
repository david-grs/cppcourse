#include "application.h"

static const cinder::ivec2 WindowSize{800, 600};

Application::Application():
		mSnake(STARTING_LENGTH, ELEMENT_RADIUS),
		mFood(ELEMENT_RADIUS)
{}

void Application::prepareSettings(Settings* settings)
{
	settings->setWindowSize(WindowSize);
	settings->setFrameRate(15.0f);
	settings->setResizable(false);
	settings->setFullScreen(false);
}

void Application::keyDown(ci::app::KeyEvent keyEvent)
{
	switch (keyEvent.getCode())
	{
		case keyEvent.KEY_UP:
		{
			ChangeDirectionUp();
			break;
		}
		case keyEvent.KEY_DOWN:
		{
			ChangeDirectionDown();
			break;
		}
		case keyEvent.KEY_LEFT:
		{
			ChangeDirectionLeft();
			break;
		}
		case keyEvent.KEY_RIGHT:
		{
			ChangeDirectionRight();
			break;
		}
		case keyEvent.KEY_RETURN:
		{
			if (keyEvent.isAltDown())
			{
				mDisplayString = FULL_SCREEN_MESSAGE;
				cinder::app::setFullScreen(true);
			}
			if (mGameOver)
			{
				StartNewGame();
			}
			break;
		}
		case keyEvent.KEY_ESCAPE:
		{
			if (isFullScreen())
			{
				setFullScreen(false);
				mDisplayString = GAME_TITLE;
			}
			else
			{
				quit();
			}
			break;
		}
		case keyEvent.KEY_F11:
		{
			setFullScreen(!isFullScreen());
			mDisplayString = isFullScreen() ? FULL_SCREEN_MESSAGE : "SNAKE";
			break;
		}
	}
}

void Application::setup()
{
	mTextureFontRef = cinder::gl::TextureFont::create( cinder::Font("Times New Roman", 24) );
	mSnake.SetInitialPosition(getWindowWidth(), getWindowHeight());
	mFood.Respawn(getWindowWidth(), getWindowHeight());
}

void Application::draw()
{
	cinder::gl::clear();

	cinder::gl::setMatricesWindow( cinder::app::getWindowSize() );
	cinder::gl::enableAlphaBlending();

	mFood.Draw();

	mSnake.Draw();

	cinder::gl::color(cinder::Color(0.9f, 1.0f, 1.0f));
	auto renderSize = mTextureFontRef->measureString(mDisplayString);
	mTextureFontRef->drawString(mDisplayString, cinder::vec2( getWindowWidth() - renderSize.x - 10, getWindowHeight() - mTextureFontRef->getDescent()));

	//cinder::gl::color(cinder::Color(1.0f, 0.0f, 0.0f));
	//cinder::gl::drawStrokedCircle(mFood.GetOffsetPosition(), ELEMENT_RADIUS); // debug collision detection
}

void Application::update()
{
	if (mGameOver)
	{
		mDisplayString = "GAME OVER (hit enter to begin again)";
	}

	else
	{

		mFood.Update(getElapsedSeconds());

		mSnake.Update();

		if (mSnake.HeadIsCollidingWith(mFood.GetPosition()))
		{
			++mSnake;
			mFood.Respawn(getWindowWidth(), getWindowHeight());
		}

		mDisplayString = "Score: " + std::to_string(mSnake.GetLength() - STARTING_LENGTH + 1);
		mGameOver = mSnake.IsCollidingWithWindow(getWindowWidth(), getWindowHeight()) || mSnake.HeadIsCollidingWithSelf();
	}
}

void Application::ChangeDirectionUp()
{
	if (mDirectionOffset != DOWN_OFFSET)
	{
		mDirectionOffset = UP_OFFSET;
	}

	mSnake.SetDirection(mDirectionOffset);
}
void Application::ChangeDirectionDown()
{
	if (mDirectionOffset != UP_OFFSET)
	{
		mDirectionOffset = DOWN_OFFSET;
	}

	mSnake.SetDirection(mDirectionOffset);
}
void Application::ChangeDirectionLeft()
{
	if (mDirectionOffset != RIGHT_OFFSET)
	{
		mDirectionOffset = LEFT_OFFSET;
	}

	mSnake.SetDirection(mDirectionOffset);
}
void Application::ChangeDirectionRight()
{
	if (mDirectionOffset != LEFT_OFFSET)
	{
		mDirectionOffset = RIGHT_OFFSET;
	}

	mSnake.SetDirection(mDirectionOffset);
}

const cinder::vec2& Application::GetSafeStartingDirection(const cinder::vec2& startingPosition)
{
	float verticalMidpoint = getWindowWidth() / 2;
	float horizontalMidpoint = getWindowHeight() / 2;

	if (startingPosition.x > verticalMidpoint && startingPosition.y > horizontalMidpoint)
	{
		return startingPosition.x < startingPosition.y ? LEFT_OFFSET : UP_OFFSET;
	}

	if (startingPosition.x <= verticalMidpoint && startingPosition.y > horizontalMidpoint)
	{
		return startingPosition.x < startingPosition.y ? RIGHT_OFFSET : UP_OFFSET;
	}

	if (startingPosition.x > verticalMidpoint && startingPosition.y <= horizontalMidpoint)
	{
		return startingPosition.x < startingPosition.y ? LEFT_OFFSET : DOWN_OFFSET;
	}

	return startingPosition.x < startingPosition.y ? RIGHT_OFFSET : DOWN_OFFSET;
}

void Application::StartNewGame()
{
	mSnake = Snake(STARTING_LENGTH, ELEMENT_RADIUS);
	mSnake.SetInitialPosition(getWindowWidth(), getWindowHeight());
	mSnake.SetDirection(GetSafeStartingDirection(mSnake.GetHeadPosition()));
	mFood.Respawn(getWindowWidth(), getWindowHeight());
	mGameOver = false;
}

CINDER_APP(Application, ci::app::RendererGl(ci::app::RendererGl::Options().msaa(16)), &Application::prepareSettings)

