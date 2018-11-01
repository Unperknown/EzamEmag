#include "maze.h"

int checkExitStatus();
int setStatus(enum status);
enum status getStatus();
int setInitalValue();
int printOption();
int chooseOption();
int playSingleMaze();
int playMultiMaze();
int playMazeWithComputer();
int demostrateMaze();
int customMaze();
//middle level method

extern int clearBoard();
extern int setPlayer();
//import low level method

int checkExitStatus()
{
	if (getStatus() == EXIT)
	{
		wprintf(L"프로그램을 종료한대요!\n"); //need to be improved
		getwchar();
		getwchar();
		exit(EXIT_FAILURE);
		return 0;
	}
	return 1;
}
int setStatus(enum status value)
{
	Status = value;
	return 1;
}
enum status getStatus()
{
	return Status;
}
int setInitalValue()
{
	setStatus(INITAL);
	clearBoard();
	setPlayer();

	return 1;
}
int printOption()
{
	wprintf(L"어떻게 생긴 초기 출력 화면들\n");
	return 1;
}
int chooseOption()
{
	enum status option; //will be replaced with choosing by cursor location soon

	wprintf(L"할 게임의 종류를 선택하라는 출력 화면들\n");
	wscanf(L"%d", &option); //will be replaced with choosing by cursor location soon

	switch (option)
	{
	case SINGLE_MAZE: setStatus(SINGLE_MAZE); break;
	case MULTIPLE_MAZE: setStatus(MULTIPLE_MAZE); break;
	case MAZE_WITH_COMPUTER: setStatus(MAZE_WITH_COMPUTER); break;
	case DEMOSTRATE_MAZE: setStatus(DEMOSTRATE_MAZE); break;
	case CUSTOM_MAZE: setStatus(CUSTOM_MAZE); break;
	case EXIT: setStatus(EXIT); break;
	default: wprintf(L"어떻게 이상한 걸 선택할 수 있죠?\n"); break;
	} //need to be divided into method soon
	return 1;
}
int playSingleMaze()
{
	wprintf(L"1인용 미로게임이라네여\n");
	return 1;
}
int playMultiMaze()
{
	wprintf(L"2인용 미로게임이래요\n");
	return 1;
}
int playMazeWithComputer()
{
	wprintf(L"컴퓨터와 함께하는 미로게임이래요\n");
	return 1;
}
int demostrateMaze()
{
	wprintf(L"컴퓨터의 미로게임을 관전한대요\n");
	return 1;
}
int customMaze()
{
	wprintf(L"플레이어가 직접 맵을 만들어서 미로게임을 한대요\n");
	return 1;
}