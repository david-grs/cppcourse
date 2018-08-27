#include <cinder/app/RendererGl.h>
#include "cinder/gl/gl.h"

class Segment
{
public:
    Segment(const cinder::vec2& startingPosition, float radius);

    void Update(const cinder::vec2& newPosition);
    void Draw();

    const cinder::vec2& GetPosition();
    bool IsCollidingWithWindow(float width, float height);

private:
    cinder::vec2 mPosition;
    float mRadius = 2.0f;
};

