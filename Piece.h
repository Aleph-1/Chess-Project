#pragma once

#include "Point.h"
#include <string.h>

class Piece
{
public:
	Piece(Point a, char name, int color);
	Piece(int x, int y, char name, int color);// Ctor
	Piece(const Piece& p);

public:
	const char getName();
	void setName(char name);
	//It's not safe try to change
	Point& getLoc();
	void setLoc(const Point& p);
	const int getColor();
	void setColor(int color);
	static int count;
	void operator=(int x) {
		this->m_name = x;
	}

	bool operator==(const Piece& p);
    

private:

	char m_name;
	Point m_loc;
	int m_color;

};




