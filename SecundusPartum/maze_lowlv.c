#include "maze.h"

static int clearBoard();
static int setPlayer();
//low level module

static int clearBoard()
{
	wprintf(L"미로 맵을 초기화하는 함수\n");
	for (int i = 0; i < sizeof board / sizeof board[0]; i++) for (int j = 0; j < sizeof board / sizeof(char); j++) board[i][j] = ' ';
	return 1;
}
static int setPlayer()
{
	wprintf(L"플레이어를 설정하는 함수\n");
	return 1;
}