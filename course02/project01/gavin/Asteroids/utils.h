#pragma once

#include <cinder/Area.h>
#include <glm/vec2.hpp>
#include <chrono>

using FrameDelta = std::chrono::duration<float>;

using ObjectId = uint64_t;

void ReturnToPlayArea(const cinder::Area &bounds, glm::vec2 &pos);