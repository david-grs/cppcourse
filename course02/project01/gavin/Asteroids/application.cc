#include "application.h"

Application::Application() : mGameWorld(mController),
                            mLastFrameTime(static_cast<float>(getElapsedSeconds())),
                            mThisFrameTime(static_cast<float>(getElapsedSeconds())){

}

void Application::draw()
{
    mThisFrameTime = static_cast<float>(getElapsedSeconds());
    auto delta = mThisFrameTime - mLastFrameTime;

    mGameWorld.Update(FrameDelta(delta));
    ci::gl::clear();
    mGameWorld.Draw();
    mLastFrameTime = mThisFrameTime;
}

void Application::keyDown(KeyEvent event)
{
    mController.keyDown(event);
}

void Application::keyUp(KeyEvent event)
{
    mController.keyUp(event);
}

