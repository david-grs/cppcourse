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
        std::vector<cinder::ivec2> body;
        snake.GetBody(body);
        for (cinder::ivec2 bodyPart : body)
        {
            ci::gl::drawSolidCircle(bodyPart, snake.GetSize());
        }
}
