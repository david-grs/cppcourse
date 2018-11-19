#include "direction.h"

Direction GetOpposite(Direction dir)
{
  switch(dir)
  {
    case Direction::Up: return Direction::Down;
    case Direction::Down: return Direction::Up;
    case Direction::Left: return Direction::Right;
    case Direction::Right: return Direction::Left;
    case Direction::None: return Direction::None;
  }
}

ci::ivec2 ToVector(Direction dir)
{
  switch(dir)
  {
    case Direction::Up: return ci::ivec2{0, -1};
    case Direction::Down: return ci::ivec2{0, 1};
    case Direction::Left: return ci::ivec2{-1, 0};
    case Direction::Right: return ci::ivec2{1, 0};
    case Direction::None: return ci::ivec2{0, 0};
  }
  throw std::runtime_error("unexpected direction");
}
