#pragma once

#include <glm/vec2.hpp>
#include "collidable.h"

class Asteroid : public Collidable {
public:
    Asteroid(GameObject& parent, glm::vec2 direction, glm::vec2 position, float size, float speed);

    void Update(float frameDelta) override;
    void Draw() override;
    void Collide(Collidable& other) override;
    void Break();
private:
    glm::vec2 mDirection;
    float mSpeed;
};


