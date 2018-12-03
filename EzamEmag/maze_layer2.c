#include "maze.h"

Player setOnePlayer();
int createOneMaze(OneMap);
int isStageEnd();
void printOneMap(int, int, OneMap);
void changeCondition(OneMap, Player*, int, int);
// layer 2 methods

extern int mazeGenerator(OneMap);
extern bool isSameLoc(Axis, Axis);
extern wchar_t * getStr(int);
extern bool isInvaildMove(OneMap, Player*, int, int);
// import layer 1 methods

extern int getch_();
extern void cersorMoveTo(int, int);
// import Layer 0 methods

Player setOnePlayer()
{
	//will be refactored soon
	system("cls");
	wprintf(L"\n\n");
	wprintf(L"						어떤 문양으로 하시겠습니까?\n\n				▶");
	Player retPlayer;

	retPlayer.mark = getStr(MAXSTR)[0];
	retPlayer.score = 0;
	retPlayer.currentLocation.x = STARTX;
	retPlayer.currentLocation.y = STARTY;

	return retPlayer;
}
int createOneMaze(OneMap target)
{
	mazeGenerator(target);
	return 1;
}
int isStageEnd()
{
	Axis EndPoint = { STOPX, STOPY };
	bool player1 = isSameLoc(maze.players.first.currentLocation, EndPoint);
	bool player2 = isSameLoc(maze.players.second.currentLocation, EndPoint);

	return (!player1 && player2) || (player1 && !player2) ? (player1 ? PLAYER1_WON : PLAYER2_WON) : NOTEND;
	//player1 XOR player2: check whether who won this stage
}
void printOneMap(int xaxis, int yaxis, OneMap target)
{
	cersorMoveTo(xaxis, yaxis);
	for (int i = 0; i < MAXMAPLENGTH * MAXMAPLENGTH; i++) {
		if (i % MAXMAPLENGTH == 0) cersorMoveTo(xaxis, yaxis + i / MAXMAPLENGTH);
		wprintf(L"%c", target[i]);
	}
	cersorMoveTo(0, PY);
}
void changeCondition(OneMap target, Player* player, int diffx, int diffy)
{
	if (isInvaildMove(target, player, diffx, diffy))
		return;
	
	target[player->currentLocation.y * MAXMAPLENGTH + player->currentLocation.x] = NON_BLOCKED;
	player->currentLocation.x += diffx;
	player->currentLocation.y += diffy;
	target[player->currentLocation.y * MAXMAPLENGTH + player->currentLocation.x] = player->mark;
}