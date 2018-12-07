#include "maze.h"

int setInitalValue();
int printOption();
int chooseOption();
int playSingleMaze();
int playMultiMaze();
int playMazeWithComputer();
int demostrateMaze();
int customMaze();
int exited();
//layer 5 methods

extern int setGameData(bool, bool);
extern int executeGame();
extern int setComputer();
//import Layer 4 methods

extern int mazeGenerate(OneMap);
// import Layer 3 methods

extern int selectByCersor();
// import Layer 1 methods

extern int setStatus(enum status);
extern enum status getStatus();
// import Layer 0 methods

int setInitalValue()
{
	setStatus(INITAL);

	//allocate each maze map
	maze.players.player1.mazeMap = (OneMap)calloc(MAXMAP, sizeof(wchar_t));
	maze.players.player2.mazeMap = (OneMap)calloc(MAXMAP, sizeof(wchar_t));
	maze.computer.information.mazeMap = (OneMap)calloc(MAXMAP, sizeof(wchar_t));

	//generate each maze map
	mazeGenerate(maze.players.player1.mazeMap);
	mazeGenerate(maze.players.player2.mazeMap);
	mazeGenerate(maze.computer.information.mazeMap);

	//set location to startpoint
	maze.players.player1.currentLocation.x = STARTX;
	maze.players.player1.currentLocation.y = STARTY;
	maze.players.player2.currentLocation.x = STARTX;
	maze.players.player2.currentLocation.y = STARTY;
	maze.computer.information.currentLocation.x = STARTX;
	maze.computer.information.currentLocation.y = STARTY;

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
	wprintf(L"%ls▷	종 료 하 기", BLANK);
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
	case EXIT: setStatus(EXIT); break;
	} //will be refactored soon
	return 1;
}
int playSingleMaze()
{
	maze.isOnlyOneMap = true;
	maze.isPlayer2Exists = false;
	setGameData(false, false);
	executeGame();
	return 1;
}
int playMultiMaze()
{
	maze.isOnlyOneMap = false;
	maze.isPlayer2Exists = true;
	setGameData(true, false);
	executeGame();
	return 1;
}
int playMazeWithComputer()
{
	maze.isOnlyOneMap = false;
	maze.isPlayer2Exists = true;
	setGameData(true, true);
	setComputer();
	executeGame();
	return 1;
}
int demostrateMaze()
{
	maze.isOnlyOneMap = true;
	maze.isPlayer2Exists = false;
	setGameData(false, true);
	setComputer();
	executeGame();
	return 1;
}
int exited()
{
	exit(EXIT_FAILURE);
	return 0;
}