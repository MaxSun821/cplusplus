#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void menu();
void game();

int main()
{
	// Initialize random number generator
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("Enter your choice:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("Exit game!\n");
			break;
		default:
			printf("Enter error, please enter again!\n");
			break;
		}
	} while (input);
	return 0;
}

void menu()
{
	printf("------------------------\n");
	printf("---1. play----0. exit---\n");
	printf("------------------------\n");
}

void game()
{
	// Generate random number between 1 and 100
	int right_number = rand() % 100 + 1;
	int guess = 0;
	while (true)
	{
		printf("Please enter your guess:> ");
		scanf("%d", &guess);
		if (guess > right_number)
		{
			printf("Your guess is greater than the right number!\n");
		}
		else if (guess < right_number)
		{
			printf("Your guess is less than the right number!\n");
		}
		else
		{
			printf("Congratulations, you got the right number!\n");
			break;
		}
	}
}