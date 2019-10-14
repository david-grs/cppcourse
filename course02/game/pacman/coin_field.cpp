#include "coin_field.h"

void Coin::Draw()
{
	if (mPoints > 0)
	{
		ci::gl::color(mConfig.YELLOW);

		ci::gl::drawSolidCircle(
			ci::vec2(mCenter.mColumn, mCenter.mRow),
			mConfig.COIN_FIELD_RADIUS);
	}
}
