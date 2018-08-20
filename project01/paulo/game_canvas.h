#pragma once

#include <cinder/gl/gl.h>

#include <vector>

class GameCanvas
{
public:
  GameCanvas(ci::ivec2 /*canvasDelta*/, int /*width*/, int /*height*/, int /*pointSize*/);

  void Clear();
  void Add(const ci::ivec2&, const ci::Color&);
  void ShowMessage(const std::string& /*message*/, const ci::Color&) const;

  int GetWidth() const { return mWidth; }
  int GetHeight() const { return mHeight; }

  ci::ivec2 GetRandomUnusedPoint() const;
  void Use(const ci::ivec2&);
  void Release(const ci::ivec2&);

private:
  int PointToIndex(const ci::ivec2& pt) const { return pt.x * mHeight + pt.y; }
  ci::ivec2 IndexToPoint(int idx) const { return ci::ivec2{idx/mHeight, idx%mHeight}; }

  const ci::ivec2 mCanvasDelta;
  const int mWidth;
  const int mHeight;
  const int mPointSize;

  int mTotalUsed{0};
  std::vector<int> mUsedCount;
  ci::Rectf mCanvas;
};
