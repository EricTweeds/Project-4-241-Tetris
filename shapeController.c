#include "shapeController.h"
#include "bitmaps.h"
#include <stdlib.h>
#include "stdbool.h"
#include <stdio.h>

void spawnShape(void) {
	//Spawns a new shape into the spawning area
	int shapeType = 6;
	int rand(void);
	//shapeType = rand()%7; 
	
	if (checkSpawn() == 1) { //if there are no blocks in the spawn area
		
		if (shapeType == 0) { //square tetrino
			board[0][6] = 1;
			board[1][6] = 1;
			board[0][7] = 1;
			board[1][7] = 1;
		}
		else if (shapeType == 1) { //line tetrino
			board[0][6] = 1;
			board[0][7] = 1;
			board[0][5] = 1;
			board[0][8] = 1;
		}
		else if (shapeType == 2) { //L tetrino
			board[1][7] = 1;
			board[1][6] = 1;
			board[0][8] = 1;
			board[1][8] = 1;
		}
		else if (shapeType == 3) { //reverse L tetrino
			board[1][6] = 1;
			board[1][7] = 1;
			board[1][8] = 1;
			board[0][6] = 1;
		}
		else if (shapeType == 4) { //T tetrino
			board[1][6] = 1;
			board[1][7] = 1;
			board[0][7] = 1;
			board[1][8] = 1;
		}
		else if (shapeType == 5) { //zig left tetrino
			board[0][6] = 1;
			board[0][7] = 1;
			board[1][7] = 1;
			board[1][8] = 1;
		}
		else if (shapeType == 6) { //zig right tetrino
			board[1][6] = 1;
			board[0][7] = 1;
			board[1][7] = 1;
			board[0][8] = 1;
		}
	} else {
		//Game over!
	}
}
void downShift(void) {
	//enables gravity and has the shapes fall down one block if nothing is underneath
}
void checkFullRows(void) {
	//Checks for any complete rows and clears them
}

unsigned int checkSpawn(void) {
	//Checks if any blocks are present in the spawn are, top 2 rows
	int j = 3, i = 0;
	unsigned int clear = 1;
	for (j = 3; j < 12; j++) {
		for (i = 0; i < 2; i++) {
			if (board[i][j] == 1) {
				clear = 0;
			}
		}
	}		
	return clear;
}