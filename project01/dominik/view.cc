#include "view.h"
#include <cinder/app/RendererGl.h>
#include <cinder/gl/gl.h>

void GameView::Draw(const Snake& snake, const Bait& bait) const
{
        ci::gl::clear();
        ci::gl::setMatricesWindow(mWindowSize);

        ci::gl::color(ci::Color(1.0f, .1f, .1f));
        ci::gl::drawSolidCircle(bait.GetPosition(), bait.GetRadius());

        ci::gl::color(ci::Color(0.8f, 0.8f, 0.8f));
        for (cinder::ivec2 bodyPart : snake.GetBody())
        {
            ci::gl::drawSolidCircle(bodyPart, snake.GetSize());
        }
}
