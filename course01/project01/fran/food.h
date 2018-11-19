#include <cinder/app/RendererGl.h>
#include "cinder/gl/gl.h"

class Food
{
public:
	const float PETAL_SIZE = 1.8f;
	Food(float radius);

	void Update(double elapsedSeconds);
	void Draw();

	cinder::vec2 GetPosition();
	void Respawn(float width, float height);

private:
	cinder::vec2 mPosition;
	float mRadius;
	cinder::vec2 mAnimateOffset;
};

