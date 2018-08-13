#include <vector>
#include "point.h"

class Snake
{
 public:
 Snake()
   : mBody({Point(7,8), Point(7,8), Point(7,8), Point(7,8), Point(8,8)})
    {};
  
  void ChangeDirection(const Point&);
  int Length();
  Point Dir();
  std::vector<Point> Body();
  bool IsAlive(const Point&);
  void Move(const Point&);
  void Grow();
  bool CheckWallsCollision(const Point&);
  bool CheckSelfCollision();
  
 private:
  std::vector<Point> mBody;

};
