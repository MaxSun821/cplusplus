
#ifndef C_MINE_CLEARANCE_H
#define C_MINE_CLEARANCE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 11
#define COLS 11

#define ROW 9
#define COL 9

#define BOMB 10

void menu();
void game();
void init(char hide[ROWS][COLS], char show[ROWS][COLS]);
void bomb(char hide[ROWS][COLS]);
void print(char board[ROWS][COLS]);
void play(char hide[ROWS][COLS], char show[ROWS][COLS]);
char check(char hide[ROWS][COLS], int x, int y);

#endif //C_MINE_CLEARANCE_H
