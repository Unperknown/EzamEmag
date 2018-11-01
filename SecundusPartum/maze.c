#include "maze.h"
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <Windows.h>

// loads of definition of methods

extern int mazeGame();
extern enum status Status;
extern char board[30][30];
//use those objects in static methods

static int setInitalOption();
static int playGame();
static bool isEnd();
//high level module

static int checkExitStatus();
static int setStatus(enum status);
static enum status getStatus();
static int setInitalValue();
static int printOption();
static int chooseOption();
static int playSingleMaze();
static int playMultiMaze();
static int playMazeWithComputer();
static int demostrateMaze();
static int customMaze();
//middle level module

static int clearBoard();
static int setPlayer();
//low level module

int mazeGame()
{
	while (true)
	{
		do {
			setInitalOption();
			playGame();
		} while (isEnd());
	}
	return 1;
}

static int setInitalOption()
{
	setInitalValue();
	printOption();
	chooseOption();

	return 1;
}
static int playGame()
{
	checkExitStatus();

	switch (getStatus())
	{
	case SINGLE_MAZE: playSingleMaze(); break;
	case MULTIPLE_MAZE: playMultiMaze(); break;
	case MAZE_WITH_COMPUTER: playMazeWithComputer(); break;
	case DEMOSTRATE_MAZE: demostrateMaze(); break;
	case CUSTOM_MAZE: customMaze(); break;
	}
	setStatus(STOPPED);

	return 1;
}
static bool isEnd()
{
	return getStatus() == STOPPED;
}

static int checkExitStatus()
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
static int setStatus(enum status value)
{
	Status = value;
	return 1;
}
static enum status getStatus()
{
	return Status;
}
static int setInitalValue()
{
	setStatus(INITAL);
	clearBoard();
	setPlayer();
}
static int printOption()
{
	wprintf(L"어떻게 생긴 초기 출력 화면들\n");
	return 1;
}
static int chooseOption()
{
	enum status option; //will be replaced with choosing by cursor location soon

	wprintf(L"할 게임의 종류를 선택하라는 출력 화면들\n");
	scanf("%d", &option); //will be replaced with choosing by cursor location soon

	switch (option)
	{
	case SINGLE_MAZE: setStatus(SINGLE_MAZE); break;
	case MULTIPLE_MAZE: setStatus(MULTIPLE_MAZE); break;
	case MAZE_WITH_COMPUTER: setStatus(MAZE_WITH_COMPUTER); break;
	case DEMOSTRATE_MAZE: setStatus(DEMOSTRATE_MAZE); break;
	case CUSTOM_MAZE: setStatus(CUSTOM_MAZE); break;
	case EXIT: setStatus(EXIT); break;
	default: wprintf(L"어떻게 이상한 걸 선택할 수 있죠?\n"); break;
	}
	return 1;
}
static int playSingleMaze()
{
	wprintf(L"1인용 미로게임이라네여\n");
	return 1;
}
static int playMultiMaze()
{
	wprintf(L"2인용 미로게임이래요\n");
	return 1;
}
static int playMazeWithComputer()
{
	wprintf(L"컴퓨터와 함께하는 미로게임이래요\n");
	return 1;
}
static int demostrateMaze()
{
	wprintf(L"컴퓨터의 미로게임을 관전한대요\n");
	return 1;
}
static int customMaze()
{
	wprintf(L"플레이어가 직접 맵을 만들어서 미로게임을 한대요\n");
	return 1;
}

static int clearBoard()
{
	wprintf(L"미로 맵을 초기화하는 함수\n");
	for (int i = 0; i < sizeof board / sizeof board[0]; i++) for (int j = 0; j < sizeof board / sizeof(char); j++) board[i][j] = ' ';
	return 1;
}
static int setPlayer()
{
	wprintf(L"플레이어를 설정하는 함수\n");
	return 1;
}