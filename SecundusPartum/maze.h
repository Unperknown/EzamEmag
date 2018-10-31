#ifndef EZAMEMAG_H
#define EZAMEMAG_H

#include <stdbool.h>

#define BLOCKED 'бс'
#define NON-BLOCKED ' '

#define STOP_GAME 0
#define START_GAME 1

/* loads of global method signatures and global variables
 *
 * 1. several macro variables: BLOCKED, NON-BLOCKED and more
 * 2. 30x30 character array: contains condition of maze(blocked, non-blocked)
 * 3. mazeGame() method: acts as the main() method, manages game stage entirely
 * 4. Player struct data: contains nickname, information about whether player won or not and more
 * (Players' informations are in txt file, need to be uploaded when it executes... but how?)
 */ 

typedef struct player {
	char name[100];
	bool isWon;
	int score;
	Player nextPlayer;
}* Player;

char board[30][30] = { 0 };

int mazeGame();

#endif
