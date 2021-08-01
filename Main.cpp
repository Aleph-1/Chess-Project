
#include "Grid.h"
#include "Piece.h"
using namespace std;

int main() {


	Point a(3, 'A');
	Piece Horse(Point(1,'B'), 'H', 0);
	Grid A;
	A.PrintGrid();
	A.isValidMove(Horse, Point(2,'D'));
	A.PrintGrid();






	


}