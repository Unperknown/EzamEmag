#include "maze.h"

int setGameData(int, int);
int executeGame();
int selectByCersor();
// Layer 4 methods

extern int mazeGenerate(int);
extern int setPlayerInformation(int);
extern int showMazeStage();
extern void printMaze();
// import Layer 3 methods

extern int getch_();
extern void cersorMoveTo(int, int);
// import Layer 0 methods

int setGameData(int quantityOfMaze, int amountOfPlayer)
{
	static int currentStage = 1;
	maze.stage = currentStage++;

	mazeGenerate(quantityOfMaze);
	setPlayerInformation(amountOfPlayer);

	return 0;
}
int executeGame()
{
	showMazeStage();
	
	return 0;
}
int selectByCersor() {
	Axis cersor;
	cersor.x = INITX;
	cersor.y = INITFIROP;

	bool isSelected = true;

	//will be refactored soon
	while (isSelected) {
		cersor.y = cersor.y < INITFIROP ? INITFIFOP : (cersor.y > INITFIFOP ? INITFIROP : cersor.y);
		cersorMoveTo(cersor.x, cersor.y);
		switch (getch_()) {
		case UP:
			cersor.y -= INITSCRGAP;
			break;
		case DOWN:
			cersor.y += INITSCRGAP;
			break;
		case ENTER:
			switch (cersor.y) {
			case INITFIROP:
				return SINGLE_MAZE;
				break;
			case INITSECOP:
				return MULTIPLE_MAZE;
				break;
			case INITTHROP:
				return DEMOSTRATE_MAZE;
				break;
			case INITFOUOP:
				return MAZE_WITH_COMPUTER;
				break;
			case INITFIFOP:
				return CUSTOM_MAZE;
				break;
			}
			break;
		}
	}
	
	return 1;
}