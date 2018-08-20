#include "apple.h"

#include "game_canvas.h"

static const ci::Color AppleColor{ci::Color::hex(0xDA1205)};

Apple::Apple(GameCanvas& canvas) :
  mCanvas(canvas)
{
  mLocation = mCanvas.GetRandomFreePoint();
  mCanvas.SetUsed(mLocation);
}

Apple::~Apple()
{
  mCanvas.SetFree(mLocation);
}

void Apple::Draw()
{
  mCanvas.Add(mLocation, AppleColor);
}
