#define _CRT_SECURE_NO_WARNINGS

#ifndef EZAMEMAG_H
#define EZAMEMAG_H

#include <stdbool.h>
#include <locale.h>
#include <wchar.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>

/* loads of global method signatures and global variables, types
 *
 * 1
 */ 

enum status { INITAL = -2, EXIT, STOPPED, SINGLE_MAZE, MULTIPLE_MAZE, MAZE_WITH_COMPUTER, DEMOSTRATE_MAZE, CUSTOM_MAZE } Status;

enum mapStatus { NOTEND, PLAYER1_WON, PLAYER2_WON };

enum mapCondition { NON_BLOCKED = L'бр', BLOCKED = L'бс', STARTPOINT = L'в├', ENDPOINT = L'в┬' };

enum maxValue { MAXMAPLENGTH = 29, MAXSTR = 100 };

enum arrowKey { ENTER = 13, LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80, A='a', W='w', S='s', D='d' };

enum initalScreenValue { INITX=48, INITSCRGAP = 1, INITFIROP = 7, INITSECOP, INITTHROP, INITFOUOP, INITFIFOP };

enum playScreenValue { MOVEGAP = 1, P1PX = 1, P2PX = 61, PY = 10 };

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
	Players players;
	Maps maps;
	int stage;
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
