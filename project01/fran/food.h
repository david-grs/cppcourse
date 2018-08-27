#include <cinder/app/RendererGl.h>
#include "cinder/gl/gl.h"

class Food
{
public:
    Food(float radius);

    void Update(double elapsedSeconds);
    void Draw();

    const cinder::vec2& GetPosition();
    void Respawn(float width, float height);

private:
    cinder::vec2 mPosition;
    float mRadius;
    cinder::vec2 mAnimateOffset;
};

