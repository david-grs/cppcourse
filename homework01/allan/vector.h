#include <ostream>

class Vector
{
public:

	Vector()
	:Vector(0,0)
	{
	}

	Vector(int x, int y)
	:m_x(x),
	 m_y(y)
	{
	}

	bool operator==(const Vector& rhs) const
	{
		return m_x == rhs.m_x &&
			   m_y == rhs.m_y;
	}
	
	friend Vector operator+(Vector first, Vector second);
	

	Vector& operator+=(Vector rhs)
	{
		return Add(rhs);
	}

	int GetX() const
	{
		return m_x;
	}

	int GetY() const
	{
		return m_y;
	}

	Vector& Add(const Vector& rhs)
	{
		m_x += rhs.m_x;
		m_y += rhs.m_y;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& ostr, Vector& vector);

private:
	int m_x;
	int m_y;
};


Vector operator+(const Vector first, const Vector second)
{
	return Vector(first.m_x + second.m_x, first.m_y + second.m_y);
}

std::ostream& operator<<(std::ostream& ostr, Vector& vector)
{
	ostr << "Vector(" << vector.m_x << "," << vector.m_y << ")";
	return ostr;
}
