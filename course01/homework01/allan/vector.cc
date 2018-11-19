#include "vector.h"
Vector& Vector::Add(const Vector& rhs)
{
	m_x += rhs.m_x;
	m_y += rhs.m_y;
	return *this;
}

Vector operator+(const Vector first, const Vector second)
{
	return Vector(first.m_x + second.m_x, first.m_y + second.m_y);
}

std::ostream& operator<<(std::ostream& ostr, Vector& vector)
{
	ostr << "Vector(" << vector.m_x << "," << vector.m_y << ")";
	return ostr;
}

