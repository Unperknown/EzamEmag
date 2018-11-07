#define _CRT_SECURE_NO_WARNINGS

#ifndef EZAMEMAG_H
#define EZAMEMAG_H

#include <stdbool.h>
#include <locale.h>
#include <wchar.h>
#include <stdlib.h>
#include <Windows.h>

/* loads of global method signatures and global variables, types
 *
 * 1. Status variable: contains condition of current game stage
 * 2. Several types: Axis, Player, Board, LinkedPlayer, LinkedBoard, Game and more
 * 3. 30x30 character array defined as Board: contains condition of maze(blocked, non-blocked)
 * 4. mazeGame() method: acts as the main() method, manages game stage entirely
 * 5. Player struct data: contains nickname, information about whether player won or not and more
 * (Players' informations are in txt file, need to be uploaded when it executes... but how?)
 */ 

typedef struct axis {
	int x;
	int y;
}* Axis;

typedef struct player {
	char name[100];
	Axis currentLocation;
	bool isWon;
	int score;
}*Player;

typedef struct linkedPlayer {
	Player currentPlayer;
	Player next;
} LinkedPlayer;

typedef char(*Board)[30][30];

typedef struct linkedBoard {
	Board currentBoard;
	Board next;
} LinkedBoard;

typedef struct game {
	LinkedPlayer players;
	LinkedBoard mazeMap;
	int stage;
} Game;

enum status { INITAL=-2, EXIT, STOPPED, SINGLE_MAZE, MULTIPLE_MAZE, MAZE_WITH_COMPUTER, DEMOSTRATE_MAZE, CUSTOM_MAZE } Status;

enum key { PLAYER1_LEFT, PLAYER1_TOP, PLAYER1_DOWN, PLAYER1_RIGHT, PLAYER2_LEFT, PLAYER2_TOP, PLAYER2_DOWN, PLAYER2_RIGHT
 };

Game maze;
//use those types in static methods

int mazeGame();

#endif
