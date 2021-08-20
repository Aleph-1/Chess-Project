
#include "Grid.h"
#include "Piece.h"
using namespace std;

//TODO: Add black won cout

bool game(Grid grid) {

	Piece King0(Point(1, 'E'), 'K', 0);
	Piece King1(Point(8, 'E'), 'K', 1);


	Point from(0, 0);
	Point to(1, 1);

	while (grid.onBoard(King0) && grid.onBoard(King1)) {

		do {

			grid.PrintGrid();

			cout << "White's turn enter location from:" << "\n";
			int x;
			char y;
			cout << "X coordinate:" << "\n";
			cin >> x;
			cout << "Y coordinate:" << "\n";
			cin >> y;

			from.m_x = x-1;
			from.m_y = y-65;

			cout << "White's turn enter location to:" << "\n";
			cout << "X coordinate:" << "\n";
			cin >> x;
			cout << "Y coordinate:" << "\n";
			cin >> y;

			to.m_x = x - 1;
			to.m_y = y-65;

		} while (!grid.isValidMove(*(grid.getGrid(from)), to,0) && !grid.canIEat(*(grid.getGrid(from)),to,0));
		


		if (grid.onBoard(King0) && grid.onBoard(King1)) {

			do {

				grid.PrintGrid();

				cout << "Black's turn enter location from:" << "\n";
					int x;
					char y;
					cout << "X coordinate:" << "\n";
					cin >> x;
					cout << "Y coordinate:" << "\n";
					cin >> y;

					from.m_x = x - 1;
					from.m_y = y - 65;

					cout << "Black's turn enter location to:" << "\n";
					cout << "X coordinate:" << "\n";
					cin >> x;
					cout << "Y coordinate:" << "\n";
					cin >> y;

					to.m_x = x - 1;
					to.m_y = y - 65;

			} while (!grid.isValidMove(*(grid.getGrid(from)), to,1) && !grid.canIEat(*(grid.getGrid(from)), to,1));

		}

		if (!grid.onBoard(King0)) {
			cout << "Black's Won Congrats!";
		}

		if(!grid.onBoard(King1)){
			cout << "White's Won Congrats!";
		}


	}

	return 0;
}


int main() {

	Point a(3, 'A');
	Piece Queen(Point(1, 'D'), 'Q', 0);
	Piece King(Point(1, 'E'), 'K', 0);
	Piece Bishop(Point(1,'C'), 'B', 0);
	Piece Horse(Point(1, 'B'), 'H', 0);
	Piece Pawn(Point(2, 'D'), 'P', 0);
	Grid A;
	game(A);




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