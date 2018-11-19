/*
 *	Algorithm I. - 11/19/2018
 *	Author: David Miko
 *	Professor: Dohnalek
 *
 *	Curriculum: Recursive functions
 *	Description: TBA
 */

#include <iostream>

using namespace std;

#pragma region Functions

/*
 * Line separator for better lucidity
 */
void space();

/*
 * Initialization of the board
 */
void initBoard(int **&board, int ROWS, int COLS);

/*
 * Loading board with default values ( 0 )
 */
void loadBoard(int **board, int ROWS, int COLS);

/* 
 * Writing out the board to the console
 */
void printBoard(int **board, int ROWS, int COLS);

/* 
 * Set the knight to the default position [0, 0]
 */
void setKnight(int **board, int ROWS, int COLS, int move);

bool moveValid(int **board, int ROWS, int COLS, int x, int y);

bool run(int **board, int ROWS, int COLS, int posX, int posY, int movesX[], int movesY[], int move);

#pragma endregion Headers of functions

int main(void)
{
	cout << "\t\tAlgorithm I. - 11/19/18" << endl;
	space();

	const int ROWS = 8;
	const int COLS = 8;

	int movesX[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
	int movesY[] = { -2, -1, 1, 2, 2, 1, -1, -2 };

	int startPosX = 0;
	int startPosY = 0;

	int **board;

	initBoard(board, ROWS, COLS);
	loadBoard(board, ROWS, COLS);
	printBoard(board, ROWS, COLS);
	
	cout << endl;
	space();
	cout << endl;

	setKnight(board, startPosX, startPosY, 1);

	printBoard(board, ROWS, COLS);

	cout << endl;
	space();
	cout << endl;
	
	run(board, ROWS, COLS, startPosX, startPosY, movesX, movesY, 2);

	printBoard(board, ROWS, COLS);

	system("pause");
	return 0;
}



#pragma region Functions

void space()
{
	cout << "============================================================" << endl;
}

/*
* Need to use & because board is not initialized if is not...
*/
void initBoard(int **&board, int ROWS, int COLS)
{
	board = new int*[ROWS];

	for (int i = 0; i < ROWS; i++)
	{
		board[i] = new int[COLS];
	}
}

void loadBoard(int **board, int ROWS, int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			board[i][j] = 0;
		}
	}
}

void printBoard(int **board, int ROWS, int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << board[i][j] << "; ";
		}

		cout << endl;
	}
}

void setKnight(int **board, int x, int y, int move)
{
	board[x][y] = move;

	return;
}

bool moveValid(int **board, int ROWS, int COLS, int x, int y)
{
	if (x < 0 || x >= COLS || y < 0 || y >= ROWS || board[x][y] != 0)
	{
		return false;
	}

	return true;
}

bool run(int **board, int ROWS, int COLS, int posX, int posY, int movesX[], int movesY[], int move)
{
	if (move >= ROWS * COLS)
	{
		return true;
	}
	for (int i = 0; i < 8; i++)
	{
		int newPosX = posX + movesX[i];
		int newPosY = posY + movesY[i];

		if (moveValid(board, ROWS, COLS, newPosX, newPosY))
		{
			setKnight(board, newPosX, newPosY, move);

			if (run(board, ROWS, COLS, newPosX, newPosY, movesX, movesY, move + 1))
			{
				return true;
			}

			setKnight(board, newPosX, newPosY, 0);
		}

		
	}

	return false;
}

#pragma endregion Bodies of functions

//End
