#include "maze.h"

int mazeGenerate(int);
int setPlayerInformation(int);
void printMaze();
int updateMaze(int);
void showWinner();
int retByComputer();
void* playerUpdate(void *);
void* computerUpdate(void *);
// layer 3 methods

extern Player setOnePlayer();
extern int createOneMaze(OneMap);
extern int isStageEnd();
extern int isComputerEnd();
extern void printOneMap(int, int, OneMap);
extern void changeCondition(OneMap, Player*, int, int);
extern void updateMap(Axis, int, int, OneMap);
extern int getBestWayOfMaze(int, int);
// import layer 2 methods

extern wchar_t* getStr(int);
// import layer 1 method

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
int updateMaze(int key)
{
	//will be REFACTORED soon: too much complicated
	switch (key) {
	case A:
		changeCondition(maze.maps.first, &maze.players.first, -MOVEGAP, 0);
		updateMap(maze.players.first.currentLocation, P1PX, PY, maze.maps.first);
		break;
	case W:
		changeCondition(maze.maps.first, &maze.players.first, 0, -MOVEGAP);
		updateMap(maze.players.first.currentLocation, P1PX, PY, maze.maps.first);
		break;
	case S:
		changeCondition(maze.maps.first, &maze.players.first, 0, MOVEGAP);
		updateMap(maze.players.first.currentLocation, P1PX, PY, maze.maps.first);
		break;
	case D:
		changeCondition(maze.maps.first, &maze.players.first, MOVEGAP, 0);
		updateMap(maze.players.first.currentLocation, P1PX, PY, maze.maps.first);
		break;
	case LEFT:
		changeCondition(maze.maps.second, &maze.players.second, -MOVEGAP, 0);
		updateMap(maze.players.second.currentLocation, P2PX, PY, maze.maps.second);
		break;
	case UP:
		changeCondition(maze.maps.second, &maze.players.second, 0, -MOVEGAP);
		updateMap(maze.players.second.currentLocation, P2PX, PY, maze.maps.second);
		break;
	case DOWN:
		changeCondition(maze.maps.second, &maze.players.second, 0, MOVEGAP);
		updateMap(maze.players.second.currentLocation, P2PX, PY, maze.maps.second);
		break;
	case RIGHT:
		changeCondition(maze.maps.second, &maze.players.second, MOVEGAP, 0);
		updateMap(maze.players.second.currentLocation, P2PX, PY, maze.maps.second);
		break;
	}
	return 0;
}
void printMaze()
{
	//will be refactored soon
	system("cls");
	cersorMoveTo(0, 0);
	wprintf(L"\n\n\n");
	wprintf(L"%ls미	로	찾	기", BLANK);
	printOneMap(P1PX, PY, maze.maps.first);
	printOneMap(P2PX, PY, maze.maps.second);
}
void showWinner()
{
	system("cls");
	switch (isStageEnd()) {
	case PLAYER1_WON:
		wprintf(L"\n\n\n\n");
		wprintf(L"%ls플레이어 1이(가) 승리하였습니다!\n", BLANK);
		getStr(MAXSTR);
		return;
		break;
	case PLAYER2_WON:
		wprintf(L"\n\n\n\n");
		wprintf(L"%ls플레이어 2이(가) 승리하였습니다!\n", BLANK); 
		getStr(MAXSTR);
		return;
		break;
	}
	if (isComputerEnd() == COMPUTER_WON) {
		wprintf(L"\n\n\n\n");
		wprintf(L"%ls컴퓨터가 승리하였습니다!", BLANK);
		getStr(MAXSTR);
		return;
	}
}
int retByComputer()
{
	return getBestWayOfMaze(maze.computer.currentPoint.x, maze.computer.currentPoint.y);
}
void* playerUpdate(void * arg)
{
	while (!isStageEnd() && !isComputerEnd()) 
		updateMaze(getch_());

	return NULL;
}
void* computerUpdate(void * arg)
{
	while (!isComputerEnd() && !isStageEnd()) {
		updateMaze(retByComputer());
		Sleep(500);
	}

	return NULL;
}