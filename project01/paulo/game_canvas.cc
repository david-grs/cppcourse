#include "game_canvas.h"

#include <random>

static std::random_device RandomDevice;
static std::mt19937 RandomEngine(RandomDevice());

GameCanvas::GameCanvas(ci::ivec2 canvasDelta, int width, int height, int pointSize) :
	mCanvasDelta(canvasDelta),
	mWidth(width),
	mHeight(height),
	mPointSize(pointSize)
{
	const ci::ivec2 canvasSize{width, height};
	const ci::ivec2 bottomRight = mCanvasDelta + mPointSize * canvasSize;
	mCanvas = ci::Rectf{mCanvasDelta, bottomRight};

	mUsedCount = std::vector<int>(width * height, 0);
	mTotalUsed = 0;
}

void GameCanvas::Clear()
{
	ci::gl::color(ci::Color::white());
	ci::gl::drawSolidRect(mCanvas);
}

void GameCanvas::ShowMessage(const std::string& message, const ci::Color& color) const
{
	ci::gl::color(color);
	ci::gl::drawSolidRect(mCanvas);
	ci::ivec2 messageBaseline = mCanvasDelta + mPointSize * ci::ivec2{mWidth/2, mHeight/2};
	ci::gl::drawStringCentered(message, messageBaseline, ci::Color::black(), ci::Font{"Courier", static_cast<float>(1.4 * mPointSize)});
}

void GameCanvas::Add(const ci::ivec2& point, const ci::Color& color)
{
	const ci::ivec2 upperLeft = mCanvasDelta + mPointSize * point;
	const ci::ivec2 bottomRight = upperLeft + ci::ivec2{mPointSize, mPointSize};
	ci::gl::color(color);
	ci::gl::drawSolidRect({upperLeft, bottomRight});
}

ci::ivec2 GameCanvas::GetRandomUnusedPoint() const
{
	std::uniform_int_distribution<> getUniforIndices(1, mUsedCount.size() - mTotalUsed);
	int freeIdx = getUniforIndices(RandomEngine);
	int actualIdx = 0;

	while (mUsedCount[actualIdx] || freeIdx)
	{
		freeIdx -= mUsedCount[actualIdx] == 0;
		++actualIdx;
	}

	return IndexToPoint(actualIdx);
}

void GameCanvas::Use(const ci::ivec2& pt)
{
	const int id = PointToIndex(pt);
	if (!mUsedCount[id]) ++mTotalUsed;
	mUsedCount[id]++;
}

void GameCanvas::Release(const ci::ivec2& pt)
{
	const int id = PointToIndex(pt);
	mUsedCount[id]--;
	if (!mUsedCount[id]) --mTotalUsed;
}
