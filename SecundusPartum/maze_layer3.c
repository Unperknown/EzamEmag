#include "maze.h"

int mazeGenerate(int quantityOfMaze);
int setPlayerInformation(int amountOfPlayer);
Axis getAxisOfBoard(int standard);
int movePlayer();
// layer 3 methods

extern Player setPlayer();
extern Board createOneMaze(Axis topLeft);
extern Board mazeGenerator();
extern Axis getStartingPoint(); //exception when maze board has not been initalized
extern Axis getEndPoint();
extern bool isStageEnd(LinkedPlayer players);
// import layer 2 methods

int mazeGenerate(int quantityOfMaze)
{
	wprintf(L"�̷� �����ϱ�\n");
	for (int mazeNumber = 1; mazeNumber <= quantityOfMaze; mazeNumber++)
	{
		maze.mazeMap.next = maze.mazeMap.currentBoard;
		maze.mazeMap.currentBoard = createOneMaze(getAxisOfBoard(mazeNumber));
	}

	return 1;
}
int setPlayerInformation(int amountOfPlayer)
{
	wprintf(L"�÷��̾� ���� �����ϱ�\n");
	for (int i = 1; i <= amountOfPlayer; i++)
	{
		maze.players.next = maze.players.currentPlayer;
		maze.players.currentPlayer = setPlayer();
		//set Players' current score, name, *starting point*, whether won or not
	}
	return 1;
}
Axis getAxisOfBoard(int standard)
{
	return (Axis)NULL;
}
int movePlayer()
{
	wprintf(L"�� �÷��̾� �̻��� �̷� ���� ã�ư��� �ϴ� �Լ�\n");
	return 0;
}