#pragma once

#include <cinder/gl/gl.h>

class GameCanvas;

class Apple
{
public:
  explicit Apple(GameCanvas&);
  ~Apple();

  const ci::ivec2& Location() const { return mLocation; }
  void Draw();
private:
  GameCanvas& mCanvas;
  ci::ivec2 mLocation;
};
