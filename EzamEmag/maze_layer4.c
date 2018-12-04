#include "maze.h"

int setGameData(int, int);
int executeGame();
int selectByCersor();
int setComputer(Player, OneMap);
// Layer 4 methods

enum status getStatus();
// import Layer 5 methods
extern int mazeGenerate(int);
extern int setPlayerInformation(int);
extern int updateMaze();
extern void printMaze();
extern void showWinner();
extern void* playerUpdate(void *);
extern void* computerUpdate(void *);
// import Layer 3 methods

extern int isStageEnd();
extern int isComputerEnd();
// import Layer 2 methods

extern void* nullFunction(void *);
// import Layer 0 methods

extern bool solveMaze(int, int);
// import Layer 1 methods

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
	printMaze();

	pthread_t p1, p2;

	switch (getStatus())
	{
	case SINGLE_MAZE:
		pthread_create(&p1, NULL, playerUpdate, NULL);
		pthread_create(&p2, NULL, nullFunction, NULL);
		break;
	case MULTIPLE_MAZE:
		pthread_create(&p1, NULL, playerUpdate, NULL);
		pthread_create(&p2, NULL, playerUpdate, NULL); 
		break;
	case MAZE_WITH_COMPUTER:
		pthread_create(&p1, NULL, computerUpdate, NULL);
		pthread_create(&p2, NULL, playerUpdate, NULL);
		break;
	case DEMOSTRATE_MAZE:
		pthread_create(&p1, NULL, computerUpdate, NULL);
		pthread_create(&p2, NULL, nullFunction, NULL);
		break;
	case EXIT:
		break;
	} //will be refactored soon
	
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);

	showWinner();
	
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
int setComputer(Player targetPl, OneMap targetMap)
{
	maze.computer.currentPoint = targetPl.currentLocation;
	maze.computer.targetMap = targetMap;

	for (int i = 0; i < MAXMAP; i++) {
		maze.computer.alreadyPassed[i] = false;
		maze.computer.solvedMaze[i] = false;
	}
	
	solveMaze(STARTX, STARTY);

	return 1;
}