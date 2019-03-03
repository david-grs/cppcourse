#pragma once

#include <glm/vec2.hpp>
#include "collidable.h"
class Laser;

class Asteroid : public Collidable {
public:
    Asteroid(GameWorld* root, glm::vec2 direction, glm::vec2 position, float size, float speed);

    void Update(FrameDelta frameDelta) override;
    void Draw() override;

    void Collide(Laser &laser);

    template<typename T>
    void Collide(T&){}
private:
    glm::vec2 mDirection;
    float mSpeed;
    void Break();
};


