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

#define BLANK L"							"
#define HALFBLANK L"		"
#define MIDDLEBLANK L"						"			

enum status { INITAL = -2, EXIT, STOPPED, SINGLE_MAZE, MULTIPLE_MAZE, MAZE_WITH_COMPUTER, DEMOSTRATE_MAZE } Status;

enum mapStatus { NOTEND, PLAYER1_WON, PLAYER2_WON, COMPUTER_WON };

enum mapCondition { NON_BLOCKED = L'бр', BLOCKED = L'бс', STARTPOINT = L'б▌', ENDPOINT = L'в├' };

enum maxValue { MAXMAPLENGTH = 29, MAXSTR = 100, MAXMAP = 841 };

enum arrowKey { ENTER = 13, LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80, A=L'a', W=L'w', S=L's', D=L'd', ESC=27, NONE=0 };

enum initalScreenValue { INITX=56, INITSCRGAP = 2, INITFIROP = 8, INITSECOP = 10, INITTHROP = 12, INITFOUOP = 14, INITFIFOP = 16 };

enum playScreenValue { MOVEGAP = 1, PX = 35, P1PX = 5, P2PX = 65, PY = 6, UPDATEMAX = 3, UPDATEGAP = 2 };

enum playerPoint { STARTX = 1, STARTY = 0, STOPX = 27, STOPY = 27 };

typedef struct {
	int x;
	int y;
} Axis;

typedef wchar_t* OneMap;

typedef struct {
	OneMap mazeMap;
	wchar_t mark;
	Axis lastLocation;
	Axis currentLocation;
} Player;

typedef struct {
	Player player1;
	Player player2;
}Players;

typedef struct {
	Player information;
	wchar_t correctPath[MAXMAP];
	bool alreadyPassed[MAXMAP];
} Computer;

typedef struct {
	Players players;
	Computer computer;
	bool isOnlyOneMap;
	bool isPlayer2Exists;
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
