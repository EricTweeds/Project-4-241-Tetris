#include "shapeController.h"
#include "bitmaps.h"
#include <stdlib.h>
#include "stdbool.h"
#include <stdio.h>
#include "GLCD.h"
int stopped = 0;
void spawnShape(void) {
	//Spawns a new shape into the spawning area
	int shapeType = 0;
	int rand(void);
	//shapeType = rand()%7; 
	
	if (checkSpawn() == 1) { //if there are no blocks in the spawn area
		
		if (shapeType == 0) { //square tetrino
			board[0][6] = 3;
			board[1][6] = 3;
			board[0][7] = 3;
			board[1][7] = 3;
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
	int j = 3, i = 19;
	unsigned int validShift = 1;
	for (i = 19; i >= 0; i--) {
		for (j = 3; j < 12; j++) {
			if (board[i][j] == 3 && board[i+1][j] == 1) {
				validShift = 0;
			}
		}
	}
	for (i = 19; i >= 0; i--) {
		if (validShift == 1) {
			for (j = 3; j < 12; j++) {
				if (board[i][j] == 3) {
					if ((i + 1) == 19) {
						board[i+1][j] = 1;
					} else {
						board[i+1][j] = 3;
					}
					board[i][j] = 0;
				}
			}
		} else {
			for (j = 3; j < 12; j++) {
				if (board[i][j] == 3) {
					board[i][j] = 1;
				}
			}
		}
	}		
}
void leftShift(void) {
//shift the active shape left
	int j = 3, i = 19;
	unsigned int validShift = 1;
	for (j = 3; j < 12; j++) {
		for (i = 19; i >= 0; i--) {
			if (board[i][j] == 3 && (board[i][j-1] == 1 || board[i][j-1] == 2)) {
				validShift = 0;
			}
		}
	}
	for (j = 3; j < 12; j++) {
		if (validShift == 1) {
			for (i = 19; i >= 0; i--) {
				if (board[i][j] == 3) {
					board[i][j-1] = 3;
					board[i][j] = 0;
				}
			}
		}
	}	
}

void rightShift(void) {
//shift the active shape right
	int j = 11, i = 19;
	unsigned int validShift = 1;
	for (j = 11; j >= 3; j--) {
		for (i = 19; i >= 0; i--) {
			if (board[i][j] == 3 && (board[i][j+1] == 1 || board[i][j+1] == 2)) {
				validShift = 0;
			}
		}
	}
	for (j = 11; j >= 3; j--) {
		if (validShift == 1) {
			for (i = 19; i >= 0; i--) {
				if (board[i][j] == 3) {
					board[i][j+1] = 3;
					board[i][j] = 0;
				}
			}
		}
	}	
}

void checkFullRows(void) {
	//Checks for any complete rows and clears them
	int i = 19, j = 3, count = 0;
	for (i = 19; i >= 0; i--) {
		if (count < 9) {
			count = 0;
			for (j = 3; j < 12; j++) {
				if (board[i][j] == 1) {
					count ++;
				}
			}
			if (count == 9) {
				for (j = 3; j < 12; j++) {
					board[i][j] = 0;
				}
			}
		} else {
			for (j = 3; j < 12; j++) {
				board[i+1][j] = board[i][j];
				board[i][j] = 0;
			}
		}
		
	}
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
void initializeGameBoard(void) {
	//Initializes the GLCD screen to the default screen for the game
	int i = 0, j = 0; // used in for loop later on

	//pointers to 2d arrays intialized in bitmaps.h
	unsigned short (*blockSolid)[16][16] = &bs; 
	unsigned short (*blockBorder)[16][16] = &bb; 
	unsigned short (*blockClear)[16][16] = &bc;  
	
	GLCD_Init();
	GLCD_Clear(0x001F);
	
	//Cycle through gameboard array to set the inital value for each block
	//The board is divided into 16x16 super pixels
	for (i = 0; i < 20; i ++) {
		for (j = 0; j < 15; j++) {
			if (board[i][j] == 1) {
				GLCD_Bitmap(16*j, 16*i, 16, 16, (unsigned char*)blockSolid);
			} else if (board[i][j] == 2) {
				GLCD_Bitmap(16*j, 16*i, 16, 16,(unsigned char*)blockBorder);
			} else if (board[i][j] == 3) {
				GLCD_Bitmap(16*j, 16*i, 16, 16,(unsigned char*)blockSolid);
			}
			else {
				GLCD_Bitmap(16*j, 16*i, 16, 16,(unsigned char*)blockClear);
			}
		}
	}
}
void updateGameBoard(void) {
	int i = 0, j = 3; // used in for loop later on

	//pointers to 2d arrays intialized in bitmaps.h
	unsigned short (*blockSolid)[16][16] = &bs; 
	unsigned short (*blockBorder)[16][16] = &bb; 
	unsigned short (*blockClear)[16][16] = &bc;  
	
	for (i = 0; i < 20; i ++) {
		for (j = 3; j < 12; j++) {
			if (board[i][j] == 1) {
				GLCD_Bitmap(16*j, 16*i, 16, 16, (unsigned char*)blockSolid);
			} else if (board[i][j] == 2) {
				GLCD_Bitmap(16*j, 16*i, 16, 16,(unsigned char*)blockBorder);
			}
			else if (board[i][j] == 3) {
				GLCD_Bitmap(16*j, 16*i, 16, 16,(unsigned char*)blockSolid);
			}
			else {
				GLCD_Bitmap(16*j, 16*i, 16, 16,(unsigned char*)blockClear);
			}
		}
	}
}