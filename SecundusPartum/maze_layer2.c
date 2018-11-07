#include "maze.h"

Player setPlayer();
Board createOneMaze(Axis topLeft);
Board mazeGenerator();
Axis getStartingPoint(); //exception when maze board has not been initalized
Axis getEndPoint();
bool isStageEnd(LinkedPlayer players);
// layer 2 methods

extern Board mazeGenerator();
// import layer 1 methods

Player setPlayer()
{
	wprintf(L"������ �÷��̾� �ѱ��\n");
	return (Player)NULL;
}
Board createOneMaze(Axis topLeft)
{
	wprintf(L"������� �� �ѱ��\n");
	return mazeGenerator();
}
Axis getStartingPoint()
{
	wprintf(L"������ ���� ������ �ѱ��\n");
	return (Axis)NULL;
}
Axis getEndPoint()
{
	wprintf(L"���� ���� ������ �ѱ��\n");
	return (Axis)NULL;
}
bool isStageEnd(LinkedPlayer players)
{
	wprintf(L"���������� �������� üũ\n"); 
	return true;
}