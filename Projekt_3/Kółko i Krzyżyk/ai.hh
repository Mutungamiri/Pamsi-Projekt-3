#ifndef AI_HH
#define AI_HH

#include <stdio.h>
#include <vector>
#include "board.hh"

using namespace std;

struct Move {

	Move() : score(0) {};
	Move(int s) : score(s) {}

	int w;
	int k;
	int score;
};

class AI
{
private:

	int artint;
	int Player;
	int deph;
	int size;
	int winrow;

public:

	// Konstruktor
	AI();
	// Destruktor
	virtual ~AI();

	// Ladowanie komputera
	void Initial(Board& board);
	// Algorytm zwracajacy najlepszy mozliwy ruch
	Move AlphaBetaMiniMax(Board& board, int alpha, int beta, int player, int deph, bool rek);
	// Funkcja wstawiajaca ruch komputera
	void AIMove(Board& board);
};


#endif

