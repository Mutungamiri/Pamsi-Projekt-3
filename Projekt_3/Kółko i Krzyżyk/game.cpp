#include <iostream>
#include <cstdlib>
#include "game.hh"
using namespace std;

// Konstruktor
Game::Game() { }

// Destruktor
Game::~Game() { }

/* Funkcja ladujaca gre */

void Game::Initial() {

	int size;
	int winrow;

	state = 2;
	size = winrow = 0;

	// Podawanie rozmiaru planszy i ilosci znakow w rzedzie przez uzytkownika
	// programu

	// ROZMIAR PLANSZY
	cout << "Wybierz rozmiar planszy (od 3 do 5):" << endl;

	while (1)
	{
		while (!(cin >> size)) { cout << "B��dna warto��" << endl; }

		if (size >= 3 && size < 10) break;

		else
			cout << "B��dna warto��" << endl;

	}
	// WYGRYWAJACY CIAG

	cout << "Podaj d�ugo�� ci�gu kt�ry ma wygrywa� gr�:" << endl;

	while (1)
	{
		while (!(cin >> winrow))
		{
			cout << "B��dna warto��" << endl;
		}
		if (winrow >= 3 && winrow <= size) break;

		else
			cout << "B��dna warto��" << endl;

	}

	// LADOWANIE PLANSZY
	// I OBIEKTU KOMPUTER

	board.Initial(size, winrow);
	artint.Initial(board);

	cout << "1 - zaczyna gracz" << endl;
	cout << "2 - zaczyna komputer" << endl;

	// WYBOR KTO ZACZYNA

	while (1)
	{
		while (!(cin >> player))
		{
			cout << "B��dna warto��" << endl;
		}

		if (player == 1 || player == 2) break;

		else
			cout << "B��dna warto��" << endl;
	}
}

/* Funkcja kontrolujaca przebieg gry*/
void Game::Process() {

	while (1) {

		Initial();

		while (state == 2)
		{
			board.Display();

			if (player == 1) PlayerMove();

			else

				artint.AIMove(board);
			state = board.CheckWinner();
			ChangePlayer();
		}
		board.Display();

		if (state == 0)
		{
			cout << "REMIS" << endl;
			break;
		}

		else if (state == 1)
		{
			cout << "WYGRA�E�" << endl;
			break;
		}

		else if (state == -1)
		{
			cout << "PRZEGRA�E�" << endl;
			break;
		}
	}

}

/* Funkcja obslugujaca ruch gracza */
void Game::PlayerMove() {

	int w, k;
	bool change = 0;

	cout << "Twoja kolej" << endl;
	cout << "Podaj pole kt�re chcesz zaznaczy� (Wiersz Kolumna)" << endl;

	while (!change)
	{
		while (!(cin >> w)) {
			cout << "B��dna warto��" << endl;
		}

		while (!(cin >> k)) {
			cout << "B��dna warto��" << endl;
		}

		if (w >= 0 && w < board.ReturnSize() && k >= 0 && k < board.ReturnSize())

			if (board.ReturnSign(w, k) == 0)
			{
				board.SetSign(w, k, 1);
				change = 1;
			}

			else

				cout << "To pole zosta�o ju� wybrane" << endl;

		else

			cout << "Takie pole nie istnieje" << endl;
	}
}
