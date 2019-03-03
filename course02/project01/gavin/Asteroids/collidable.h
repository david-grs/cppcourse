#pragma once
#include "game_object.h"


class Collidable : public GameObject {
public:
    Collidable(GameWorld* root, ObjectId id, glm::vec2 position, float size);

    bool Overlaps(Collidable& other);

    float GetSize(){return mSize;}
    glm::vec2& GetPosition() { return mPosition;}

};
