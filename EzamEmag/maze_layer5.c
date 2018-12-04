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
//layer 5 methods

extern int setGameData(int, int);
extern int executeGame();
extern int selectByCersor();
extern int setComputer(Player, OneMap);
//import layer 4 methods

extern int retByComputer();
//import Layer 3 methods

extern int getch_();
extern void cersorMoveTo(int, int);
extern int nullFunction();
// import Layer 0 methods

int checkExitStatus()
{
	if (getStatus() == EXIT)
	{
		wprintf(L"프로그램을 종료한대요!\n"); //need to be improved
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
	maze.maps.first = (OneMap)calloc(MAXMAPLENGTH * MAXMAPLENGTH, sizeof(wchar_t));
	maze.maps.second = (OneMap)calloc(MAXMAPLENGTH * MAXMAPLENGTH, sizeof(wchar_t));

	return 1;
}
int printOption()
{
	system("cls");
	wprintf(L"\n\n\n\n\n");
	wprintf(L"%ls미	로	찾	기\n\n\n", BLANK);
	wprintf(L"%ls▷	혼 자 서\n\n", BLANK);
	wprintf(L"%ls▷	둘 이 서\n\n", BLANK);
	wprintf(L"%ls▷	관 전 하 기\n\n", BLANK);
	wprintf(L"%ls▷	컴 퓨 터 랑\n\n", BLANK);
	wprintf(L"%ls▷	직 접 게 임", BLANK);
	return 1;
}
int chooseOption()
{
	switch (selectByCersor())
	{
	case SINGLE_MAZE: setStatus(SINGLE_MAZE); break;
	case MULTIPLE_MAZE: setStatus(MULTIPLE_MAZE); break;
	case MAZE_WITH_COMPUTER: setStatus(MAZE_WITH_COMPUTER); break;
	case DEMOSTRATE_MAZE: setStatus(DEMOSTRATE_MAZE); break;
	case CUSTOM_MAZE: setStatus(CUSTOM_MAZE); break;
	case EXIT: setStatus(EXIT); break;
	} //will be refactored soon
	return 1;
}
int playSingleMaze()
{
	setGameData(1, 1);
	executeGame();
	return 1;
}
int playMultiMaze()
{
	setGameData(2, 2);
	executeGame();
	return 1;
}
int playMazeWithComputer()
{
	setGameData(2, 2);
	setComputer(maze.players.first, maze.maps.first);
	executeGame();
	return 1;
}
int demostrateMaze()
{
	setGameData(1, 1);
	setComputer(maze.players.first, maze.maps.first);
	//for (int i = 0; i < MAXMAP; i++) {
	//	if (i % MAXMAPLENGTH == 0) wprintf(L"\n");
	//	wprintf(L"%lc", maze.computer.solvedMaze[i]);
	//}
	//while (true);
	executeGame();
	//Function overloading is not supported in C...
	return 1;
}
int customMaze()
{
	setGameData(2, 2);
	executeGame();
	return 1;
}