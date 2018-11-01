#define _CRT_SECURE_NO_WARNINGS

#ifndef EZAMEMAG_H
#define EZAMEMAG_H

#include <stdbool.h>
#include <locale.h>
#include <wchar.h>
#include <stdlib.h>
#include <Windows.h>

/* loads of global method signatures and global variables
 *
 * 1. several macro variables: BLOCKED, NON-BLOCKED and more
 * 2. status variable: contains condition of current game stage
 * 3. 30x30 character array: contains condition of maze(blocked, non-blocked)
 * 4. mazeGame() method: acts as the main() method, manages game stage entirely
 * 5. Player struct data: contains nickname, information about whether player won or not and more
 * (Players' informations are in txt file, need to be uploaded when it executes... but how?)
 */ 

typedef struct player {
	char name[100];
	bool isWon;
	int score;
}* Player;

enum status { INITAL=-2, EXIT, STOPPED, SINGLE_MAZE, MULTIPLE_MAZE, MAZE_WITH_COMPUTER, DEMOSTRATE_MAZE, CUSTOM_MAZE } Status;

char board[30][30];
//use those objects in static methods

int mazeGame();

#endif
