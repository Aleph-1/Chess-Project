#pragma once

#include "Point.h"
#include <string.h>

class Piece
{
public:
	Piece(Point a, char name, bool color);
	Piece(int x, int y, char name, bool color);// Ctor
	Piece(const Piece& p);

public:
	const char getName();
	const Point& getLoc();
	void setLoc(Point& p);
	const bool getColor();
	static int count;
    

private:

	char m_name;
	Point m_loc;
	bool m_color;

};




