#define _CRT_SECURE_NO_DEPRICATE
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRICAT

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

struct RockPaperScissor
{
	char R[10] = "Rock";
	char P[10] = "Paper";
	char S[10] = "Scissor";
};

char Choice0[10], Choice1[10];
int Count0, Count1;

void SystemGuess()
{
	RockPaperScissor RPS;

	srand(time(NULL));
	int Number = rand() % 3;

	if (Number == 0)
	{
		strcpy(Choice0, RPS.R);
		printf("System choice: %s\n", Choice0);
	}
	else if (Number == 1)
	{
		strcpy(Choice0, RPS.P);
		printf("System choice: %s\n", Choice0);
	}
	else  if (Number == 2)
	{
		strcpy(Choice0, RPS.S);
		printf("System choice: %s\n", Choice0);
	}
}

void WinCondition()
{
	RockPaperScissor RPS;

	if (strcmp(Choice0, Choice1) == 0)
	{
		printf("Play again\n");
	}
	else if ((strcmp(Choice0, RPS.R) == 0 && (strcmp(Choice1, RPS.P) == 0)) ||
		(strcmp(Choice0, RPS.P) == 0 && (strcmp(Choice1, RPS.S) == 0)) ||
		(strcmp(Choice0, RPS.S) == 0 && (strcmp(Choice1, RPS.R) == 0)))
	{
		Count1++;
		if (Count1 == 3)
		{
			printf("You won\n");
			exit(0);
		}
	}
	else if ((strcmp(Choice1, RPS.R) == 0 && (strcmp(Choice0, RPS.P) == 0)) ||
		(strcmp(Choice1, RPS.P) == 0 && (strcmp(Choice0, RPS.S) == 0)) ||
		(strcmp(Choice1, RPS.S) == 0 && (strcmp(Choice0, RPS.R) == 0)))
	{
		Count0++;
		if (Count0 == 3)
		{
			printf("You lost\n");
			exit(0);
		}
	}
}
int main()
{
	int Option;
	RockPaperScissor RPS;

	while (1)
	{
		printf("Your score: %d\n", Count1);
		printf("system score: %d\n\n", Count0);
		printf("1. Rock\n");
		printf("2. Paper\n");
		printf("3. Scissor\n");
		printf("Enter your choice: ");
		scanf("%d", &Option);
		printf("\n");

		system("cls");

		switch (Option)
		{
		case 1:
			strcpy(Choice1, RPS.R);
			printf("Your choice: %s\n", Choice1);
			break;
		case 2:
			strcpy(Choice1, RPS.P);
			printf("Your choice: %s\n", Choice1);
			break;
		case 3:
			strcpy(Choice1, RPS.S);
			printf("Your choice: %s\n", Choice1);
			break;
		default:
			printf("Enter valid choice\n");
		}
		SystemGuess();
		WinCondition();
	}
	return 0;
}