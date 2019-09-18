#pragma once

#include <cinder/Area.h>
#include <glm/vec2.hpp>

enum class Tag {
    None,
    Player,
    Laser,
    Asteroid
};

void ReturnToPlayArea(cinder::Area &bounds, glm::vec2 &pos);