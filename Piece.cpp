#include "Piece.h"

Piece::Piece(Point a, char name, bool color) : m_loc(a)
{
	m_name = name;
	m_color = color;
}

Piece::Piece(int x, int y, char name, bool color) :m_loc(x, y)
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

const Point& Piece::getLoc()
{

	return m_loc;

	// TODO: insert return statement here
}

void Piece::setLoc(const Point& p)
{
	m_loc = p;
}

const bool Piece::getColor()
{
	return m_color;
}

