#include "game_world.h"
#include <cmath>

Collidable::Collidable(GameWorld* root, ObjectId id, glm::vec2 position, float size) : GameObject(root, id, position, size)
{
}
//FIXME: just square hitboxes for now
bool Collidable::Overlaps(const Collidable& other) const
{
    const auto diff = mPosition - other.GetPosition();
    const auto dist = std::sqrt(diff.x*diff.x + diff.y*diff.y);
    return dist < mSize or dist < other.GetSize();
}
