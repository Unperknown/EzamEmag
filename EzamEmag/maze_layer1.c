#include "maze.h"

int mazeGenerator(OneMap);
bool isSameLoc(Axis, Axis);
wchar_t* getStr(int);
bool isInvaildMove(OneMap, Player*, int, int);
bool solveMaze();
// Layer 1 methods

extern Game maze;
extern int initalizeElement();
extern Element* linkEachElement(Element*);
extern int generateMazeMap(OneMap);

int mazeGenerator(OneMap target)
{
	initalizeElement();
	generateMazeMap(target);

	return 1;
}
bool isSameLoc(Axis standard, Axis target)
{
	return standard.x == target.x && standard.y == target.y;
}
wchar_t * getStr(int max_len)
{
	wchar_t * ret_str = (wchar_t *)malloc(sizeof(wchar_t) * max_len);
	ret_str = fgetws(ret_str, max_len, stdin);

	if (ret_str)
	{
		wchar_t * newline = wcschr(ret_str, '\n');
		if (newline) *newline = '\0';
		else while (getwchar() != '\n') continue;
	}

	return ret_str;
}
bool isInvaildMove(OneMap map, Player * player, int diffx, int diffy)
{
	if (map[(player->currentLocation.y + diffy) * MAXMAPLENGTH + player->currentLocation.x + diffx] != NON_BLOCKED)
		return true;
	else
		return false;
}
bool solveMaze(int xaxis, int yaxis)
{
	//기저 조건들!
	if (maze.computer.targetMap[yaxis * MAXMAPLENGTH + xaxis] == BLOCKED) return false;
	//현재 좌표가 막혀 있으면 false
	if (maze.computer.alreadyPassed[yaxis * MAXMAPLENGTH + xaxis] == true) return false;
	//이미 지나간 좌표면 false
	if (xaxis == STOPX && yaxis == STOPY) return true;
	//끝점에 도달하면 true

	if (xaxis == STARTX && yaxis == STARTY) maze.computer.solvedMaze[yaxis * MAXMAPLENGTH + xaxis] = S;

	maze.computer.alreadyPassed[yaxis * MAXMAPLENGTH + xaxis] = true;
	if (xaxis >= 0) {
		if (solveMaze(xaxis - 1, yaxis)) {
			maze.computer.solvedMaze[yaxis * MAXMAPLENGTH + xaxis] = A;
			return true;
		}
	}
	if (xaxis <= MAXMAPLENGTH - 1) {
		if (solveMaze(xaxis + 1, yaxis)) {
			maze.computer.solvedMaze[yaxis * MAXMAPLENGTH + xaxis] = D;
			return true;
		}
	}
	if (yaxis >= 0) {
		if (solveMaze(xaxis, yaxis - 1)) {
			maze.computer.solvedMaze[yaxis * MAXMAPLENGTH + xaxis] = W;
			return true;
		}
	}
	if (yaxis <= MAXMAPLENGTH - 1) {
		if (solveMaze(xaxis, yaxis + 1)) {
			maze.computer.solvedMaze[yaxis * MAXMAPLENGTH + xaxis] = S;
			return true;
		}
	}

	return false;
}