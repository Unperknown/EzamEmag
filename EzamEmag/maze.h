#define _CRT_SECURE_NO_WARNINGS

#ifndef EZAMEMAG_H
#define EZAMEMAG_H

#define HAVE_STRUCT_TIMESPEC

#include <stdbool.h>
#include <locale.h>
#include <wchar.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <pthread.h>

#define BLANK L"										 "

/* loads of global method signatures and global variables, types
 *
 * 1
 */ 

enum status { INITAL = -2, EXIT, STOPPED, SINGLE_MAZE, MULTIPLE_MAZE, MAZE_WITH_COMPUTER, DEMOSTRATE_MAZE, CUSTOM_MAZE } Status;

enum mapStatus { NOTEND, PLAYER1_WON, PLAYER2_WON, COMPUTER_WON };

enum mapCondition { NON_BLOCKED = L'бр', BLOCKED = L'бс', STARTPOINT = L'б▌', ENDPOINT = L'в┬' };

enum maxValue { MAXMAPLENGTH = 29, MAXSTR = 100, MAXMAP = 841 };

enum arrowKey { ENTER = 13, LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80, A='a', W='w', S='s', D='d', NONE=0 };

enum initalScreenValue { INITX=81, INITSCRGAP = 2, INITFIROP = 8, INITSECOP = 10, INITTHROP = 12, INITFOUOP = 14, INITFIFOP = 16 };

enum playScreenValue { MOVEGAP = 1, P1PX = 34, P2PX = 94, PY = 6, UPDATEMAX = 3, UPDATEGAP = 2 };

enum playerPoint { STARTX = 1, STARTY = 0, STOPX = 27, STOPY = 27 };

typedef struct {
	int x;
	int y;
} Axis;

typedef struct {
	wchar_t mark;
	Axis currentLocation;
	int score;
} Player;

typedef wchar_t* OneMap;

typedef struct {
	OneMap first;
	OneMap second;
} Maps;

typedef struct {
	Player first, second;
}Players;

typedef struct {
	OneMap targetMap;
	wchar_t solvedMaze[MAXMAP];
	bool alreadyPassed[MAXMAP];
	Axis currentPoint;
} Computer;

typedef struct {
	Players players;
	Maps maps;
	int stage;
	Computer computer;
} Game;

typedef struct {
	Axis axis;
	wchar_t condition;
	void * parent;
	int directions;
} Element;

Game maze;
//use those types in static methods

int mazeGame();

#endif
