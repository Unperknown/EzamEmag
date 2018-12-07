#include "maze.h"

int mazeGenerate(OneMap);
int setMark(Player *);
int setComputer();
void printTitle();
void printMap();
void playMazeByKey();
void showWinner();
// layer 3 methods

pthread_mutex_t update = PTHREAD_MUTEX_INITIALIZER;

extern int isStageEnd();
extern void printOneMap(const int, const int, OneMap);
extern void changeCondition(Player*, const int, const int);
extern int updateMaze(const int, Player*, const int);
extern void updateElement(const Player, const int);
extern int retByComputer();
extern int getBestWayOfMaze(int, int);
extern void* nullFunction(void *);
extern void* player1Map(void *);
extern void* player2Map(void *);
extern void* computerMap(void *);
extern void* player1Update(void *);
extern void* player2Update(void *);
extern void* computerUpdate(void *);
// import Layer 2 methods

extern bool solveMaze(int, int);
// import Layer 1 methods

extern enum status getStatus();
extern wchar_t* getStr(int);
extern int getChr();
extern void cersorMoveTo(int, int);
extern int initalizeElement();
extern int generateMazeMap(OneMap);
// import Layer 0 methods

int mazeGenerate(OneMap targetMap)
{
	initalizeElement();
	generateMazeMap(targetMap);
	
	return 1;
}
int setMark(Player * targetP)
{
	system("cls");
	wprintf(L"\n\n\n\n");
	wprintf(L"%ls어떤 문양으로 하시겠습니까?\n\n%ls▶", BLANK, BLANK);

	targetP->mark = getStr(MAXSTR)[0];

	return 1;
}
int setComputer()
{	
	maze.computer.information.mark = L'ⓒ';
	for (int i = 0; i < MAXMAP; i++) {
		maze.computer.alreadyPassed[i] = false;
		maze.computer.correctPath[i] = L' ';
	}
	
	solveMaze(STARTX, STARTY);

	return 1;
}
void printTitle()
{
	system("cls");
	cersorMoveTo(0, 2);
	wprintf(L"%ls**종료는 ESC**\n", BLANK);
	wprintf(L"%ls	왼쪽(가운데) 맵 방향키%ls오른쪽 맵 방향키\n", HALFBLANK, MIDDLEBLANK);
	wprintf(L"%ls		Ｗ%ls		↑\n", HALFBLANK, MIDDLEBLANK);
	wprintf(L"%ls	Ａ	Ｓ	Ｄ%ls←	↓	→\n", HALFBLANK, MIDDLEBLANK);
}
void printMap()
{
	switch (getStatus())
	{
	case SINGLE_MAZE:
		player1Map(NULL);
		break;
	case MULTIPLE_MAZE:
		player1Map(NULL);
		player2Map(NULL);
		break;
	case MAZE_WITH_COMPUTER:
		computerMap(NULL);
		player2Map(NULL);
		break;
	case DEMOSTRATE_MAZE:
		computerMap(NULL);
		break;
	} //will be refactored soon

}
void playMazeByKey()
{
	pthread_t left, right;

	switch (getStatus())
	{
	case SINGLE_MAZE:
		pthread_create(&left, NULL, player1Update, NULL);
		pthread_create(&right, NULL, nullFunction, NULL);
		break;
	case MULTIPLE_MAZE:
		pthread_create(&left, NULL, player1Update, NULL);
		pthread_create(&right, NULL, player2Update, NULL);
		break;
	case MAZE_WITH_COMPUTER:
		pthread_create(&left, NULL, computerUpdate, NULL);
		pthread_create(&right, NULL, player2Update, NULL);
		break;
	case DEMOSTRATE_MAZE:
		pthread_create(&left, NULL, computerUpdate, NULL);
		pthread_create(&right, NULL, nullFunction, NULL);
		break;
	} //will be refactored soon

	pthread_join(left, NULL);
	pthread_join(right, NULL);

	pthread_mutex_destroy(&update);
}
void showWinner()
{
	system("cls");
	wprintf(L"\n\n\n\n%ls", BLANK);
	switch (isStageEnd()) {
	case PLAYER1_WON:
		wprintf(L"%ls승리하였습니다!\n", maze.isOnlyOneMap ? "" : L"왼쪽 플레이어가 ");
		break;
	case PLAYER2_WON:
		wprintf(L"오른쪽 플레이어가 승리하였습니다!\n");
		break;
	case COMPUTER_WON:
		wprintf(L"컴퓨터가 승리하였습니다!\n");
		break;
	}
	
	getStr(MAXSTR);
}