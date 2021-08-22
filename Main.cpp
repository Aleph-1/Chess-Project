
#include "Grid.h"
#include "Piece.h"
using namespace std;

//TODO: Add black won cout

bool game(Grid grid) {

	Piece King0(Point(1, 'E'), 'K', 0);
	Piece King1(Point(8, 'E'), 'K', 1);


	Point from(0, 0);
	Point to(1, 1);
	bool isValidMoveSuc = false; // Is valid move succesful
	bool canIEatSuc = false;
	bool check; // Check if there's not any check
	bool all = false;

	while (grid.onBoard(King0) && grid.onBoard(King1)) {

		check = false;

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


			
			if (grid.isCheck(*(grid.getGrid(from)),to,0)) {
				cout << "Check On White!"  << endl;
				check = true;
			}
		
			if (!check) {
				isValidMoveSuc = grid.isValidMove(*(grid.getGrid(from)), to, 0);
			}

			if (!check) {
				canIEatSuc = grid.canIEat(*(grid.getGrid(from)), to, 0);
			}


		} while ( (!isValidMoveSuc && !canIEatSuc) || check);
		
		check = false;

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
					
					
					if (grid.isCheck(*(grid.getGrid(from)), to, 1)) {
						cout << "Check On Black!" << endl;
						check = true;
					}

					if (!check) {
						isValidMoveSuc = grid.isValidMove(*(grid.getGrid(from)), to, 1);
					}

					if (!check) {
						canIEatSuc = grid.canIEat(*(grid.getGrid(from)), to, 1);
					}


			} while ((!isValidMoveSuc && !canIEatSuc) || check);

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

}