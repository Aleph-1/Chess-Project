#include "Grid.h"
#include "Piece.h"
#include <math.h>
using namespace std;

Grid::Grid()
{


	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			m_grid[i][j] = NULL;
		}
	}

	m_grid[0][0] = new Piece(0, 0, 'R', 0); // Thing that goes in parallel
	m_grid[0][1] = new Piece(0, 1, 'H', 0); // Horse
	m_grid[0][2] = new Piece(0, 2, 'B', 0); // Diagonal thing
	m_grid[0][3] = new Piece(0, 3, 'Q', 0); // Queen
	m_grid[0][4] = new Piece(0, 4, 'K', 0); // King
	m_grid[0][5] = new Piece(0, 5, 'B', 0); // Diagonal thing
	m_grid[0][6] = new Piece(0, 6, 'H', 0); // Horse
	m_grid[0][7] = new Piece(0, 7, 'R', 0); // Thing that goes in parallel



	m_grid[7][0] = new Piece(7, 0, 'R', 1); // Thing that goes in parallel
	m_grid[7][1] = new Piece(7, 1, 'H', 1); // Horse
	m_grid[7][2] = new Piece(7, 2, 'B', 1); // Diagonal thing
	m_grid[7][3] = new Piece(7, 3, 'Q', 1); // Queen
	m_grid[7][4] = new Piece(7, 4, 'K', 1); // King
	m_grid[7][5] = new Piece(7, 5, 'B', 1); // Diagonal thing
	m_grid[7][6] = new Piece(7, 6, 'H', 1); // Horse
	m_grid[7][7] = new Piece(7, 7, 'R', 1); // Thing that goes in parallel



	for (int i = 0; i < 8; i++) {
			m_grid[1][i] = new Piece(1,i,'P',0); // Pawn.
	}

	for (int i = 0; i < 8; i++) {
		m_grid[6][i] = new Piece(6,i,'P',1); // Pawn.
	}


}

Piece* Grid::getGrid(Point p)
{
	return m_grid[p.m_x][p.m_y];
}




void Grid::setGrid(Point& p, Piece& s)
{

	m_grid[p.m_x][p.m_y] = new Piece(s);

}


void Grid::PrintGrid()
{

	cout << "    A   B   C   D   E   F   G   H" << endl;

	for (int i = 0; i < 8; i++) {

		cout << i + 1 << " ";

		for (int j = 0; j < 8; j++) {
			if (i >= 2 && i < 6) {
				if (m_grid[i][j] != NULL) {
					std::cout << "|" << "0" << m_grid[i][j]->getName() << "|";
				}
				else {

					std::cout << "|  |";
				}
			}
			else {
				if (i <= 2) {
					if (m_grid[i][j] != NULL) {
						std::cout << "|" << 0 << m_grid[i][j]->getName() << "|";
					}
					else {
						std::cout << "|  |";
					}
				}
				else if (i >= 6) {
					std::cout << "|" << 1 << m_grid[i][j]->getName() << "|";
				}
			}
		}
		std::cout << '\n';
	}

}

void Grid::movePoints(Piece& f, const Point& t)
{

	this->m_grid[t.m_x][t.m_y] = this->m_grid[f.getLoc().m_x][f.getLoc().m_y];
	this->m_grid[f.getLoc().m_x][f.getLoc().m_y] = NULL;
	f.setLoc(t);



}


bool Grid::pawnCheck(Piece& p, const Point& to) {

	if (this->getGrid(to) != NULL) {
		return false;
	}

	if (p.getLoc().m_x == 1 || p.getLoc().m_x == 6) {
		if (to.m_x == p.getLoc().m_x + 1 || to.m_x == p.getLoc().m_x + 2) {
			movePoints(p, to);
			return true;
		}
	}
	else if (to.m_x == p.getLoc().m_x + 1) {
		movePoints(p, to);
		return true;
	}

	return false;

}


bool Grid::rookCheck(Piece& p, const Point& to) {

	//Might be some Problems 
		//TODO - Maybe to fix?

	if (this->getGrid(to) != NULL) {
		return false;
	}
	if (to.m_y == p.getLoc().m_y || to.m_x == p.getLoc().m_x) {

		for (int i = p.getLoc().m_x + 1; i < to.m_x; i++) {
			if (m_grid[i][to.m_y] != NULL) {
				return false;
			}
		}

		movePoints(p, to);
		return true;
	}

	return false;

}


bool Grid::horseCheck(Piece& p, const Point& to) {


	//The diffrences between the x and y values are always 1 or 2 thats the check later

	if (this->getGrid(to) != NULL && to.m_x >= 0 && to.m_x <= 8 && to.m_y >= 0 && to.m_y <= 8) {
		return false;
	}

	if (abs(p.getLoc().m_x - to.m_x) > 2 || abs(p.getLoc().m_y - to.m_y) > 2) {
		return false;
	}

	if ((to.m_x - 1 == p.getLoc().m_x || to.m_x - 2 == p.getLoc().m_x ||
		to.m_x + 1 == p.getLoc().m_x || to.m_x + 2 == p.getLoc().m_x)
		&& (to.m_y - 1 == p.getLoc().m_y || to.m_y - 2 == p.getLoc().m_y ||
			to.m_y + 1 == p.getLoc().m_y || to.m_y + 2 == p.getLoc().m_y)) {

		movePoints(p, to);
		return true;

	}

	return false;

}

bool Grid::bishopCheck(Piece& p, const Point& to) {

	//Might be some Problems 
		//TODO - Maybe to fix?

	if (this->getGrid(to) != NULL) {
		return false;
	}

	int x_dist = abs(to.m_x - p.getLoc().m_x);
	int y_dist = abs(to.m_y - p.getLoc().m_y);


		

		if ((p.getLoc().m_x + x_dist == to.m_x && p.getLoc().m_y + y_dist == to.m_y) ||
			(p.getLoc().m_x + x_dist == to.m_x && p.getLoc().m_y - y_dist == to.m_y) ||
			(p.getLoc().m_x - x_dist == to.m_x && p.getLoc().m_y + y_dist == to.m_y) ||
			(p.getLoc().m_x - x_dist == to.m_x && p.getLoc().m_y - y_dist == to.m_y)) {


			if (to.m_x > p.getLoc().m_x) {

				if (to.m_y > p.getLoc().m_y) {

					int j = p.getLoc().m_y + 1;
					for (int i = p.getLoc().m_x + 1; i < to.m_x, j < to.m_y; i++, j++) {
						if (m_grid[i][j] != NULL) {
							return false;
						}
					}

				}
				else {

					int j = to.m_y;
					for (int i = to.m_x ; i != p.getLoc().m_x, j != p.getLoc().m_y; i--, j++) {
						if (m_grid[i][j] != NULL) {
							return false;
						}
					}



				}
				movePoints(p, to);
				return true;


			}

			if (to.m_x < p.getLoc().m_x) {

				if (to.m_y > p.getLoc().m_y) {

					int j = p.getLoc().m_y + 1;
					for (int i = p.getLoc().m_x - 1; i != to.m_x, j < to.m_y; i--, j++) {
						if (m_grid[i][j] != NULL) {
							return false;
						}
					}

				}

				else {

					int j = to.m_y;
					for (int i = to.m_x; i != p.getLoc().m_x, j != p.getLoc().m_y; i++, j++) {
						if (m_grid[i][j] != NULL) {
							return false;
						}
					}



				}
				movePoints(p, to);
				return true;


			}
		}
			


	return false;

}

bool Grid::kingCheck(Piece& p, const Point& to) {

	if (this->getGrid(to) != NULL) {
		return false;
	}

	if ((to.m_x - 1 == p.getLoc().m_x || to.m_x == p.getLoc().m_x ||
		to.m_x + 1 == p.getLoc().m_x || to.m_x == p.getLoc().m_x)
		&& (to.m_y - 1 == p.getLoc().m_y || to.m_y == p.getLoc().m_y ||
			to.m_y + 1 == p.getLoc().m_y || to.m_y == p.getLoc().m_y)) {

		movePoints(p, to);
		return true;

	}

	return false;

}

bool Grid::queenCheck(Piece& p, const Point& to) {


	if (rookCheck(p, to)) {
		return true;
	}

	if (bishopCheck(p, to)) {
		return true;
	}


	return false;




}




//TODO - Add Movement
bool Grid::isValidMove(Piece& p, const Point& to)
{


	if (p.getName() == 'P') {

		return pawnCheck(p, to);

	}

	if (p.getName() == 'R') {

		return rookCheck(p, to);

	}

	if (p.getName() == 'H') {

	
		return horseCheck(p, to);

	}


	if (p.getName() == 'B') {

		return bishopCheck(p, to);

	}

	if (p.getName() == 'K') {

		return kingCheck(p, to);

	}

	if (p.getName() == 'Q') {

		return queenCheck(p, to);

	}





	
}
