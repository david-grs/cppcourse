#include <cmath>
#include "collidable.h"
#include "game_world.h"

Collidable::Collidable(GameObject& parent, Tag tag, glm::vec2 position, float size) : GameObject(parent, tag, position, size)
{
    //FIXME: There has to be a better way
    dynamic_cast<GameWorld*>(&mRoot)->AddCollider(this);
}
//FIXME: just square hitboxes for now
bool Collidable::Overlaps(Collidable& other)
{
    const auto diff = mPosition - other.GetPosition();
    const auto dist = std::sqrt(diff.x*diff.x + diff.y*diff.y);
    return dist < mSize or dist < other.GetSize();
}

Collidable::~Collidable()
{
        dynamic_cast<GameWorld*>(&mRoot)->RemoveCollider(this);
}
