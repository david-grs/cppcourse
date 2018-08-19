#include "point.h"
#include <vector>

class Walls
{
 public:
  Walls()
    {};
 Walls(std::vector<Point> vec)
   : mBody(vec)
  {};
  std::vector<Point> Body() const {return mBody;}
 private:
  std::vector<Point> mBody;
};
