#include "pacman.h"

void Pacman::UpdateMouth(const double delta)
{
	if (mMouthState == CLOSING)
	{
		mOpenMouth -= delta * 2.0f;
		if (mOpenMouth <= 0.0f)
		{
			mOpenMouth = 0.0f;
			mMouthState = OPENING;
		}
	}
	else
	{
		mOpenMouth += delta * 2.0f;
		if (mOpenMouth >= 1.0f)
		{
			mOpenMouth = 1.0f;
			mMouthState = CLOSING;
		}
	}
}

void Pacman::MakeStep()
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

void Pacman::Draw()
{
	std::vector<ci::vec2> skeleton = std::move(GetSkeleton());
	std::vector<ci::vec2> body = std::move(GetBorder(skeleton));
	ci::vec2 center{ mCenter.mColumn, mCenter.mRow };
	ci::gl::color(mConfig.YELLOW);
	for (auto i = 0u; i < body.size() - 1; ++i)
	{
		const ci::vec2& p1 = body[i];
		const ci::vec2& p2 = body[i + 1];

		ci::gl::drawSolidTriangle(p1, p2, center);
	}
}

std::vector<ci::vec2> Pacman::GetSkeleton()
{
	std::vector<ci::vec2> skeleton;

	auto openMouthAngle = mOpenMouth * M_PI / 4.0f;
	float startAngle = openMouthAngle;
	AlignDirectionAngle(startAngle);
	float endAngle = startAngle + 2.0f * M_PI - 2.0f * openMouthAngle;
	if (endAngle < startAngle)
		openMouthAngle += 2.0f * M_PI;

	const float angleStep = 0.05f;

	for (float angle = startAngle; angle <= endAngle; angle += angleStep)
	{
		const float x = mRadius * std::cos(angle);
		const float y = mRadius * std::sin(angle);
		skeleton.emplace_back(x, y);
	}

	return skeleton;
}

std::vector<ci::vec2> Pacman::GetBorder(std::vector<ci::vec2>& skeleton)
{
	std::vector<ci::vec2> points;
	ci::vec2 center{ mCenter.mColumn, mCenter.mRow };

	std::transform(
		std::begin(skeleton),
		std::end(skeleton),
		std::back_inserter(points),
		[&center](const ci::vec2& v) { return v + center; });

	return points;
}

void Pacman::AlignDirectionAngle(float& angle)
{
	if (mDirection == DOWN)
		angle += M_PI / 2.0f;
	else if (mDirection == LEFT)
		angle += M_PI;
	else if (mDirection == UP)
		angle += M_PI * 3.0f / 2.0f;
}
