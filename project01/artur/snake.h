#include <vector>
#include "point.h"
#include "walls.h"

class Snake
{
 public:
 Snake()
   : mBody({Point(7,8), Point(7,8), Point(7,8), Point(7,8), Point(8,8)})
    {};
  
  void ChangeDirection(const Point&);
  int Length() const;
  Point Dir() const;
  std::vector<Point> Body() const;
  bool IsAlive(const Point&, const Walls&) const;
  void Move(const Point&);
  void Grow();
  bool CheckOutsideWallsCollision(const Point&) const;
  bool CheckWallsCollision(const Walls&) const;
  bool CheckSelfCollision() const;
  
 private:
  std::vector<Point> mBody;

};
