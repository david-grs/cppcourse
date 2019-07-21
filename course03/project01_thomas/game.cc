#include "game.h"
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/Text.h"
#include "cinder/Color.h"


using namespace ci;
using namespace ci::app;


Game::Game()
{

}

void Game::draw()
{

	mGrid[0][1] = 2;

	float w = 100.0f;

	gl::clear();
	vec2 center = getWindowCenter();
	gl::color(1.0f, 0.0f , 0.0f) ;

	vec2 topleft = vec2(0, 0);
	vec2 current = topleft;
	int offset = 5;
	current = current + vec2(offset, offset) ;

	for (auto row : mGrid) {
		vec2 tmp_current = current;
		for (auto el : row) {
			vec2 botright = tmp_current + vec2(w, w);
			auto block = Rectf(tmp_current,botright);
			gl::drawSolidRect(block);

			if (el != 0 ){
				vec2 centered = tmp_current + vec2(w/2, w/2);
				gl::drawStringCentered(std::to_string(el), centered, ColorA(0,0,1,1), Font("Arial", 50));
			}
			tmp_current = tmp_current + vec2(w,0) + vec2(offset,0) ;

		}
		current = current + vec2(0,w)+ vec2(0, offset) ;
	}
}
