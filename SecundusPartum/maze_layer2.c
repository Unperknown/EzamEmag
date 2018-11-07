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
	wprintf(L"설정된 플레이어 넘기기\n");
	return (Player)NULL;
}
Board createOneMaze(Axis topLeft)
{
	wprintf(L"만들어진 맵 넘기기\n");
	return mazeGenerator();
}
Axis getStartingPoint()
{
	wprintf(L"시작점 참조 포인터 넘기기\n");
	return (Axis)NULL;
}
Axis getEndPoint()
{
	wprintf(L"끝점 참조 포인터 넘기기\n");
	return (Axis)NULL;
}
bool isStageEnd(LinkedPlayer players)
{
	wprintf(L"스테이지가 끝났는지 체크\n"); 
	return true;
}