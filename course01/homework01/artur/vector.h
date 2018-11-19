#include <iostream>

class Vector
{
 public:
  Vector();
  Vector(const int, const int);
  Vector(const Vector&);
  
  const int GetX() const;
  const int GetY() const;

  const bool operator==(const Vector&);
  const Vector operator+(const Vector&);

  Vector& operator+=(const Vector&);
  
  void Add(const Vector&);

  friend std::ostream& operator<<(std::ostream&, const Vector&);
  
 private: 
  int mX;
  int mY;
};
