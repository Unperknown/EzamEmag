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
	wprintf(L"미로 게임을 하는데 필요한 데이터를 할당함\n");
	static int currentStage = 1;
	maze.stage = currentStage++;

	mazeGenerate(quantityOfMaze);
	setPlayerInformation(amountOfPlayer);

	return 0;
}
int executeGame()
{
	wprintf(L"게임을 실행하는 함수\n");
	return 0;
}
int clearBoard(Board target)
{
	wprintf(L"미로 맵을 초기화하는 함수\n");

	for (int i = 0; i < sizeof *target; i++)
		*((char *)*target + i) = ' ';

	return 1;
}
