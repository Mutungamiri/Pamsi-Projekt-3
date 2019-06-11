#ifndef GAME_HH
#define GAME_HH

#include "board.hh"
#include "ai.hh"

using namespace std;

class Game
{
private:

	Board board;
	AI artint;
	int player;
	int state;

public:

	// Konstruktor
	Game();
	// Destruktor
	virtual ~Game();

	void Initial();
	void Process();
	void PlayerMove();
	void ChangePlayer()
	{
		(player == 1) ? player = 2 : player = 1;
	}
};

#endif
