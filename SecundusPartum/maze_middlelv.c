#include "maze.h"

static int checkExitStatus();
static int setStatus(enum status);
static enum status getStatus();
static int setInitalValue();
static int printOption();
static int chooseOption();
static int playSingleMaze();
static int playMultiMaze();
static int playMazeWithComputer();
static int demostrateMaze();
static int customMaze();
//middle level module

static int checkExitStatus()
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
static int setStatus(enum status value)
{
	Status = value;
	return 1;
}
static enum status getStatus()
{
	return Status;
}
static int setInitalValue()
{
	setStatus(INITAL);
	clearBoard();
	setPlayer();

	return 1;
}
static int printOption()
{
	wprintf(L"��� ���� �ʱ� ��� ȭ���\n");
	return 1;
}
static int chooseOption()
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
	}
	return 1;
}
static int playSingleMaze()
{
	wprintf(L"1�ο� �̷ΰ����̶�׿�\n");
	return 1;
}
static int playMultiMaze()
{
	wprintf(L"2�ο� �̷ΰ����̷���\n");
	return 1;
}
static int playMazeWithComputer()
{
	wprintf(L"��ǻ�Ϳ� �Բ��ϴ� �̷ΰ����̷���\n");
	return 1;
}
static int demostrateMaze()
{
	wprintf(L"��ǻ���� �̷ΰ����� �����Ѵ��\n");
	return 1;
}
static int customMaze()
{
	wprintf(L"�÷��̾ ���� ���� ���� �̷ΰ����� �Ѵ��\n");
	return 1;
}