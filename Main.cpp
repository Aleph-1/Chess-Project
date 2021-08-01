
#include "Grid.h"
#include "Piece.h"
using namespace std;

int main() {


	Point a(1, 'A');
	Piece Queen(a, 'Q', 1);
	Grid A;
	Point p(2, 'A');
	Point q(4, 'A');
	Piece pq(p, 'P', 0);

	A.PrintGrid();

	bool ab = A.isValidMove(pq,p, q);
	A.PrintGrid();

	


}