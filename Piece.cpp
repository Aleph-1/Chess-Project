#include "Piece.h"

Piece::Piece(Point a, char name, int color) : m_loc(a)
{
	m_name = name;
	m_color = color;
}

Piece::Piece(int x, int y, char name, int color) :m_loc(x, y)
{

	m_name = name;
	m_color = color;

}

Piece::Piece(const Piece& p) : m_loc(p.m_loc)
{
	
	m_name = p.m_name;
	m_color = p.m_color;

}



const char Piece::getName()
{

	return m_name;
}

void Piece::setName(char name)
{

	m_name = name;

}

Point& Piece::getLoc()
{

	return m_loc;
}

void Piece::setLoc(const Point& p)
{
	m_loc = p;
}

const int Piece::getColor()
{
	return m_color;
}

void Piece::setColor(int color)
{
	m_color = color;

}

bool Piece::operator==(const Piece& p)
{
	
	if (m_name == p.m_name && m_color == p.m_color) {
		return true;
	}

	return false;

}

