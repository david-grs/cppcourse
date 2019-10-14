#include "basic_field.h"

void BasicField::Draw()
{
	if (mPoints > 0)
	{
		ci::gl::color(mConfig.YELLOW);

		ci::gl::drawSolidCircle(
			ci::vec2(mCenter.mColumn, mCenter.mRow),
			mConfig.BASIC_FIELD_RADIUS);
	}
}
