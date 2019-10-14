#pragma once

#include <cinder/Color.h>
#include <boost/assign/list_of.hpp>
#include <boost/unordered_map.hpp>
#include <chrono>

using boost::assign::map_list_of;
using namespace std::chrono_literals;

struct Config
{
	static const int WINDOW_SIZE_X = 500;
	static const int WINDOW_SIZE_Y = 350;

	const int FIELD_SIZE = 12;
	const int FIELD_OFFSET = 2;

	const float BASIC_FIELD_RADIUS = 1.0f;
	const float COIN_FIELD_RADIUS = 3.0f;
	const float PACMAN_RADIUS = 6.0f;

	const std::chrono::milliseconds CURTAIN_UPDATE_INTERVAL{ 200ms };

	const std::chrono::milliseconds PACMAN_UPDATE_INTERVAL{ 50ms };
	const int PACMAN_STEP_IN_PX = 4; // per update interval

	const std::chrono::milliseconds GHOST_UPDATE_INTERVAL{ 50ms };
	const int GHOST_STEP_IN_PX = 4; // per update interval
	const int GHOST_STEP_IN_PX_SLOW = 2; // per update interval
	const std::chrono::seconds RELEASE_GHOSTS{ 5s }; // after 5 seconds of game start

	const int MAP_START_ROW = 20;
	const int MAP_START_COLUMN = 20;

	const std::string MAP_FILE_NAME = "map.txt";

	ci::Color YELLOW{ 1.0, 1.0, 0.0 };
	ci::Color BLUE{ 0.0, 0.0, 1.0 };
	ci::Color BLACK{ 0.0, 0.0, 0.0 };
	ci::Color RED{ 1.0, 0.0, 0.1 };
	ci::Color PINK{ 0.5, 0.0, 0.5 };
	ci::Color GREEN{ 0.0, 0.5, 0.0 };
	ci::Color WHITE{ 1.0, 1.0, 1.0 };

	const int BASIC_POINTS = 1;
	const int COIN_POINTS = 3;
};

enum FIELD 
{ 
	WALL,
	TMP_WALL,
	BASIC,
	COIN,
	EMPTY,
	PACMAN,
	GHOST
};

const boost::unordered_map<const std::string, FIELD> stringToField = map_list_of
("W", WALL)
("T", TMP_WALL) // temporary wall field that guards ghosts
("-", BASIC)
("C", COIN)
(" ", EMPTY)
("P", PACMAN)
("G", GHOST);
