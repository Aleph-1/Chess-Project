#pragma once
#include <iostream>
#include "Piece.h"
#include "Point.h"

class Grid
{
public:
	Grid(); // Default Ctor

public:
	Piece* getGrid(Point p);
	void setGrid(Point& p, Piece& s); // The ch is the char that the place will be set to.
	void PrintGrid();
	void movePoints(Piece& f, const Point& t);
	bool isValidMove(Piece& p, const Point& to);
	

private:
	Piece* m_grid[8][8]; // The grid it self.

};
