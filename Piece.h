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
	static int count;
    char getName();
	Point& getLoc();
	void setLoc(Point& p);
	bool getColor();
	

private:

	char m_name;
	Point m_loc;
	bool m_color;

};




