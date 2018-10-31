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

static int showOption();
static int playGame();
static bool isEnd();
//high level module

static int setInitalStatus();
static int setStatus(enum status);
static enum status getStatus();
static int printOption();
static int chooseOption();
static int playSingleMaze();
static int playMultiMaze();
static int playMazeWithComputer();
static int demostrateMaze();
static int customMaze();
//middle level module

int mazeGame()
{
	while (true)
	{
		do {
			showOption();
			playGame();
		} while (isEnd());
	}
	return 1;
}

static int showOption()
{
	printOption();
	chooseOption();
	setInitalStatus();
}
static int playGame()
{
	switch (getStatus())
	{
	case SINGLE_MAZE: playSingleMaze(); break;
	case MULTIPLE_MAZE: playMultiMaze(); break;
	case MAZE_WITH_COMPUTER: playMazeWithComputer(); break;
	case DEMOSTRATE_MAZE: demostrateMaze(); break;
	case CUSTOM_MAZE: customMaze(); break;
	}
	setStatus(STOPPED);
}
static bool isEnd()
{
	return getStatus() == STOPPED;
}

static int setInitalStatus()
{
	if (getStatus() == EXIT)
		exit(EXIT_FAILURE);
	else
		setStatus(START);
}
static int setStatus(enum status value)
{
	Status = value;
}
static int getStatus()
{
	return Status;
}
static int printOption()
{
	wprintf(L"메뉴 출력");
	return 1;
}
static int chooseOption()
{
	enum status option;
	int temp_input; //will be replaced with choosing by cursor location soon

	wprintf(L"메뉴 선택\n");
	scanf("%d", &temp_input); //will be replaced with choosing by cursor location soon
	
	option = temp_input;

	switch (option)
	{
	case SINGLE_MAZE: setStatus(SINGLE_MAZE); break;
	case MULTIPLE_MAZE: setStatus(MULTIPLE_MAZE); break;
	case MAZE_WITH_COMPUTER: setStatus(MAZE_WITH_COMPUTER); break;
	case DEMOSTRATE_MAZE: setStatus(DEMOSTRATE_MAZE); break;
	case CUSTOM_MAZE: setStatus(CUSTOM_MAZE); break;
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