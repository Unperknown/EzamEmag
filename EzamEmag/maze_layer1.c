#include "maze.h"

int mazeGenerator(OneMap);
bool isSameLoc(Axis, Axis);
wchar_t* getStr(int);
bool isInvaildMove(OneMap, Player*, int, int);
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