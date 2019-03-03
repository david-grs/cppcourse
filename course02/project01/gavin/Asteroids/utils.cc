#include <cinder/Area.h>
#include <glm/vec2.hpp>

void ReturnToPlayArea(const cinder::Area &bounds, glm::vec2 &pos)
{
    if(pos.x > bounds.x2)
        pos.x = bounds.x1 + (pos.x - bounds.x2);
    if(pos.x < bounds.x1)
        pos.x = bounds.x2 - (bounds.x1 - pos.x);
    if(pos.y > bounds.y2)
        pos.y = bounds.y1 + (pos.y - bounds.y2);
    if(pos.y < bounds.y1)
        pos.y = bounds.y2 - (bounds.y1 - pos.y);
}
