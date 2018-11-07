#include "maze.h"

int setGameData(int quantityOfMaze, int amountOfPlayer);
int executeGame();
int clearBoard(Board target);
// Layer 4 methods

extern int mazeGenerate(int quantityOfMaze);
extern int setPlayerInformation(int amountOfPlayer);
extern Player setPlayer();
extern int movePlayer();
extern Board createOneMaze(Axis topLeft);
extern Axis getAxisOfBoard(int standard);
// import Layer 3 methods

int setGameData(int quantityOfMaze, int amountOfPlayer)
{
	wprintf(L"�̷� ������ �ϴµ� �ʿ��� �����͸� �Ҵ���\n");
	static int currentStage = 1;
	maze.stage = currentStage++;

	mazeGenerate(quantityOfMaze);
	setPlayerInformation(amountOfPlayer);

	return 0;
}
int executeGame()
{
	wprintf(L"������ �����ϴ� �Լ�\n");
	return 0;
}
int clearBoard(Board target)
{
	wprintf(L"�̷� ���� �ʱ�ȭ�ϴ� �Լ�\n");

	for (int i = 0; i < sizeof *target; i++)
		*((char *)*target + i) = ' ';

	return 1;
}
