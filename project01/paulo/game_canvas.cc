#include "game_canvas.h"

GameCanvas::GameCanvas(ci::ivec2 canvasDelta, int width, int height, int pointSize) :
	mCanvasDelta(canvasDelta),
	mWidth(width),
	mHeight(height),
	mPointSize(pointSize)
{
	const ci::ivec2 canvasSize{width, height};
	const ci::ivec2 bottomRight = mCanvasDelta + mPointSize * canvasSize;
	mCanvas = ci::Rectf{mCanvasDelta, bottomRight};
}

void GameCanvas::Clear()
{
	ci::gl::color(ci::Color::white());
	ci::gl::drawSolidRect(mCanvas);
}

void GameCanvas::Add(const ci::ivec2& point, const ci::Color& color)
{
	const ci::ivec2 upperLeft = mCanvasDelta + mPointSize * point;
	const ci::ivec2 bottomRight = upperLeft + ci::ivec2{mPointSize, mPointSize};
	ci::gl::color(color);
	ci::gl::drawSolidRect({upperLeft, bottomRight});
}

ci::ivec2 GameCanvas::GetRandomFreePoint()
{
	return ci::ivec2{0, 0};
}

void GameCanvas::SetUsed(const ci::ivec2&)
{}

void GameCanvas::SetFree(const ci::ivec2&)
{}