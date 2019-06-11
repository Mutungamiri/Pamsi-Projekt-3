#ifndef BOARD_HH
#define BOARD_HH

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Board
{
private:

	int** board;
	int size;
	int winrow;
	int movecount;
	int last[2];

public:

	// Konstruktor
	Board() {

	}

	// Destruktor
	virtual ~Board() {
		delete[] board;
		board = NULL;
	}

	// Ładowanie planszy
	void Initial(int r, int w);
	// Potrzebna do funkcji wyswietl
	char Sign(int i, int j);
	// Wyswietlanie planszy
	void Display();
	// Wstawinie znaku
	void SetSign(int i, int j, int sign);
	// Sprwdzanie zwyciezcy
	int CheckWinner();

	int ReturnSize();
	int ReturnSign(int i, int j);
	int ReturnWinRow();
};

#endif
