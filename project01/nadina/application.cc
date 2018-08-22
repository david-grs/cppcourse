#include "application.h"
#include <stdlib.h>
#include <cinder/Color.h>
#include <time.h>

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

void Application::keyDown(ci::app::KeyEvent keyEvent)
{
    if (keyEvent.getCode() == ci::app::KeyEvent::KEY_DOWN)
    {
            mVerticalDirection = 1;
            mHorizontalDirection = 0;
    }
    else if (keyEvent.getCode() == ci::app::KeyEvent::KEY_UP)
    {
            mVerticalDirection = -1;
            mHorizontalDirection = 0;
    }
    else if (keyEvent.getCode() == ci::app::KeyEvent::KEY_RIGHT)
    {
            mVerticalDirection = 0;
            mHorizontalDirection = 1;
    }
    else if (keyEvent.getCode() == ci::app::KeyEvent::KEY_LEFT)
    {
            mVerticalDirection = 0;
            mHorizontalDirection = -1;
    }
}

void Application::setup()
{
    mSnake.push_back(getWindowCenter());
    updateFoodPos();
}

void Application::draw()
{
    ci::gl::clear();

    //Draw food
    ci::gl::color(cinder::Color(1, 1, 1));
    ci::gl::drawSolidCircle(mFood, mFoodSize);

    //Draw snake
    ci::gl::color(cinder::Color(0, 1, 0));
    for (auto const& item : mSnake)
    {
        ci::gl::drawSolidCircle(item, mSnakeSize, mSnakeSize);
    }

    if (collisionDetected())
    {
        updateFoodPos();
        increaseSnake();
        mSpeed += 0.5f;
    }
}

void Application::increaseSnake()
{
    mSnake.push_back(glm::vec2());
}

void Application::updateFoodPos()
{
    int x = rand() % 640 + 1;
    int y = rand() % 480 + 1;
    mFood = glm::vec2(x, y);
}

void Application::resetBoundaries(glm::vec2& pos)
{
    if (pos.x < getWindowBounds().x1)
        pos.x = getWindowBounds().x2;
    else if (pos.x > getWindowBounds().x2)
        pos.x = getWindowBounds().x1;
    else if (pos.y < getWindowBounds().y1)
        pos.y = getWindowBounds().y2;
    else if (pos.y > getWindowBounds().y2)
        pos.y = getWindowBounds().y1;
}

void Application::update()
{
    for (std::vector<glm::vec2>::size_type i = mSnake.size() - 1; i >= 1; i --)
    {
        mSnake[i] = mSnake[i-1];
    }
    mSnake[0] += glm::vec2(mHorizontalDirection * mSpeed, mVerticalDirection * mSpeed);
    resetBoundaries(mSnake[0]);
}

bool Application::collisionDetected()
{
    float headSnakeX = mSnake[0].x;
    float headSnakeY = mSnake[0].y;
    return abs(headSnakeX - mFood.x) < 20.0 && abs(headSnakeY - mFood.y) < 20.0;
}

CINDER_APP(Application, ci::app::RendererGl(ci::app::RendererGl::Options().msaa(16)), &Application::prepareSettings)

