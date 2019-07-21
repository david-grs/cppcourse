#pragma once
#include <array>
#include <random>
class Game
{
public:
	Game();

	void setup();
	void draw();
	void update();

	void right();
private:
	std::array<std::array<int, 4>, 4> mGrid;

	int mGridSize = 4;
	int mTurn = 0;

	void spawn();

    std::mt19937 mGen; //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> mDis;

};
