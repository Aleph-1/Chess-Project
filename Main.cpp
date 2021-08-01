
#include "Grid.h"
#include "Piece.h"
using namespace std;

int main() {


	Point a(1, 'A');
	Piece Queen(a, 'Q', 1);
	Grid A;
	A.PrintGrid();
	Point t(3, 'B');
	A.movePoints(a, t);
	A.PrintGrid();

	


}