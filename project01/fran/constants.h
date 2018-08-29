#pragma once
#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include "cinder/gl/gl.h"
#include "cinder/gl/TextureFont.h"

	const std::string GAME_TITLE = "The Very Hungry Catepillar";
	const std::string FULL_SCREEN_MESSAGE = "Full screen mode, Esc to exit full screen, or use F11 to toggle on/off.";
	const cinder::vec2 UP_OFFSET = cinder::vec2(0.0f, -1.0f);
	const cinder::vec2 DOWN_OFFSET = cinder::vec2(0.0f, 1.0f);
	const cinder::vec2 LEFT_OFFSET = cinder::vec2(-1.0f, 0.0f);
	const cinder::vec2 RIGHT_OFFSET = cinder::vec2(1.0f, 0.0f);
	const int STARTING_LENGTH = 5;
	const float ELEMENT_RADIUS = 10.0f;