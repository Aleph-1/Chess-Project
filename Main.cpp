
#include "Grid.h"
#include "Piece.h"
using namespace std;

int main() {


	Point a(3, 'A');
	Piece Queen(Point(1, 'D'), 'Q', 0);
	Piece King(Point(1, 'E'), 'K', 0);
	Piece Bishop(Point(1,'C'), 'B', 0);
	Piece Horse(Point(1, 'B'), 'H', 0);
	Piece Pawn(Point(2, 'D'), 'P', 0);
	Grid A;
	A.PrintGrid();
	A.isValidMove(Pawn, Point(4, 'D'));
	A.PrintGrid();
	A.isValidMove(Queen, Point(3, 'D'));
	A.PrintGrid();
	A.isValidMove(Queen, Point(6, 'G'));
	A.PrintGrid();




	/*
	A.isValidMove(Pawn, Point(4,'E'));
	A.PrintGrid();
	A.isValidMove(King, Point(2, 'E'));
	A.PrintGrid();
	A.isValidMove(King, Point(3, 'E'));
	A.PrintGrid();
	A.isValidMove(King, Point(3, 'F'));
	A.PrintGrid();
	A.isValidMove(King, Point(2, 'F'));
	A.PrintGrid();
	A.isValidMove(Horse, Point(3, 'C'));
	A.PrintGrid();
	A.isValidMove(Horse, Point(4, 'E'));
	A.PrintGrid();
	*/



	


}