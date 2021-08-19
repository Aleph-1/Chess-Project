#include "Point.h"

Point::Point(int x, char y)
{

	m_x = x-1;
	m_y = y - 65;
	

}

Point& Point::operator=(const Point& p)
{

	m_x = p.m_x;
	m_y = p.m_y;

	return *this;
}

bool Point::operator==(const Point& p)
{

	if (m_x == p.m_x && m_y == p.m_y) {
		return true;
	}

	return false;
	
}
