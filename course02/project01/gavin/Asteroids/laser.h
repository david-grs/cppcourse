#pragma once

#include <glm/vec2.hpp>
#include "collidable.h"

class Laser : public Collidable {
public:
    Laser(GameWorld* root, glm::vec2 direction, glm::vec2 position);
    ~Laser() = default;
    void Update(FrameDelta frameDelta) override;
    void Draw() override;

    template<typename T>
    void Collide(T&){}

private:
    glm::vec2 mDirection;
    float speed = 100;
};


