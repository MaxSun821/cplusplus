#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void init_board(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void display_board(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		int j = 0;
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void set_mine(char board[ROWS][COLS], int row, int col)
{
	int count = MAX_MINE;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char board[ROWS][COLS], int x, int y)
{
	int ret = (board[x - 1][y - 1] +
		board[x - 1][y] +
		board[x - 1][y + 1] +
		board[x][y - 1] +
		board[x][y + 1] +
		board[x + 1][y - 1] +
		board[x + 1][y] +
		board[x + 1][y + 1] - 8 * '0');
	return ret;
}

bool player(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int count = row * col - MAX_MINE;
	int x = 0;
	int y = 0;
	while (count)
	{
		printf("Enter the location to sweep: ");
		scanf("%d %d", &x, &y);
		if (x < 1 || x > row || y < 1 || y > col)
		{
			printf("Location is invalid!\n");
		}
		else
		{
			if (mine[x][y] == '1')
			{
				printf("Game Over!\n");
				return false;
			}
			else
			{
				int ret = get_mine_count(mine, x, y);
				show[x][y] = ret + '0';
				count--;
			}
		}
		display_board(show, row, col);
	}
	return true;
}