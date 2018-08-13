#include "view.h"
#include <cinder/app/RendererGl.h>
#include <cinder/gl/gl.h>

GameView::GameView(const cinder::ivec2& windowSize, const int snakeBodyPartSize)
    : mWindowSize(windowSize),
      mSnakeBodyPartSize(snakeBodyPartSize),
      mBodyPartRect(cinder::vec2{0,0}, cinder::vec2{mSnakeBodyPartSize,mSnakeBodyPartSize})
{}

void GameView::Draw(const Snake& snake, const Bait& bait) const
{
        ci::gl::clear();
        ci::gl::setMatricesWindow(mWindowSize);

        ci::gl::color(ci::Color(0.8f, 0.8f, 0.8f));
        for (cinder::ivec2 bodyPart : snake.GetBody())
        {
            ci::gl::drawSolidRect(mBodyPartRect + bodyPart);
        }

        ci::gl::color(ci::Color(1.0f, .1f, .1f));
        ci::gl::drawSolidCircle(bait.GetPosition(), bait.GetRadius());
}
