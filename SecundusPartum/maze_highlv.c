#include "maze.h"

static int setInitalOption();
static int playGame();
static bool isEnd();
//high level module

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