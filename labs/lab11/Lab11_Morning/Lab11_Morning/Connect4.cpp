#include "Connect4.h"
#include <iostream>
using namespace std;

void drawBoard(char board[NUM_ROWS][NUM_COLS])
{
	system("cls");
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLS; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < NUM_COLS; i++)
	{
		cout << i + 1 << " ";
	}
	cout << endl;
}
void resetBoard(char board[NUM_ROWS][NUM_COLS])
{
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLS; j++)
		{
			board[i][j] = '_';
		}
	}
}
char isGameOver(char board[NUM_ROWS][NUM_COLS])
{
	return '\0';
}

char getNextPlayer(char current_player)
{
	if (current_player == 'X')
	{
		return 'O';
	}
	else
	{
		return 'X';
	}
}
void playGame()
{
	//initialize board
	char board[NUM_ROWS][NUM_COLS];
	resetBoard(board);

	//initialize player
	char player = 'O';

	//play game
	while (isGameOver(board) == '\0')
	{
		drawBoard(board);
		int row = getPlayerSelection();
		placePiece(board, player, row);
		player = getNextPlayer(player);
	}
}
void placePiece(char board[NUM_ROWS][NUM_COLS], char piece, int col)
{
	//start at top row and work down
	int location = 0;
	col = col - 1;
	while (board[location][col] == '_' && location < NUM_ROWS)
	{
		location++;
	}
	location--;
	board[location][col] = piece;
}
int getPlayerSelection()
{
	cout << "Where would you like to place your piece (1-7): ";
	int selection = 0;
	cin >> selection;
	return selection;
}