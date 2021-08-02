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
	bool pawnCheck(Piece& p, const Point& to);
	bool rookCheck(Piece& p, const Point& to);
	bool horseCheck(Piece& p, const Point& to);
	bool bishopCheck(Piece& p, const Point& to);
	bool kingCheck(Piece& p, const Point& to);
	bool queenCheck(Piece& p, const Point& to);
	bool isValidMove(Piece& p, const Point& to);
	

private:
	Piece* m_grid[8][8]; // The grid it self.

};
