#include "maze.h"

int clearBoard();
int setPlayer();
//low level method

int clearBoard()
{
	wprintf(L"�̷� ���� �ʱ�ȭ�ϴ� �Լ�\n");

	for (int i = 0; i < sizeof board; i++)
		*((char *)board + i) = ' ';

	return 1;
}
int setPlayer()
{
	wprintf(L"�÷��̾ �����ϴ� �Լ�\n");
	return 1;
}