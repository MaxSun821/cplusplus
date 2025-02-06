#ifndef _GAME_H
#define _GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROWS 3
#define COLS 3

void init_board(char board[ROWS][COLS], int rows, int cols);
void display_board(char board[ROWS][COLS], int rows, int cols);
void player(char board[ROWS][COLS], int rows, int cols);
void computer(char board[ROWS][COLS], int rows, int cols);
char is_win(char board[ROWS][COLS], int rows, int cols);

#endif // !_GAME_H