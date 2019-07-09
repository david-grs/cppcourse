#pragma once

#include <cinder/Rand.h>
#include <cinder/app/App.h>
#include <cinder/gl/gl.h>

#include <chrono>

#include "types.h"

inline uint64_t timestamp_ms()
{
	using namespace std::chrono;

	return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

inline cinder::vec2 RandInBounds(const cinder::vec2& bounds)
{
	return {cinder::Rand::randFloat() * bounds.x,
		cinder::Rand::randFloat() * bounds.y};
}

inline void DrawTextInPosition(const std::string& text, cinder::vec2 position)
{
	using namespace ci;

	TextLayout layout;
	layout.clear(ColorA(0.2, 0.2, 0.2, 0.7));
	layout.setColor(Color(1, 1, 1));
	layout.addCenteredLine(text);

	Surface8u rendered = layout.render(true, false);
	auto texture = gl::Texture2d::create(rendered);
	gl::draw(texture, position);
}

inline void DrawStartupScreen()
{
	using namespace ci;
	
	gl::clear(Color{0.2,0.4,0.7});

	static const char* startupMessage = "SPACEIMPACT";
	static const char* instructions = 
		"Use J/K to move your ship and F to fire. Press <space> to start.";

	TextLayout layout;
	layout.clear(ColorA(0.2, 0.2, 0.2, 0.7));
	layout.setColor(Color(1, 1, 1));
	layout.addCenteredLine(startupMessage);
	layout.addCenteredLine(instructions);

	Surface8u rendered = layout.render(true, false);
	auto texture = gl::Texture2d::create(rendered);
	gl::draw(texture, vec2{40,40});

}
