#include "maze.h"

int checkExitStatus();
int setStatus(enum status);
enum status getStatus();
int setInitalValue();
int printOption();
int chooseOption();
int playSingleMaze();
int playMultiMaze();
int playMazeWithComputer();
int demostrateMaze();
int customMaze();
//middle level method

extern int clearBoard();
extern int setPlayer();
//import low level method

int checkExitStatus()
{
	if (getStatus() == EXIT)
	{
		wprintf(L"���α׷��� �����Ѵ��!\n"); //need to be improved
		getwchar();
		getwchar();
		exit(EXIT_FAILURE);
		return 0;
	}
	return 1;
}
int setStatus(enum status value)
{
	Status = value;
	return 1;
}
enum status getStatus()
{
	return Status;
}
int setInitalValue()
{
	setStatus(INITAL);
	clearBoard();
	setPlayer();

	return 1;
}
int printOption()
{
	wprintf(L"��� ���� �ʱ� ��� ȭ���\n");
	return 1;
}
int chooseOption()
{
	enum status option; //will be replaced with choosing by cursor location soon

	wprintf(L"�� ������ ������ �����϶�� ��� ȭ���\n");
	wscanf(L"%d", &option); //will be replaced with choosing by cursor location soon

	switch (option)
	{
	case SINGLE_MAZE: setStatus(SINGLE_MAZE); break;
	case MULTIPLE_MAZE: setStatus(MULTIPLE_MAZE); break;
	case MAZE_WITH_COMPUTER: setStatus(MAZE_WITH_COMPUTER); break;
	case DEMOSTRATE_MAZE: setStatus(DEMOSTRATE_MAZE); break;
	case CUSTOM_MAZE: setStatus(CUSTOM_MAZE); break;
	case EXIT: setStatus(EXIT); break;
	default: wprintf(L"��� �̻��� �� ������ �� ����?\n"); break;
	} //need to be divided into method soon
	return 1;
}
int playSingleMaze()
{
	wprintf(L"1�ο� �̷ΰ����̶�׿�\n");
	return 1;
}
int playMultiMaze()
{
	wprintf(L"2�ο� �̷ΰ����̷���\n");
	return 1;
}
int playMazeWithComputer()
{
	wprintf(L"��ǻ�Ϳ� �Բ��ϴ� �̷ΰ����̷���\n");
	return 1;
}
int demostrateMaze()
{
	wprintf(L"��ǻ���� �̷ΰ����� �����Ѵ��\n");
	return 1;
}
int customMaze()
{
	wprintf(L"�÷��̾ ���� ���� ���� �̷ΰ����� �Ѵ��\n");
	return 1;
}