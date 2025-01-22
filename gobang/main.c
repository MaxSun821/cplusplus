#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu();
void game();

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("Enter your choice: ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("Exit Game\n");
			break;
		default:
			printf("Error Choice\n");
			break;
		}
	} while (input);
	return 0;
}

void menu()
{
	printf("--------------------\n");
	printf("--- 1.Start Game ---\n");
	printf("--- 0.Exit Game  ---\n");
	printf("--------------------\n");
}

void game()
{
	// board
	char board[ROWS][COLS] = { 0 };
	// init board
	init_board(board, ROWS, COLS);
	// print board
	display_board(board, ROWS, COLS);

	char ret = 0;
	while (1)
	{
		// player play
		player(board, ROWS, COLS);
		display_board(board, ROWS, COLS);
		ret = is_win(board, ROWS, COLS);
		if (ret != 'c')
		{
			break;
		}
		// computer play
		computer(board, ROWS, COLS);
		display_board(board, ROWS, COLS);

		ret = is_win(board, ROWS, COLS);
		if (ret != 'c')
		{
			break;
		}
	}

	if (ret == '*')
	{
		printf("Player Win\n");
	}
	else if (ret == '#')
	{
		printf("Computer Win\n");
	}
	else
	{
		printf("Draw\n");
	}
}