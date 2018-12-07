#include "maze.h"

int setInitalOption();
int playGame();
bool isEnd();
//layer 6 methods

extern int setInitalValue();
extern int printOption();
extern int chooseOption();
extern int playSingleMaze();
extern int playMultiMaze();
extern int playMazeWithComputer();
extern int demostrateMaze();
extern int customMaze();
extern int exited();
//import layer 5 methods

extern int setStatus(const enum status);
extern enum status getStatus();
//import Layer 0 methods

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
	//will be refactored soon
	switch (getStatus())
	{
	case SINGLE_MAZE: playSingleMaze(); break;
	case MULTIPLE_MAZE: playMultiMaze(); break;
	case MAZE_WITH_COMPUTER: playMazeWithComputer(); break;
	case DEMOSTRATE_MAZE: demostrateMaze(); break;
	case EXIT: exited(); break;
	}
	setStatus(STOPPED);

	return 1;
}
bool isEnd()
{
	return getStatus() == STOPPED;
}