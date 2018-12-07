#include "maze.h"

int setGameData(bool, bool);
int executeGame();
// Layer 4 methods

extern int mazeGenerate(OneMap);
extern int setMark(Player *);
extern void printTitle();
extern void printMap();
extern void playMazeByKey();
extern void showWinner();
// import Layer 3 methods

extern enum status getStatus();
// import Layer 0 methods

int setGameData(bool isOtherPlayerExists, bool isComputerPlay)
{
	if (!isComputerPlay)
		setMark(&maze.players.player1);
	if (isOtherPlayerExists)
		setMark(&maze.players.player2);

	return 0;
}
int executeGame()
{
	printTitle();
	printMap();
	playMazeByKey();
	showWinner();
	
	return 0;
}