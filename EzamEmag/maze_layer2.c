#include "maze.h"

int isStageEnd();
void printOneMap(const int, const int, const OneMap);
void changeCondition(Player*, const int, const int);
int updateMaze(const int, Player*, const int);
void updateElement(const Player, const int);
int retByComputer();
int getBestWayOfMaze(int, int);
void* nullFunction(void *);
void* player1Map(void *);
void* player2Map(void *);
void* computerMap(void *);
void* player1Update(void *);
void* player2Update(void *);
void* computerUpdate(void *);
// layer 2 methods

extern pthread_mutex_t update;
// import layer 3 attributes

extern bool isInvaildMove(const OneMap, const Axis, const int, const int);
extern bool solveMaze(int, int);
extern int selectByCersor();
// import layer 1 methods

extern int getChr();
extern void cersorMoveTo(int, int);
extern bool isSameLoc(const Axis, const Axis);
// import Layer 0 methods

int isStageEnd()
{
	Axis EndPoint = { STOPX, STOPY };

	if (isSameLoc(maze.players.player1.currentLocation, EndPoint)) return PLAYER1_WON;
	if (isSameLoc(maze.players.player2.currentLocation, EndPoint)) return PLAYER2_WON;
	if (isSameLoc(maze.computer.information.currentLocation, EndPoint)) return COMPUTER_WON;
	return NOTEND;
}
void printOneMap(const int xaxis, const int yaxis, const OneMap targetMap)
{
	cersorMoveTo(xaxis, yaxis);
	for (int i = 0; i < MAXMAPLENGTH * MAXMAPLENGTH; i++) {
		if (i % MAXMAPLENGTH == 0) cersorMoveTo(xaxis, yaxis + i / MAXMAPLENGTH);
		wprintf(L"%lc", targetMap[i]);
	}
	cersorMoveTo(0, 2);
}
void changeCondition(Player* targetP, const int diffx, const int diffy)
{
	if (isInvaildMove(targetP->mazeMap, targetP->currentLocation, diffx, diffy))
		return;
	
	targetP->lastLocation.x = targetP->currentLocation.x;
	targetP->lastLocation.y = targetP->currentLocation.y;
	targetP->mazeMap[targetP->currentLocation.y * MAXMAPLENGTH + targetP->currentLocation.x] = NON_BLOCKED;
	targetP->currentLocation.x += diffx;
	targetP->currentLocation.y += diffy;
	targetP->mazeMap[targetP->currentLocation.y * MAXMAPLENGTH + targetP->currentLocation.x] = targetP->mark;
}
int updateMaze(const int key, Player* currentPlayer, const int screenXAxis)
{
	switch (key) {
	case A:
	case L'け':
	case LEFT:
		changeCondition(currentPlayer, -MOVEGAP, 0);
		updateElement(*currentPlayer, screenXAxis);
		break;
	case W:
	case L'じ':
	case UP:
		changeCondition(currentPlayer, 0, -MOVEGAP);
		updateElement(*currentPlayer, screenXAxis);
		break;
	case S:
	case L'い':
	case DOWN:
		changeCondition(currentPlayer, 0, MOVEGAP);
		updateElement(*currentPlayer, screenXAxis);
		break;
	case D:
	case L'し':
	case RIGHT:
		changeCondition(currentPlayer, MOVEGAP, 0);
		updateElement(*currentPlayer, screenXAxis);
		break;
	}

	return 0;
}
void updateElement(const Player targetP, const int screenXAxis)
{
	cersorMoveTo(screenXAxis + targetP.lastLocation.x * UPDATEGAP, PY + targetP.lastLocation.y);
	wprintf(L"%lc", targetP.mazeMap[targetP.lastLocation.y * MAXMAPLENGTH + targetP.lastLocation.x]);

	cersorMoveTo(screenXAxis + targetP.currentLocation.x * UPDATEGAP, PY + targetP.currentLocation.y);
	wprintf(L"%lc", targetP.mazeMap[targetP.currentLocation.y * MAXMAPLENGTH + targetP.currentLocation.x]);
	cersorMoveTo(0, 2);
}
int retByComputer()
{
	return getBestWayOfMaze(maze.computer.information.currentLocation.x, maze.computer.information.currentLocation.y);
}
int getBestWayOfMaze(int currX, int currY)
{
	return maze.computer.correctPath[currY * MAXMAPLENGTH + currX];
}

void* nullFunction(void * arg)
{
	while (!isStageEnd) {
		pthread_mutex_lock(&update);
		wprintf(L"null\n");
		getChr();
		pthread_mutex_unlock(&update);
	}
	return NULL;
}
void* player1Map(void * arg)
{
	if (maze.isOnlyOneMap)
		printOneMap(PX, PY, maze.players.player1.mazeMap);
	else
		printOneMap(P1PX, PY, maze.players.player1.mazeMap);

	return NULL;
}
void* player2Map(void *arg)
{
	printOneMap(P2PX, PY, maze.players.player2.mazeMap);

	return NULL;
}
void* computerMap(void * arg)
{
	if (maze.isOnlyOneMap)
		printOneMap(PX, PY, maze.computer.information.mazeMap);
	else
		printOneMap(P1PX, PY, maze.computer.information.mazeMap);

	return NULL;
}
void* player1Update(void * arg)
{
	while (!isStageEnd()) {
		pthread_mutex_lock(&update);
		wprintf(L"player1\n");
		if (maze.isOnlyOneMap)
			updateMaze(getChr(), &maze.players.player1, PX);
		else
			updateMaze(getChr(), &maze.players.player1, P1PX);
		
		Sleep(50);
		pthread_mutex_unlock(&update);
	}

	return NULL;
}
void* player2Update(void * arg)
{
	while (!isStageEnd()) {
		pthread_mutex_lock(&update);
		wprintf(L"player2\n");
		if (maze.isPlayer2Exists)
			updateMaze(getChr(), &maze.players.player2, P2PX);
		Sleep(50);
		pthread_mutex_unlock(&update);
	}

	return NULL;
}
void* computerUpdate(void * arg)
{
	while (!isStageEnd()) {
		pthread_mutex_lock(&update);
		wprintf(L"computer\n");
		if (maze.isOnlyOneMap)
			updateMaze(retByComputer(), &maze.computer.information, PX);
		else
			updateMaze(retByComputer(), &maze.computer.information, P1PX);
		Sleep(100);
		pthread_mutex_unlock(&update);
	}
	return NULL;
}