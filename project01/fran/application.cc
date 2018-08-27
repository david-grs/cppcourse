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
                mSnake = Snake(STARTING_LENGTH, ELEMENT_RADIUS);
                mSnake.SetInitialPosition(getWindowWidth(), getWindowHeight());
                mFood.Respawn(getWindowWidth(), getWindowHeight());
                mDisplayString = GAME_TITLE;
                mGameOver = false;
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

    //cinder::gl::color( cinder::ColorA( 1, 0.8f, 0.25f, 1.0f ) );

	cinder::gl::color(cinder::Color(0.9f, 1.0f, 1.0f));
    auto renderSize = mTextureFontRef->measureString(mDisplayString);
    mTextureFontRef->drawString(mDisplayString, cinder::vec2( getWindowWidth() - renderSize.x - 10, getWindowHeight() - mTextureFontRef->getDescent()));
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
        if (mSnake.IsCollidingWith(mFood.GetPosition()))
		{
        	mSnakeLength++;
        	mSnake = Snake(mSnakeLength, ELEMENT_RADIUS);
        	mSnake.SetInitialPosition(getWindowWidth(), getWindowHeight());
			mSnake.SetDirection(mDirectionOffset);
			mFood.Respawn(getWindowWidth(), getWindowHeight());
			return;
		}
		mGameOver = mSnake.IsCollidingWithWindow(getWindowWidth(), getWindowHeight());
        mSnakeLength = STARTING_LENGTH;
    }
}

void Application::ChangeDirectionUp()
{
    if (mDirectionOffset != DOWN_OFFSET)
    {
        mDirectionOffset = UP_OFFSET;
        mDisplayString = "UP";
    }

    mSnake.SetDirection(mDirectionOffset);
}
void Application::ChangeDirectionDown()
{
    if (mDirectionOffset != UP_OFFSET)
    {
        mDirectionOffset = DOWN_OFFSET;
        mDisplayString = "DOWN";
    }

    mSnake.SetDirection(mDirectionOffset);
}
void Application::ChangeDirectionLeft()
{
    if (mDirectionOffset != RIGHT_OFFSET)
    {
        mDirectionOffset = LEFT_OFFSET;
        mDisplayString = "LEFT";
    }

    mSnake.SetDirection(mDirectionOffset);
}
void Application::ChangeDirectionRight()
{
    if (mDirectionOffset != LEFT_OFFSET)
    {
        mDirectionOffset = RIGHT_OFFSET;
        mDisplayString = "RIGHT";
    }

    mSnake.SetDirection(mDirectionOffset);
}

CINDER_APP(Application, ci::app::RendererGl(ci::app::RendererGl::Options().msaa(16)), &Application::prepareSettings)

