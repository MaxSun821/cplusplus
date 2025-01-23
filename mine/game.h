#ifndef _MINE_SWEEPER_GAME_H_
#define _MINE_SWEEPER_GAME_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define MAX_MINE 79

void init_board(char board[ROWS][COLS], int rows, int cols, char set);
void display_board(char board[ROWS][COLS], int row, int col);
void set_mine(char board[ROWS][COLS], int row, int col);
bool player(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

#endif // _MINE_SWEEPER_GAME_H_
