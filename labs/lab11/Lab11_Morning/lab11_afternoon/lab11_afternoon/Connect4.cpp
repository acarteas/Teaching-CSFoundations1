#include "Connect4.h"
#include <iostream>
using namespace std;

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
		int col = getPlayerSelection();
		placePiece(board, player, col);
		player = getNextPlayer(player);
	}
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
void drawBoard(char board[NUM_ROWS][NUM_COLS])
{
	//comment out if not on windows
	system("cls");

	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLS; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	//draw a cool bottom border
	for (int i = 0; i < NUM_COLS; i++)
	{
		cout << (char)196 << (char)196;
	}
	cout << endl;
	
	//draw column labels
	for (int i = 0; i < NUM_COLS; i++)
	{
		cout << i + 1 << " ";
	}
	cout << endl;
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
void placePiece(char board[NUM_ROWS][NUM_COLS], char piece, int col)
{
	int current_row = 0;
	while (current_row < NUM_ROWS - 1 && board[current_row][col] == '_')
	{
		current_row++;
	}
	if (board[current_row][col] != '_')
	{
		current_row--;
	}
	board[current_row][col] = piece;
}
int getPlayerSelection()
{
	cout << "Enter column (1-7): ";
	int user_input;
	cin >> user_input;
	return user_input - 1;
}