#pragma once
#include "game_object.h"


class Collidable : public GameObject {
public:
    Collidable(GameWorld* root, ObjectId id, glm::vec2 position, float size);

    bool Overlaps (const Collidable& other) const;

    float GetSize() const {return mSize;}
    const glm::vec2& GetPosition() const { return mPosition;}
};
