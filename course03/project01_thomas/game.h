#pragma once
#include <array>

class Game
{
public:
	Game();

	void setup();
	void draw();
	void update();

private:
	std::array<std::array<int, 4>, 4> mGrid;

	int mGridSize = 4;

};
