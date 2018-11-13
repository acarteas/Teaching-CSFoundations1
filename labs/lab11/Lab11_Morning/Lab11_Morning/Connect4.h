#pragma once
const int NUM_ROWS = 6;
const int NUM_COLS = 7;

void drawBoard(char board[NUM_ROWS][NUM_COLS]);
void resetBoard(char board[NUM_ROWS][NUM_COLS]);
char isGameOver(char board[NUM_ROWS][NUM_COLS]);
char getNextPlayer(char current_player);
void playGame();
void placePiece(char board[NUM_ROWS][NUM_COLS], char piece, int col);
int getPlayerSelection();