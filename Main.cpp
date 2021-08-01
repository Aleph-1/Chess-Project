
#include "Grid.h"
#include "Piece.h"
using namespace std;

int main() {


	Point a(1, 'A');
	Piece Queen(a, 'Q', 1);
	Grid A;
	Point q(1, 'A');
	Point s(2, 'A');
	Point p(3, 'A');
	Point t(2, 'B');
	Point z(3, 'B');
	Point y(5, 'A');
	Point k(5, 'F');

	Piece pq(q, 'R', 0);
	Piece ps(s, 'P', 0);

	A.PrintGrid();

	bool ab = A.isValidMove(ps, p);
	A.movePoints(ps, z);
	A.isValidMove(pq, s);
	A.PrintGrid();



	A.isValidMove(pq, y);
	A.PrintGrid();

	A.isValidMove(pq, k);


	A.PrintGrid();
	


}