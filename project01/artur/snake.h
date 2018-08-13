#include <vector>
#include "point.h"

class Snake
{
 public:
 Snake()
   : mBody({Point(7,8), Point(7,8), Point(7,8), Point(7,8), Point(8,8)})
    {};
  
  void ChangeDirection(Point);
  int Length();
  Point Dir();
  std::vector<Point> Body();
  bool IsAlive();
  void Move(Point);
  void Grow();
  bool CheckWallsCollision();
  bool CheckSelfCollision();
  
 private:
  std::vector<Point> mBody;

};
