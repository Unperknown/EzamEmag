#include "maze.h"

int setStatus(const enum status);
enum status getStatus();
wchar_t* getStr(const int);
int getChr();
void cersorMoveTo(const int, const int);
bool isSameLoc(const Axis, const Axis);
int initalizeElement();
Element* linkEachElement(Element*);
int generateMazeMap(OneMap);
//Layer 0 methods

extern int setInitalOption();
// import layer 6 method

Element* nodeOfMap;

int setStatus(const enum status value)
{
	Status = value;
	return 1;
}
enum status getStatus()
{
	return Status;
}
wchar_t * getStr(const int length)
{
	wchar_t * ret_str = (wchar_t *)malloc(sizeof(wchar_t) * length);
	ret_str = fgetws(ret_str, length, stdin);

	if (ret_str)
	{
		wchar_t * newline = wcschr(ret_str, '\n');
		if (newline) *newline = '\0';
		else while (getwchar() != '\n') continue;
	}

	return ret_str;
}
int getChr()
{
	char ch = getch();
	if (ch == ESC)
		exit(EXIT_FAILURE);
	return ch;
}
void cersorMoveTo(const int x, const int y)
{
	COORD position = { x, y };
	static HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, position);
}
bool isSameLoc(const Axis standard, const Axis target)
{
	return standard.x == target.x && standard.y == target.y;
}
int initalizeElement() {
	Element *n;

	nodeOfMap = calloc(MAXMAPLENGTH * MAXMAPLENGTH, sizeof(Element));
	//allocate a pointer of array that contains each element
	for (int w = 0; w < MAXMAPLENGTH; w++) {
		for (int h = 0; h < MAXMAPLENGTH; h++) {
			n = nodeOfMap + w + h * MAXMAPLENGTH;

			if (w * h % 2) {
				n->axis.x = w;
				n->axis.y = h;
				n->condition = NON_BLOCKED;
				n->directions = 15;
				//suppose it has fifteen ways to pass
			}
			else {
				n->condition = BLOCKED;
			}
		}
	}

	return 1;
}

Element * linkEachElement(Element *target)
{
	Axis tmpAxis;
	char direction;
	Element *destination;

	while (target->directions)
	{
		direction = (1 << (rand() % 4));

		//go to next node if current node is done searching
		if (~target->directions & direction) continue;

		target->directions &= ~direction;

		switch (direction)
		{
		//go right
		case 1:
			if (target->axis.x + 2 < MAXMAPLENGTH)
			{
				tmpAxis.x = target->axis.x + 2;
				tmpAxis.y = target->axis.y;
			}
			else continue;
			break;
		//go down
		case 2:
			if (target->axis.y + 2 < MAXMAPLENGTH)
			{
				tmpAxis.x = target->axis.x;
				tmpAxis.y = target->axis.y + 2;
			}
			else continue;
			break;
		//go left
		case 4:
			if (tmpAxis.x = target->axis.x >= 0)
			{
				tmpAxis.x = target->axis.x - 2;
				tmpAxis.y = target->axis.y;
			}
			else continue;
			break;
		//go up
		case 8:
			if (tmpAxis.y = target->axis.y - 2 >= 0)
			{
				tmpAxis.x = target->axis.x;
				tmpAxis.y = target->axis.y - 2;
			}
			else continue;
			break;
		}

		destination = nodeOfMap + tmpAxis.x + tmpAxis.y * MAXMAPLENGTH;
		
		if (destination->condition == NON_BLOCKED)
		{
			//check if current node is inherited with its parent(=current path is already searched)
			if (destination->parent != NULL) continue;
		
			destination->parent = target;
		
			//create a path
			nodeOfMap[target->axis.x + (tmpAxis.x - target->axis.x) / 2 + (target->axis.y + (tmpAxis.y - target->axis.y) / 2) * MAXMAPLENGTH].condition = NON_BLOCKED;
		
			return destination;
		}
	}

	return target->parent;
}
int generateMazeMap(OneMap target)
{
	//will be REFACTORED soon
	Element *start, *last;

	start = nodeOfMap + 1 + MAXMAPLENGTH;
	start->parent = start;
	last = start;
	srand((unsigned int)time(NULL));

	while ((last = linkEachElement(last)) != start);

	for (int i = 0; i < MAXMAP; i++) {
		target[i] = nodeOfMap[i].condition;
	}

	//set point
	target[1] = STARTPOINT;
	target[28 * MAXMAPLENGTH + 27] = ENDPOINT;

	return 1;
}