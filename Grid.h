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
	bool onBoard(Piece& p);
	void movePoints(Piece& f, const Point& t);
	void movePointsEat(Piece& f, const Point& t, int color);
	bool isValidMove(Piece p, const Point& to, int color);
	bool canIEat(Piece p, const Point& to, int color);


public:
	bool pawnCheck(Piece& p, const Point& to);
	bool rookCheck(Piece& p, const Point& to);
	bool horseCheck(Piece& p, const Point& to);
	bool bishopCheck(Piece& p, const Point& to);
	bool kingCheck(Piece& p, const Point& to);
	bool queenCheck(Piece& p, const Point& to);

	bool pawnEat(Piece& p, const Point& to, int color);
	bool rookEat(Piece& p, const Point& to, int color);
	bool horseEat(Piece& p, const Point& to, int color);
	bool bishopEat(Piece& p, const Point& to, int color);
	bool kingEat(Piece& p, const Point& to, int color);
	bool bishopEatForQueen(Piece& p, const Point& to, int color);
	bool rookEatQueen(Piece& p, const Point& to, int color);
	bool queenEat(Piece& p, const Point& to, int color);
	
	

private:
	Piece* m_grid[8][8]; // The grid it self.

};
