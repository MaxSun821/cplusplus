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
			printf("Exit Game!\n");
			break;
		default:
			printf("Error Choice!\n");
			break;
		}
	} while (input);
	return 0;
}

void menu()
{
	printf("--------------------\n");
	printf("-------1. Play------\n");
	printf("-------0. Exit------\n");
	printf("--------------------\n");
}

void game()
{
	//printf("Game is running...\n");

	// board
	char mine[ROWS][COLS] = { 0 }; // 11 * 11
	char show[ROWS][COLS] = { 0 }; // 11 * 11

	// init board
	// mine board set all '0'
	// show board set all '*'
	init_board(mine, ROWS, COLS, '0');
	// display_board(mine, ROW, COL);
	init_board(show, ROWS, COLS, '*');
	display_board(show, ROW, COL);

	// set ten mines on the mine board
	set_mine(mine, ROW, COL);
	display_board(mine, ROW, COL);

	bool ret = player(mine, show, ROW, COL);
	if (ret)
	{
		printf("Congratulations! You win!\n");
	}
	
}