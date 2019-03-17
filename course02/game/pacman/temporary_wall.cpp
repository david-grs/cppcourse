#include "temporary_wall.h"

void TemporaryWall::Draw()
{
	if (!mIsVisitable)
	{
		ci::gl::color(mConfig.BLUE);

		const float x1 = mCenter.mColumn - (mFieldSize * 0.5f);
		const float y1 = mCenter.mRow + (mFieldSize * 0.5f);
		const float x2 = mCenter.mColumn + (mFieldSize * 0.5f);
		const float y2 = mCenter.mRow - (mFieldSize * 0.5f);
		ci::Rectf rect(x1, y1, x2, y2);

		ci::gl::drawSolidRect(rect);
	}
}