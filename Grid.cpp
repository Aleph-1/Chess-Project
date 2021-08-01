#include "Grid.h"
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

	cout << "    A   B  C  D  E  F  G  H"<<endl;

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

void Grid::movePoints(Point& f, Point& t)
{

	this->m_grid[t.m_x][t.m_y] = this->m_grid[f.m_x][f.m_y];
	this->m_grid[f.m_x][f.m_y] = NULL;


}

bool Grid::isValidMove(const Piece& p, const Point& from, const Point& to)
{





	return false;
}