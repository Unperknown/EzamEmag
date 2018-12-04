#include "maze.h"

Element* nodeOfMap;

int initalizeElement();
Element* linkEachElement(Element*);
int generateMazeMap(OneMap);
int getch_();
void cersorMoveTo(int, int);
void* nullFunction(void *);
//layer 0 methods

int initalizeElement() {
	Element *n;

	nodeOfMap = calloc(MAXMAPLENGTH * MAXMAPLENGTH, sizeof(Element));
	//Element 배열 포인터에 메모리 할당
	for (int w = 0; w < MAXMAPLENGTH; w++) {
		for (int h = 0; h < MAXMAPLENGTH; h++) {
			n = nodeOfMap + w + h * MAXMAPLENGTH;

			if (w * h % 2) {
				n->axis.x = w;
				n->axis.y = h;
				n->condition = NON_BLOCKED;
				n->directions = 15; //15개의 길이 있다고 가정 하에
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

		//모두 탐색했을 경우 최종적으로 탐색
		if (~target->directions & direction) continue;

		target->directions &= ~direction;

		switch (direction)
		{
			//오른쪽으로 가는지
		case 1:
			if (target->axis.x + 2 < MAXMAPLENGTH)
			{
				tmpAxis.x = target->axis.x + 2;
				tmpAxis.y = target->axis.y;
			}
			else continue;
			break;
			//아래로 내려가는지
		case 2:
			if (target->axis.y + 2 < MAXMAPLENGTH)
			{
				tmpAxis.x = target->axis.x;
				tmpAxis.y = target->axis.y + 2;
			}
			else continue;
			break;
			//왼쪽으로 가는지
		case 4:
			if (tmpAxis.x = target->axis.x >= 0)
			{
				tmpAxis.x = target->axis.x - 2;
				tmpAxis.y = target->axis.y;
			}
			else continue;
			break;
			//위로 올라가는지
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
			//노드가 연결되어 있는지(=미로 길이 있는지, Linked List인지)
			if (destination->parent != NULL) continue;
		
			//연결되어 있지 않으면 연결->벽 없애기->미로 길 생성
			destination->parent = target;
		
			//벽 없애기
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

	for (int i = 0; i < MAXMAPLENGTH * MAXMAPLENGTH; i++) {
		target[i] = nodeOfMap[i].condition;
	}

	target[1] = STARTPOINT;
	target[28 * MAXMAPLENGTH + 27] = ENDPOINT;

	return 1;
}
int getch_()
{
	char ch;
	if ((ch = _getch()) == -32 || ch == 0)
		ch = _getch();

	return ch;
}
void cersorMoveTo(int x, int y)
{
	COORD position = { x, y };
	static HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, position);
}
void* nullFunction(void * arg)
{
	return NULL;
}