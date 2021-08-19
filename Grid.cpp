#include "Grid.h"
#include "Piece.h"
#include <math.h>
using namespace std;

Grid::Grid()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			m_grid[i][j] = new Piece(Point(i,j),'D',0);
		}
	}


	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			*(m_grid[i][j]) = NULL;
		}
	}

	m_grid[0][0] = new Piece(Point(1, 'A'), 'R', 0); // Thing that goes in parallel
	m_grid[0][1] = new Piece(Point(1, 'B'), 'H', 0); // Horse
	m_grid[0][2] = new Piece(Point(1, 'C'), 'B', 0); // Diagonal thing
	m_grid[0][3] = new Piece(Point(1, 'D'), 'Q', 0); // Queen
	m_grid[0][4] = new Piece(Point(1, 'E'), 'K', 0); // King
	m_grid[0][5] = new Piece(Point(1, 'F'), 'B', 0); // Diagonal thing
	m_grid[0][6] = new Piece(Point(1, 'G'), 'H', 0); // Horse
	m_grid[0][7] = new Piece(Point(1, 'H'), 'R', 0); // Thing that goes in parallel



	m_grid[7][0] = new Piece(Point(8, 'A'), 'R', 1); // Thing that goes in parallel
	m_grid[7][1] = new Piece(Point(8, 'B'), 'H', 1); // Horse
	m_grid[7][2] = new Piece(Point(8, 'C'), 'B', 1); // Diagonal thing
	m_grid[7][3] = new Piece(Point(8, 'D'), 'Q', 1); // Queen
	m_grid[7][4] = new Piece(Point(8, 'E'), 'K', 1); // King
	m_grid[7][5] = new Piece(Point(8, 'F'), 'B', 1); // Diagonal thing
	m_grid[7][6] = new Piece(Point(8, 'G'), 'H', 1); // Horse
	m_grid[7][7] = new Piece(Point(8, 'H'), 'R', 1); // Thing that goes in parallel



	for (int i = 0; i < 8; i++) {
			m_grid[1][i] = new Piece(Point(2,i+65),'P',0); // Pawn.
	}

	for (int i = 0; i < 8; i++) {
		m_grid[6][i] = new Piece(Point(7,i+65),'P',1); // Pawn.
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
		if (m_grid[i][j]->getName() != NULL) {
			if (m_grid[i][j]->getColor() != 2) {
				std::cout << "|" << m_grid[i][j]->getColor() << m_grid[i][j]->getName() << "|";
			}
			else {
				std::cout << "|  |";
			}
		}
		else {

			std::cout << "|  |";
		}
	}
	else {
		if (i <= 2) {
			if (m_grid[i][j]->getName() != NULL) {
				if (m_grid[i][j]->getColor() != 2) {
					std::cout << "|" << m_grid[i][j]->getColor() << m_grid[i][j]->getName() << "|";
				}
				else {
					std::cout << "|  |";
				}
			}
			else {
				std::cout << "|  |";
			}
		}
		else if (i >= 6 && m_grid[i][j]->getName() != NULL) {
			std::cout << "|" << m_grid[i][j]->getColor() << m_grid[i][j]->getName() << "|";
		}
		else {
			std::cout << "|  |";
		}
	}
}
std::cout << '\n';
	}

}

bool Grid::onBoard(Piece& p)
{

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (m_grid[i][j]->getName() != NULL && *(m_grid[i][j]) == p) {
				return true;
			}
		}
	}

	return false;

}

void Grid::movePoints(Piece& f, const Point& t)
{

	//Not good the last piece is wasted because we don't have a pointer to the memory of that.

	this->m_grid[t.m_x][t.m_y] = new Piece(t, f.getName(), f.getColor());
	this->m_grid[f.getLoc().m_x][f.getLoc().m_y]->setName(NULL);
	this->m_grid[f.getLoc().m_x][f.getLoc().m_y]->setColor(2);

}

void Grid::movePointsEat(Piece& f, const Point& t, int color)
{


	this->m_grid[t.m_x][t.m_y] = new Piece(t, f.getName(), f.getColor());
	this->m_grid[f.getLoc().m_x][f.getLoc().m_y]->setName(NULL);
	this->m_grid[f.getLoc().m_x][f.getLoc().m_y]->setColor(2);

	if (color == 0) {
		this->m_grid[f.getLoc().m_x][f.getLoc().m_y]->setColor(1);
	}
	else {
		this->m_grid[f.getLoc().m_x][f.getLoc().m_y]->setColor(0);
	}


	f.setLoc(t);



}


bool Grid::pawnCheck(Piece& p, const Point& to) {

	if (this->getGrid(to)->getName() != NULL) {
		return false;
	}

	if (p.getLoc().m_x == 1 || p.getLoc().m_x == 6) {
		if (p.getColor() == 0 && (p.getLoc().m_x + 1 == to.m_x || to.m_x == p.getLoc().m_x + 2) && p.getLoc().m_y == to.m_y) {
			movePoints(p, to);
			return true;
		}


		if (p.getColor() == 1 && (p.getLoc().m_x - 1 || to.m_x == p.getLoc().m_x - 2) && p.getLoc().m_y == to.m_y) {
			movePoints(p, to);
			return true;
		}
	}
	else {

		if (p.getColor() == 0 && (p.getLoc().m_x + 1 == to.m_x) && p.getLoc().m_y == to.m_y){
			movePoints(p, to);
			return true;
		}
		else {
			if (p.getColor() == 1 && (p.getLoc().m_x -1 == to.m_x) && p.getLoc().m_y == to.m_y) {
				movePoints(p, to);
				return true;
			}
		}

	}

	return false;

}


bool Grid::rookCheck(Piece& p,  const Point& to) {

	//Might be some Problems 
		//TODO - Maybe to fix?

	if (this->getGrid(to)->getName() != NULL) {
		return false;
	}
	if (to.m_y == p.getLoc().m_y || to.m_x == p.getLoc().m_x) {

		for (int i = p.getLoc().m_x + 1; i < to.m_x; i++) {
			if (m_grid[i][to.m_y]->getName() != NULL) {
				return false;
			}
		}

		movePoints(p, to);
		return true;
	}

	return false;

}


bool Grid::horseCheck(Piece& p,  const Point& to) {


	//The diffrences between the x and y values are always 1 or 2 thats the check later

	if (this->getGrid(to)->getName() != NULL && to.m_x >= 0 && to.m_x <= 8 && to.m_y >= 0 && to.m_y <= 8) {
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

bool Grid::bishopCheck(Piece& p,  const Point& to) {

	//Might be some Problems 
	//TODO - To fix!



	if (this->getGrid(to)->getName() != NULL) {
		return false;
	}

	int dist = abs(to.m_x - p.getLoc().m_x);



		

		if ((p.getLoc().m_x + dist == to.m_x && p.getLoc().m_y + dist == to.m_y) ||
			(p.getLoc().m_x + dist == to.m_x && p.getLoc().m_y - dist == to.m_y) ||
			(p.getLoc().m_x - dist == to.m_x && p.getLoc().m_y + dist == to.m_y) ||
			(p.getLoc().m_x - dist == to.m_x && p.getLoc().m_y - dist == to.m_y)) {


			if (to.m_x > p.getLoc().m_x) {

				if (to.m_y > p.getLoc().m_y) {

					int j = p.getLoc().m_y + 1;
					for (int i = p.getLoc().m_x + 1; i < to.m_x; i++, j++) {
						if (m_grid[i][j]->getName() != NULL && j < to.m_y) {
							return false;
						}
					}

				}
				else {

					int j = to.m_y;
					for (int i = to.m_x ; i != p.getLoc().m_x, j != p.getLoc().m_y; i--, j++) {
						if (m_grid[i][j]->getName() != NULL) {
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
						if (m_grid[i][j]->getName() != NULL) {
							return false;
						}
					}

				}

				else {

					int j = to.m_y;
					for (int i = to.m_x; i != p.getLoc().m_x, j != p.getLoc().m_y; i++, j++) {
						if (m_grid[i][j]->getName() != NULL) {
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

bool Grid::kingCheck(Piece& p,  const Point& to) {

	if (this->getGrid(to)->getName() != NULL) {
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

bool Grid::queenCheck(Piece& p,  const Point& to) {


	if (rookCheck(p, to)) {
		return true;
	}

	if (bishopCheck(p, to)) {
		return true;
	}


	return false;

}


//TODO: Fix eating backwards for white
bool Grid::pawnEat(Piece& p, const Point& to, int color)
{

	if (this->getGrid(to)->getName() == NULL && this->getGrid(to)->getColor() == color) {
		return false;
	}

	if ((p.getLoc().m_x + 1 == to.m_x && p.getLoc().m_y + 1 == to.m_y) || (p.getLoc().m_x + 1 == to.m_x && p.getLoc().m_y - 1 == to.m_y) && p.getColor() == 0) {

		movePoints(p, to);
		return true;

	}

	if(((p.getLoc().m_x - 1 == to.m_x && p.getLoc().m_y + 1 == to.m_y) || (p.getLoc().m_x - 1 == to.m_x && p.getLoc().m_y - 1 == to.m_y)) && p.getColor() == 1){

		movePoints(p, to);
		return true;

	}

	return false;

}

bool Grid::rookEat(Piece& p, const Point& to, int color)
{
	if (this->getGrid(to)->getName() != NULL && this->getGrid(to)->getColor() == color) {
		return false;
	}

	if (to.m_y == p.getLoc().m_y || to.m_x == p.getLoc().m_x) {

		for (int i = p.getLoc().m_x + 1; i < to.m_x; i++) {
			if (m_grid[i][to.m_y]->getName() != NULL) {
				return false;
			}
		}

		movePoints(p, to);
		return true;
	}


	return false;
}

bool Grid::horseEat(Piece& p, const Point& to, int color)
{


	if (this->getGrid(to)->getName() != NULL && this->getGrid(to)->getColor() == color) {
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

bool Grid::bishopEat(Piece& p, const Point& to,int color)
{

	if (this->getGrid(to)->getName() != NULL && this->getGrid(to)->getColor() == color) {
		return false;
	}

	int dist = abs(to.m_x - p.getLoc().m_x);





	if ((p.getLoc().m_x + dist == to.m_x && p.getLoc().m_y + dist == to.m_y) ||
		(p.getLoc().m_x + dist == to.m_x && p.getLoc().m_y - dist == to.m_y) ||
		(p.getLoc().m_x - dist == to.m_x && p.getLoc().m_y + dist == to.m_y) ||
		(p.getLoc().m_x - dist == to.m_x && p.getLoc().m_y - dist == to.m_y)) {


		if (to.m_x > p.getLoc().m_x) {

			if (to.m_y > p.getLoc().m_y) {

				int j = p.getLoc().m_y + 1;
				for (int i = p.getLoc().m_x + 1; i < to.m_x, j < to.m_y; i++, j++) {
					if (m_grid[i][j]->getName() != NULL) {
						return false;
					}
				}

			}
			else {

				int j = to.m_y;
				for (int i = to.m_x; i != p.getLoc().m_x, j != p.getLoc().m_y; i--, j++) {
					if (m_grid[i][j]->getName() != NULL) {
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
					if (m_grid[i][j]->getName() != NULL) {
						return false;
					}
				}

			}

			else {

				int j = to.m_y;
				for (int i = to.m_x; i != p.getLoc().m_x, j != p.getLoc().m_y; i++, j++) {
					if (m_grid[i][j]->getName() != NULL) {
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


//TODO: Add content

bool Grid::kingEat(Piece& p, const Point& to, int color)
{

	if (this->getGrid(to)->getName() != NULL && this->getGrid(to)->getColor() == color) {
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


bool Grid::bishopEatForQueen(Piece& p, const Point& to, int color) {

	int dist = abs(to.m_x - p.getLoc().m_x);

	if ((p.getLoc().m_x + dist == to.m_x && p.getLoc().m_y + dist == to.m_y) ||
		(p.getLoc().m_x + dist == to.m_x && p.getLoc().m_y - dist == to.m_y) ||
		(p.getLoc().m_x - dist == to.m_x && p.getLoc().m_y + dist == to.m_y) ||
		(p.getLoc().m_x - dist == to.m_x && p.getLoc().m_y - dist == to.m_y)) {


		if (to.m_x > p.getLoc().m_x) {

			if (to.m_y > p.getLoc().m_y) {

				int j = p.getLoc().m_y + 1;
				for (int i = p.getLoc().m_x + 1; i < to.m_x, j < to.m_y; i++, j++) {
					if (m_grid[i][j]->getName() != NULL) {
						return false;
					}
				}

			}
			else {

				int j = to.m_y;
				for (int i = to.m_x; i != p.getLoc().m_x, j != p.getLoc().m_y; i--, j++) {
					if (m_grid[i][j]->getName() != NULL) {
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
					if (m_grid[i][j]->getName() != NULL) {
						return false;
					}
				}

			}

			else {

				int j = to.m_y;
				for (int i = to.m_x; i != p.getLoc().m_x, j != p.getLoc().m_y; i++, j++) {
					if (m_grid[i][j]->getName() != NULL) {
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


bool Grid::rookEatQueen(Piece& p, const Point& to, int color) {

	if (to.m_y == p.getLoc().m_y || to.m_x == p.getLoc().m_x) {

		for (int i = p.getLoc().m_x + 1; i < to.m_x; i++) {
			if (m_grid[i][to.m_y]->getName() != NULL) {
				return false;
			}
		}

		movePoints(p, to);
		return true;
	}

	return false;
}

//TODO: Add content
bool Grid::queenEat(Piece& p, const Point& to, int color)
{

	if (this->getGrid(to)->getName() != NULL && this->getGrid(to)->getColor() == color) {
		return false;
	}

	if (bishopEatForQueen(p, to, color) || rookEatQueen(p, to, color)) {
		return true;
	}

	return false;
}




//TODO - Add Movement
bool Grid::isValidMove(Piece p,  const Point& to, int color)
{

	if (p.getColor() != color) {
		return false;
	}


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

	return false;
	
}

bool Grid::canIEat(Piece p, const Point& to, int color)
{

	if (p.getColor() != color) {
		return false;
	}

	if (p.getName() == 'P') {
		return pawnEat(p, to, color);
	}

	if (p.getName() == 'R') {
		return rookEat(p, to, color);
	}

	if (p.getName() == 'H') {
		return horseEat(p, to, color);
	}

	if (p.getName() == 'B') {
		return bishopEat(p, to, color);
	}

	if (p.getName() == 'K') {
		return kingEat(p, to, color);
	}

	if (p.getName() == 'Q') {

		return queenEat(p, to, color);
		return false;
	}

	return false;
}
