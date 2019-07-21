#include "game.h"
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/Text.h"
#include "cinder/Color.h"
#include <random>
#include <iterator>
#include <algorithm>
using namespace ci;
using namespace ci::app;

void Game::check_victory()
{
	for (int i = 0; i < mGridSize; i++) {
		for (int j = 0; j < mGridSize; j++) {
			if (mGrid[i][j] >= 2048) {
				mVictory = true;
				return;
			}

		}
	}
}

void Game::right()
{

	std::cout << "Right." << std::endl;

	for (int i = 0; i < mGridSize; i++) {
		std::array<int, 4> row = mGrid[i];
		std::reverse(std::begin(row), std::end(row));
		row = aggregate_row(row);
		std::reverse(std::begin(row), std::end(row));
		mGrid[i] = row;
	}

	mTurn = mTurn + 1;
	check_victory();
	spawn();
}

void Game::left()
{

	std::cout << "Left." << std::endl;

	for (int i = 0; i < mGridSize; i++) {
		std::array<int, 4> row = mGrid[i];
		row = aggregate_row(row);
		mGrid[i] = row;
	}

	mTurn = mTurn + 1;
	check_victory();
	spawn();
}

void Game::up()
{

	std::cout << "Up." << std::endl;

	for (int i = 0; i < mGridSize; i++) {
		std::array<int, 4> row;
		for (int j = 0; j < mGridSize; j++) {
			row[j] = mGrid[j][i];
		}
		row = aggregate_row(row);
		for (int j = 0; j < mGridSize; j++) {
			mGrid[j][i] = row[j];
		}
	}

	mTurn = mTurn + 1;
	check_victory();
	spawn();
}

void Game::down()
{

	std::cout << "Up." << std::endl;

	for (int i = 0; i < mGridSize; i++) {
		std::array<int, 4> row;
		for (int j = 0; j < mGridSize; j++) {
			row[j] = mGrid[j][i];
		}
		std::reverse(std::begin(row), std::end(row));
		row = aggregate_row(row);
		std::reverse(std::begin(row), std::end(row));
		for (int j = 0; j < mGridSize; j++) {
			mGrid[j][i] = row[j];
		}
	}

	mTurn = mTurn + 1;
	check_victory();
	spawn();
}


std::array<int, 4> Game::aggregate_row(std::array<int, 4> row)
{

	int prev = 0;
	int idx = 0;

	for (int i = 0; i < mGridSize; i++) {
		int value = row[i];
		if (value != 0){
			if (prev == 0) {
				prev = value;
			} else {
				if (prev == value) {
					row[idx] = prev + value;
					idx++;
					prev = 0;
				} else {
					row[idx] = prev;
					idx++;
					prev = value;
				}
			}
		}
		row[i] = 0;

	}
	if (prev != 0) {
		row[idx] = prev;
	}

	return row;
	
}

Game::Game()
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    mGen = std::mt19937{rd()}; //Standard mersenne_twister_engine seeded with rd()
    mDis = std::uniform_int_distribution<>(0, mGridSize - 1);

	for (int i = 0; i < mGridSize; i++) {
		for (int j = 0; j < mGridSize; j++) {
			mGrid[i][j] = 0;
		}
	}
}

void Game::spawn()
{
	int x = mDis(mGen);
	int y = mDis(mGen);
	std::cout << x << std::endl;
	std::cout << y << std::endl;
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

	if (mVictory) {
		gl::clear();
		vec2 center = getWindowCenter();
		gl::drawStringCentered("Victory", center, ColorA(0,0,1,1), Font("Arial", 50));

	} else {

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
}
