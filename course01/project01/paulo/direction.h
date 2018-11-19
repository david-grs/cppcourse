#pragma once

#include <cinder/gl/gl.h>

enum class Direction
{
  None,
  Up,
  Down,
  Left,
  Right
};

Direction GetOpposite(Direction);
ci::ivec2 ToVector(Direction);
