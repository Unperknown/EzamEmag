#include "maze.h"

int mazeGenerate(int);
int setPlayerInformation(int);
int showMazeStage();
void printMaze();
// layer 3 methods

extern Player setOnePlayer();
extern int createOneMaze(OneMap);
extern int isStageEnd();
extern void printOneMap(int, int, OneMap);
extern void changeCondition(OneMap, Player*, int, int);
// import layer 2 methods

extern int getch_();
extern void cersorMoveTo(int x, int y);
// import Layer 0 methods

int mazeGenerate(int quantityOfMaze)
{
	createOneMaze(maze.maps.first);
	
	if (quantityOfMaze == 2)
		createOneMaze(maze.maps.second);
	
	return 1;
}
int setPlayerInformation(int amountOfPlayer)
{
	maze.players.first = setOnePlayer();
	
	if (amountOfPlayer == 2)
		maze.players.second = setOnePlayer();

	return 1;
}
int showMazeStage()
{
	printMaze();
	//will be REFACTORED soon: too much complicated
	while (!isStageEnd()) {
		switch (getch_()) {
		case A:
			changeCondition(maze.maps.first, &maze.players.first, -MOVEGAP, 0);
			printOneMap(P1PX, PY, maze.maps.first);
			break;
		case W:
			changeCondition(maze.maps.first, &maze.players.first, 0, -MOVEGAP);
			printOneMap(P1PX, PY, maze.maps.first);
			break;
		case S:
			changeCondition(maze.maps.first, &maze.players.first, 0, MOVEGAP);
			printOneMap(P1PX, PY, maze.maps.first);
			break;
		case D:
			changeCondition(maze.maps.first, &maze.players.first, MOVEGAP, 0);
			printOneMap(P1PX, PY, maze.maps.first);
			break;
		case LEFT:
			changeCondition(maze.maps.second, &maze.players.second, -MOVEGAP, 0);
			printOneMap(P2PX, PY, maze.maps.second);
			break;
		case UP:
			changeCondition(maze.maps.second, &maze.players.second, 0, -MOVEGAP);
			printOneMap(P2PX, PY, maze.maps.second);
			break;
		case DOWN:
			changeCondition(maze.maps.second, &maze.players.second, 0, MOVEGAP);
			printOneMap(P2PX, PY, maze.maps.second);
			break;
		case RIGHT:
			changeCondition(maze.maps.second, &maze.players.second, MOVEGAP, 0);
			printOneMap(P2PX, PY, maze.maps.second);
			break;
		}
	}
	return 0;
}
void printMaze()
{
	//will be refactored soon
	system("cls");
	cersorMoveTo(0, 0);
	wprintf(L"\n\n");
	wprintf(L"							미	로	찾	기\n\n");
	printOneMap(P1PX, PY, maze.maps.first);
	printOneMap(P2PX, PY, maze.maps.second);
}