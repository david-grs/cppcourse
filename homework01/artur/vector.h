
class Vector
{
 public:
  Vector(double x = 0., double y = 0.)
    {
      this->x = x;
      this->y = y;
    }
  
  bool operator==(Vector other)
  {
    return (this->GetX() == other.GetX()) && (this->GetY() == other.GetY());
  }
  
  void Add(Vector other)
  {
    this->x += other.GetX();
    this->y += other.GetY();
  }
  
  double GetX()
  {
    return this->x;
  }

  double GetY()
  {
    return this->y;
  }

 private:
  double x;
  double y;
};
