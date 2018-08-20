#pragma once

#include <cinder/gl/gl.h>

class GameCanvas
{
public:
  GameCanvas(ci::ivec2 /*canvasDelta*/, int /*width*/, int /*height*/, int /*pointSize*/);

  void Clear();
  void Add(const ci::ivec2&, const ci::Color&);

  int GetWidth() const { return mWidth; }
  int GetHeight() const { return mHeight; }

  ci::ivec2 GetRandomFreePoint();
  void SetUsed(const ci::ivec2&);
  void SetFree(const ci::ivec2&);

private:
  const ci::ivec2 mCanvasDelta;
  const int mWidth;
  const int mHeight;
  const int mPointSize;

  ci::Rectf mCanvas;
};
