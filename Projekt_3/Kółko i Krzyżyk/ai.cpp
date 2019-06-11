#include "ai.hh"

using namespace std;

// Konstruktor
AI::AI() { }
// Destruktor
AI::~AI() { }

/*Funkcja inicjalizuje gracza komputer.*/

void AI::Initial(Board& board) {

	artint = -1;
	Player = 1;
	deph = 0;

	size = board.ReturnSize();
	winrow = board.ReturnWinRow();
}


/* Funkcja dla algorytmu minimax z cieciami alfa i beta oraz ocena uwzgledniajaca ilosc ruchu
	do zamierzonego rezultatu oraz ocena wybranego pola.*/

Move AI::AlphaBetaMiniMax(Board& board, int alpha, int beta, int player, int deph, bool rek) {

	int bestscore;
	int iterator = 0;

	int score = board.CheckWinner();
	Move move;
	vector<Move> moves;

	if (rek) deph++;

	if (score != 2)
		return (score == -1) ? Move(score * (-1000) - 20 * deph) : Move(score * (-1000) + 20 * deph);

	else if (player == artint)
	{
		bestscore = alpha;

		for (int i = 0; i < board.ReturnSize(); i++)
		{
			for (int j = 0; j < board.ReturnSize(); j++)
			{
				if (board.ReturnSign(i, j) == 0)
				{
					board.SetSign(i, j, player);

					move.score = AlphaBetaMiniMax(board, bestscore, beta, Player, deph, 1).score;
					move.w = i;
					move.k = j;
					moves.push_back(move);
					board.SetSign(i, j, 0);

					if (move.score > bestscore) bestscore = move.score;
					if (beta <= bestscore) i = j = board.ReturnSize();
				}
			}
		}

		bestscore = -10000;

		for (int i = 0; i < (int)moves.size(); i++)
		{
			if (moves[i].score > bestscore)
			{
				iterator = i;
				bestscore = moves[i].score;
			}
		}
	}

	else {

		bestscore = beta;

		for (int i = 0; i < board.ReturnSize(); i++)
		{
			for (int j = 0; j < board.ReturnSize(); j++)
			{
				if (board.ReturnSign(i, j) == 0)
				{
					board.SetSign(i, j, player);
					move.score = AlphaBetaMiniMax(board, alpha, bestscore, artint, deph, 1).score;
					move.w = i;
					move.k = j;
					moves.push_back(move);
					board.SetSign(i, j, 0);

					if (move.score < bestscore) bestscore = move.score;

					if (alpha >= bestscore) i = j = board.ReturnSize();
				}
			}
		}

		bestscore = 10000;

		for (int i = 0; i < (int)moves.size(); i++)
		{
			if (moves[i].score < bestscore)
			{
				iterator = i;
				bestscore = moves[i].score;
			}
		}
	}
	return moves[iterator];
}

/* Funkcja obslugujaca ruch komputera*/

void AI::AIMove(Board& board) {

	Move best;
	best = AlphaBetaMiniMax(board, -10000, 10000, artint, 0, 0);

	board.SetSign(best.w, best.k, artint);
}
