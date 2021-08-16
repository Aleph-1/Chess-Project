#include "Point.h"

Point::Point(int x, char y)
{

	m_x = x-1;
	
	if (y == 65) {
		m_y = 0;
		return;
	}
	if (y == 66) {
		m_y = 1;
		return;
	}
	if (y == 67) {
		m_y = 2;
		return;
	}
	if (y == 68) {
		m_y = 3;
		return;
	}
	if (y == 69) {
		m_y = 4;
		return;
	}
	if (y == 70) {
		m_y = 5;
		return;
	}
	if (y == 71) {
		m_y = 6;
		return;
	}
	if (y == 72) {
		m_y = 7;
		
	}



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
