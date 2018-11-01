#include "maze.h"

int setInitalOption();
int playGame();
bool isEnd();
//high level method

extern int checkExitStatus();
extern int setStatus(enum status);
extern enum status getStatus();
extern int setInitalValue();
extern int printOption();
extern int chooseOption();
extern int playSingleMaze();
extern int playMultiMaze();
extern int playMazeWithComputer();
extern int demostrateMaze();
extern int customMaze();
//import middle level method

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

int setInitalOption()
{
	setInitalValue();
	printOption();
	chooseOption();

	return 1;
}
int playGame()
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
bool isEnd()
{
	return getStatus() == STOPPED;
}