#include "game.h"
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/Text.h"
#include "cinder/Color.h"
#include <random>

using namespace ci;
using namespace ci::app;

void Game::right()
{
	std::cout << "Right." << std::endl;

	std::array<std::array<int, 4>, 4> newGrid;

	/* for (auto row : mGrid) { */
	for (int i = 0; i < mGridSize; i++) {

		int prev = 0;
		/* std::array<int, 4> newrow; */
		int idx = 3;

		for (int j = mGridSize-1; j >= 0; j--) {
		{
			int value = mGrid[i][j];
			if (value != 0){
				if (prev == 0) {
					prev = value;
				} else {
					if (prev == value) {
						mGrid[i][idx] = prev + value;
						idx = idx - 1;
						prev = 0;
					} else {
						mGrid[i][idx] = prev;
						idx = idx - 1;
						prev = value;
					}
				}
			}
			mGrid[i][j] = 0;

		}
		if (prev != 0) {
			mGrid[i][idx] = prev;
		}
		
		}

		 /* newGrid[i] = newrow; */
		 /* mGrid[i] = newrow; */

		/* int prev = 0; */
  
		/* for (i1=row.end();i1!=row.begin();--i1) */ 
		/* { */ 
		/* 	if (i1 != row.end()) */ 
		/* 	{ */ 
		/* 		std::cout << (*i1) << " "; */ 
		/* 	} */ 
		/* } */ 
		/* std::cout << (*i1); */ 

	}

	/* mGrid = newGrid; */
	mTurn = mTurn + 1;
	spawn();
}


Game::Game()
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    /* mGen = mGen{rd()}; //Standard mersenne_twister_engine seeded with rd() */
    mGen = std::mt19937{rd()}; //Standard mersenne_twister_engine seeded with rd()
    /* mDis{0, mGridSize * mGridSize}; */
    /* mDis = mDis{0, mGridSize * mGridSize}; */
    mDis = std::uniform_int_distribution<>(0, mGridSize - 1);
}

void Game::spawn()
{
	int x = mDis(mGen);
	int y = mDis(mGen);
	if(mGrid[x][y] == 0){
		mGrid[x][y] = 2;
	};
}

void Game::setup()
{
	spawn();

}

void Game::draw()
{


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
