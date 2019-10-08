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
	void left();
	void up();
	void down();
private:
	std::array<std::array<int, 4>, 4> mGrid;

	int mGridSize = 4;
	int mTurn = 0;

	bool mVictory = false;

	void spawn();
	void check_victory();
	std::array<int, 4> aggregate_row(std::array<int, 4> row);

    std::mt19937 mGen; //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> mDis;

};
