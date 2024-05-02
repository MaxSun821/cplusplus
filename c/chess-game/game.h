/*
 * 头文件
 */

#ifndef C_GAME_H
#define C_GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3


// 函数声明
void menu();
void chess_game(char board[ROWS][COLS]);
void init(char board[ROWS][COLS]);
void print(char board[ROWS][COLS]);
void player(char board[ROWS][COLS]);
void computer(char board[ROWS][COLS]);
char is_win(char board[ROWS][COLS]);

#endif //C_GAME_H
