#include "board.hh"

using namespace std;

int Board::ReturnSize()
{
	return size;
}


int Board::ReturnSign(int i, int j)
{
	return board[i][j];
};

int Board::ReturnWinRow()
{
	return winrow;
}



/* Funkcja inicjalizuje plansze */

void Board::Initial(int r, int w) {

	size = r;
	winrow = w;
	movecount = 0;

	last[0] = last[1] = size;

	board = new int* [size];

	for (int i = 0; i < size; i++)
	{
		board[i] = new int[size];

		for (int j = 0; j < size; j++)
		{
			board[i][j] = 0;
		}
	}
}

/* Funkcja zwracajaca znak przypisany do wskazanego pola */

char Board::Sign(int i, int j) {

	if (board[i][j] == 1) return 'x';

	else if (board[i][j] == -1) return 'o';

	else return ' ';

}

/* Funkcja wyswietlajaca plansze */
void Board::Display() {

	// czyszczenie terminala
	system("clear");

	cout << "Rozmiar planszy: " << size << endl;
	cout << "Ci¹g który wygrywa: " << winrow << endl;
	cout << "Gracz - X   Komputer - O" << endl << endl;
	cout << "  ";

	for (int i = 0; i < this->size; i++) cout << " " << i;

	cout << endl;

	for (int i = 0; i < this->size; i++)
	{
		cout << i << " ";

		for (int j = 0; j < this->size; j++)
		{
			cout << "|" << Sign(i, j);
		}
		cout << "|" << endl;

		if (i != this->size - 1)
		{
			cout << "  +";
			for (int k = 0; k < this->size - 1; k++) cout << "-+";
			cout << "-+" << endl;
		}
	}

	cout << endl;
}

/* Funkcja ustawia znak na wybranym polu */

void Board::SetSign(int i, int j, int sign) {

	board[i][j] = sign;

	if (sign == 0) {

		movecount--;
		last[0] = last[1] = size;
	}

	else {

		movecount++;
		last[0] = i;
		last[1] = j;
	}
}

/* Funkcja sprawdzajaca czy gra zostala rozstrzygnieta , sprawdza stan gry */

int Board::CheckWinner() {

	if (last[0] == size) return 2;

	int w, k, a, b, sign, counter;
	sign = counter = 1;

	w = last[0];
	k = last[1];

	sign = board[w][k];

	for (int i = -1; i < 1; i++)
	{

		for (int j = -1; j <= 1; j++) {

			if (i >= 0 && j >= 0) {

				if (movecount >= size * size) return 0;

				else return 2;

			}

			counter = 1;
			a = i;
			b = j;

			while (w + a >= 0 && w + a < size && k + b >= 0 && k + b < size && board[w + a][k + b] == sign)
			{
				counter++;
				a += i;
				b += j;
			}

			a = i;
			b = j;

			while (w - a >= 0 && w - a < size && k - b >= 0 && k - b < size && board[w - a][k - b] == sign)
			{
				counter++;
				a += i;
				b += j;
			}

			if (counter >= winrow) return board[w][k];

		}
	}

	return 2;
}
