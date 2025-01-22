#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void init_board(char board[ROWS][COLS], int rows, int cols)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void display_board(char board[ROWS][COLS], int rows, int cols)
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < cols - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < rows - 1)
		{
			for (j = 0; j < cols; j++)
			{
				printf("---");
				if (j < cols - 1)
				{
					printf("|");
				}
			}
		}
		
		printf("\n");

	}
}

void player(char board[ROWS][COLS], int rows, int cols)
{
	int x = 0;
	int y = 0;

	while (1)
	{
		printf("Player choice: ");
		scanf("%d %d", &x, &y);
		if (x < 1 || x > rows || y < 1 || y > cols)
		{
			printf("Invalid choice\n");
		}
		else
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("The cell is not empty\n");
			}
		}
	}
}

void computer(char board[ROWS][COLS], int rows, int cols)
{
	while (1)
	{
		int x = rand() % rows;
		int y = rand() % cols;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
	
}

bool is_full(char board[ROWS][COLS], int rows, int cols)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			if (board[i][j] == ' ')
			{
				return false;
			}
		}
	}
	return true;
}

char is_win(char board[ROWS][COLS], int rows, int cols)
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	for (i = 0; i < cols; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	if (is_full(board, rows, cols))
	{
		return 'q';
	}

	return 'c';
}
