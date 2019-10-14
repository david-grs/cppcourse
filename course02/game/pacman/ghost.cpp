#include "ghost.h"

void Ghost::MakeStep()
{
	switch (mDirection)
	{
	case DOWN:
		mCenter.mRow += mStepSize;
		break;
	case UP:
		mCenter.mRow -= mStepSize;
		break;
	case RIGHT:
		mCenter.mColumn += mStepSize;
		break;
	case LEFT:
		mCenter.mColumn -= mStepSize;
		break;
	default:
		break;
	}
}

void Ghost::Draw()
{
	DrawBody(GetBody());
}

std::vector<ci::vec2> Ghost::GetSkeleton()
{
	std::vector<ci::vec2> skeleton;

	auto ghostSize = mConfig.FIELD_SIZE;
	const float STEP = 0.1f;

	for (float i = M_PI; i < (2.0f * M_PI + STEP); i += STEP)
	{
		const float r = ghostSize / 2.0f;

		const float x = r + r * std::cos(i);
		const float y = r + r * std::sin(i);
		skeleton.emplace_back(x, y);
	}

	skeleton.emplace_back(ghostSize, ghostSize);
	skeleton.emplace_back(ghostSize * 5.0f / 6.0f, ghostSize * 5.0f / 6.0f);
	skeleton.emplace_back(ghostSize * 2.0f / 3.0f, ghostSize);
	skeleton.emplace_back(ghostSize / 2.0f, ghostSize * 5.0f / 6.0f);
	skeleton.emplace_back(ghostSize / 3.0f, ghostSize);
	skeleton.emplace_back(ghostSize / 6.0f, ghostSize * 5.0f / 6.0f);
	skeleton.emplace_back(0.0f, ghostSize);

	const float offset = ghostSize / 2;
	std::for_each(
		std::begin(skeleton),
		std::end(skeleton),
		[offset](ci::vec2& p) { p -= ci::vec2(offset, offset); });

	return skeleton;
}

std::vector<ci::vec2> Ghost::GetBody()
{
	std::vector<ci::vec2> points;
	ci::vec2 center{ mCenter.mColumn, mCenter.mRow };

	std::transform(
		std::begin(mGhostSkelton),
		std::end(mGhostSkelton),
		std::back_inserter(points),
		[&center](const ci::vec2& v) { return v + center; });

	return points;
}

void Ghost::DrawBody(const std::vector<ci::vec2>& body)
{
	ci::gl::color(mConfig.PINK);
	ci::vec2 center{ mCenter.mColumn, mCenter.mRow };

	for (auto i = 0u; i < body.size(); ++i)
	{
		const ci::vec2& p1 = body[i];
		const ci::vec2& p2 = body[(i + 1) % body.size()];

		ci::gl::drawSolidTriangle(p1, p2, center);
	}
}