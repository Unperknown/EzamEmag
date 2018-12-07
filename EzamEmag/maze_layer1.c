#include "maze.h"

bool isInvaildMove(const OneMap, const Axis, const int, const int);
bool solveMaze(int, int);
int selectByCersor();
// Layer 1 methods

extern int setStatus(const enum status);
extern enum status getStatus();
extern wchar_t* getStr(const int);
extern int getChr();
extern void cersorMoveTo(const int, const int);
extern bool isSameLoc(const Axis, const Axis);
extern int initalizeElement();
extern Element* linkEachElement(Element*);
extern int generateMazeMap(OneMap);
// import Layer 0 methods

bool isInvaildMove(const OneMap targetMap, const Axis currLoc, const int diffx, const int diffy)
{
	if (targetMap[(currLoc.y + diffy) * MAXMAPLENGTH + currLoc.x + diffx] != NON_BLOCKED)
		return true;
	else if ((currLoc.x + diffx) < 0 || (currLoc.x + diffx) > MAXMAPLENGTH || (currLoc.y + diffy) < 0 || (currLoc.y + diffy) > MAXMAPLENGTH)
		return true;
	else
		return false;
}
bool solveMaze(int xaxis, int yaxis)
{
	if (maze.computer.information.mazeMap[yaxis * MAXMAPLENGTH + xaxis] == BLOCKED)
		return false;
	//현재 좌표가 막혀 있으면 false
	if (maze.computer.alreadyPassed[yaxis * MAXMAPLENGTH + xaxis] == true)
		return false;
	//이미 지나간 좌표면 false
	if (xaxis == STOPX && yaxis == STOPY) {
		maze.computer.correctPath[yaxis * MAXMAPLENGTH + xaxis] = S;
		return true;
	}
	//끝점에 도달하면 true

	if (xaxis == STARTX && yaxis == STARTY)
		maze.computer.correctPath[yaxis * MAXMAPLENGTH + xaxis] = S;

	maze.computer.alreadyPassed[yaxis * MAXMAPLENGTH + xaxis] = true;
	if (xaxis >= 0) {
		if (solveMaze(xaxis - 1, yaxis)) {
			maze.computer.correctPath[yaxis * MAXMAPLENGTH + xaxis] = A;
			return true;
		}
	}
	if (xaxis <= MAXMAPLENGTH - 1) {
		if (solveMaze(xaxis + 1, yaxis)) {
			maze.computer.correctPath[yaxis * MAXMAPLENGTH + xaxis] = D;
			return true;
		}
	}
	if (yaxis >= 0) {
		if (solveMaze(xaxis, yaxis - 1)) {
			maze.computer.correctPath[yaxis * MAXMAPLENGTH + xaxis] = W;
			return true;
		}
	}
	if (yaxis <= MAXMAPLENGTH - 1) {
		if (solveMaze(xaxis, yaxis + 1)) {
			maze.computer.correctPath[yaxis * MAXMAPLENGTH + xaxis] = S;
			return true;
		}
	}

	return false;
}
int selectByCersor()
{
	Axis cersor;
	cersor.x = INITX;
	cersor.y = INITFIROP;

	bool isSelected = true;

	//will be refactored soon
	while (isSelected) {
		cersor.y = cersor.y < INITFIROP ? INITFIFOP : (cersor.y > INITFIFOP ? INITFIROP : cersor.y);
		cersorMoveTo(cersor.x, cersor.y);
		switch (getChr()) {
		case UP:
			cersor.y -= INITSCRGAP;
			break;
		case DOWN:
			cersor.y += INITSCRGAP;
			break;
		case ENTER:
			switch (cersor.y) {
			case INITFIROP:
				return SINGLE_MAZE;
				break;
			case INITSECOP:
				return MULTIPLE_MAZE;
				break;
			case INITTHROP:
				return DEMOSTRATE_MAZE;
				break;
			case INITFOUOP:
				return MAZE_WITH_COMPUTER;
				break;
			case INITFIFOP:
				return EXIT;
				break;
			}
			break;
		}
	}
	
	return 1;
}