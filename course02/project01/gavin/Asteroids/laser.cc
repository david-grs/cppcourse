//
// Created by gavinparker on 10-2-19.
//

#include <cinder/gl/gl.h>
#include "laser.h"

Laser::Laser(GameObject& parent, glm::vec2 direction, glm::vec2 position) : Collidable(parent, Tag::Laser, position, 1), mDirection(direction){}

void Laser::Update(const float frameDelta)
{
    auto dist = mDirection * speed * frameDelta;
    mPosition += dist;
}

void Laser::Draw()
{
    ci::gl::drawSolidCircle(mPosition, mSize);
}

void Laser::Collide(Collidable &other) {
    if(other.GetTag() == Tag::Asteroid)
        Destroy();

}