#include "shapeController.h"
#include "bitmaps.h"
#include <stdlib.h>
#include "stdbool.h"
#include <stdio.h>
#include "GLCD.h"

int shapeType = 1;
extern int stopped = 0;
extern int cleared = 0;
void spawnShape(void) {
	//Spawns a new shape into the spawning area
	
	int rand(void);
	shapeType = rand()%7; 

	if (checkSpawn() == 1) { //if there are no blocks in the spawn area
		
		if (shapeType == 0) { //square tetrino
			board[0][6] = 3;
			board[1][6] = 3;
			board[0][7] = 3;
			board[1][7] = 3;
		}
		else if (shapeType == 1) { //line tetrino
			board[1][6] = 3;
			board[1][7] = 3;
			board[1][5] = 3;
			board[1][8] = 3;
		}
		else if (shapeType == 2) { //L tetrino
			board[1][7] = 3;
			board[1][6] = 3;
			board[0][8] = 3;
			board[1][8] = 3;
		}
		else if (shapeType == 3) { //reverse L tetrino
			board[1][6] = 3;
			board[1][7] = 3;
			board[1][8] = 3;
			board[0][6] = 3;
		}
		else if (shapeType == 4) { //T tetrino
			board[1][6] = 3;
			board[1][7] = 3;
			board[0][7] = 3;
			board[1][8] = 3;
		}
		else if (shapeType == 5) { //zig left tetrino
			board[0][6] = 3;
			board[0][7] = 3;
			board[1][7] = 3;
			board[1][8] = 3;
		}
		else if (shapeType == 6) { //zig right tetrino
			board[1][6] = 3;
			board[0][7] = 3;
			board[1][7] = 3;
			board[0][8] = 3;
		}
	} else {
		//Game over!
	}
}
void downShift(void) {
	//enables gravity and has the shapes fall down one block if nothing is underneath
	int j = 3, i = 19, k = 0;
	unsigned int validShift = 1;
	printf("%d \n", board[1][7]);
	for (i = 19; i >= 0; i--) {
		for (j = 3; j < 12; j++) {
			if (board[i][j] == 3 && (board[i+1][j] == 1 || (i + 1) == 20)) {
				validShift = 0;
			}
		}
	}
	for (i = 19; i >= 0; i--) {
		if (validShift == 1) {
			for (j = 3; j < 12; j++) {
				if (board[i][j] == 3) {
					board[i+1][j] = 3;
					board[i][j] = 0;
				}
			}
		} else {
			for (k = 0; k < 4; k++) {
				for (j = 3; j < 12; j++) {
					if ((i - k) >= 0) {
						if (board[i - k][j] == 3) {
							board[i - k][j] = 1;
              stopped = 1;
						}
					}
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

void rotateRight(void) {
	//Rotates the active shape 90deg to the right
	int corneri = 0, cornerj = 0, i, j, valid = 1;
	for (i = 0; i < 19; i++) {
		for (j = 3; j < 12; j++) {
			if (board[i][j] == 3) {
				corneri = i;
				cornerj = j;
				i = 20;
				break;
			}
		}
	}
	if (shapeType == 0); //do nothing
	if (shapeType == 1) {
		for (i = 1; i< 4; i++) {
			if (board[corneri + i][cornerj] != 0) {
				valid = 0;
			}
		}
		if (valid == 1) {
			for (j = 1; j < 4; j ++) {
				board[corneri][cornerj + j] = 0;
			}
			for (i = 1; i < 4; i++) {
				board[corneri + i][cornerj] = 3;
			}
			shapeType = 7;
		}
	}
	else if (shapeType == 2) {
		if (board[corneri][cornerj - 2] != 0 || board[corneri - 1][cornerj - 2] != 0) {
			valid = 0;
		}
		if (valid == 1) {
			board[corneri][cornerj] = 0;
			board[corneri + 1][cornerj] = 0;
			board[corneri - 1][cornerj - 2] = 3;
			board[corneri][cornerj - 2] = 3;
			shapeType = 10;
		}
	}
	else if (shapeType == 3) {
		if (board[corneri - 1][cornerj] != 0 || board[corneri - 1][cornerj + 1] != 0) {
			valid = 0;
		}
		if (valid == 1) {
			board[corneri + 1][cornerj + 1] = 0;
			board[corneri + 1][cornerj + 2] = 0;
			board[corneri - 1][cornerj] = 3;
			board[corneri - 1][cornerj + 1] = 3;
			shapeType = 12;
		}
	}
	else if (shapeType == 4) {
		shapeType = 14;
	}
	else if (shapeType == 5) {
		shapeType = 17;
	}
	else if (shapeType == 6) {
		shapeType = 18;
	}
	else if (shapeType == 7) {
		for (j = 1; j < 4; j++) {
			if (board[corneri][cornerj + j] != 0) {
				valid = 0;
			}
		}
		if (valid == 1) {
			for (i = 1; i < 4; i ++) {
				board[corneri + i][cornerj] = 0;
			}
			for (j = 1; j < 4; j++) {
				board[corneri][cornerj + j] = 3;
			}
			shapeType = 1;
		}
	}
	else if (shapeType == 8) {
		if (board[corneri + 1][cornerj + 2] != 0 || board[corneri + 2][cornerj + 2] != 0) {
			valid = 0;
		}
		if (valid == 1) {
			board[corneri][cornerj] = 0;
			board[corneri + 1][cornerj] = 0;
			board[corneri + 1][cornerj + 2] = 3;
			board[corneri + 2][cornerj + 2] = 3;
			shapeType = 9;
		}
	}
	else if (shapeType == 9) {
		if (board[corneri + 2][cornerj] != 0 || board[corneri + 2][cornerj -1] != 0) {
			valid = 0;
		}
		if (valid == 1) {
			board[corneri][cornerj] = 0;
			board[corneri][cornerj + 1] = 0;
			board[corneri + 2][cornerj] = 3;
			board[corneri + 2][cornerj - 1] = 3;
			shapeType = 2;
		}
	}
	else if (shapeType == 10) {
		if (board[corneri][cornerj + 1] != 0 || board[corneri][cornerj + 2] != 0) {
			valid = 0;
		}
		if (valid == 1) {
			board[corneri + 2][cornerj] = 0;
			board[corneri + 2][cornerj + 1] = 0;
			board[corneri][cornerj + 1] = 3;
			board[corneri][cornerj + 2] = 3;
			shapeType = 8;
		}
	}
	else if (shapeType == 11) {
		if (board[corneri + 1][cornerj - 2] != 0 || board[corneri + 2][cornerj - 2] != 0) {
			valid = 0;
		}
		if (valid == 1) {
			board[corneri][cornerj] = 0;
			board[corneri + 1][cornerj] = 0;
			board[corneri + 1][cornerj - 2] = 3;
			board[corneri + 2][cornerj - 2] = 3;
			shapeType = 3;
		}
	}
	else if (shapeType == 12) {
		if (board[corneri][cornerj + 2] != 0 || board[corneri + 1][cornerj + 2] != 0) {
			valid = 0;
		}
		if (valid == 1) {
			board[corneri + 1][cornerj] = 0;
			board[corneri + 2][cornerj] = 0;
			board[corneri][cornerj + 2] = 3;
			board[corneri + 1][cornerj + 2] = 3;
			shapeType = 13;
		}
	}
	else if (shapeType == 13) {
		if (board[corneri - 1][cornerj + 1] != 0 || board[corneri - 2][cornerj + 1] != 0) {
			valid = 0;
		}
		if (valid == 1) {
			board[corneri][cornerj + 2] = 0;
			board[corneri + 1][cornerj + 2] = 0;
			board[corneri - 1][cornerj + 1] = 3;
			board[corneri - 2][cornerj + 1] = 3;
			shapeType = 11;
		}
	}
	else if (shapeType == 14) {
		shapeType = 15;
	}
	else if (shapeType == 15) {
		shapeType = 16;
	}
	else if (shapeType == 16) {
		shapeType = 4;
	}
	else if (shapeType == 17) {
		shapeType = 5;
	}
	else if (shapeType == 18) {
		shapeType = 6;
	}
	
	
	/* attempt at a general case
	int i,j,k,l, height = 4, width = 1, tempWidth, rotateCorneri = 0, rotateCornerj = 0;
	unsigned short rotationContainer[4][4], rotated[4][4];
	for (i = 0; i < 19; i++) {
		for (j = 3; j < 12; j++) {
			if (board[i][j] == 3) {
				printf("here \n");
				rotateCorneri = i;
				rotateCornerj = j;
				width = 1;
				height = 4;
				for (k = 0; k < 4; k++) {
					if ((rotateCorneri + k) < 19) {
						tempWidth = 0;
						for (l = 3; l < 12; l++) {
							if (board[rotateCorneri + k][l] == 3) {
								tempWidth ++;
							}
						}
						if (tempWidth > width) {
							width = tempWidth;
						}
						if (tempWidth == 0) {
							height = k + 1;
						}
					}
				}
				i = 20;
				break;
			}
			
		}
	}
	printf("h: %d, w: %d \n", height, width);
	if (width == 4) {
		for (j = 0; j < 4; j++) {
			rotationContainer[3][j] = 3;
			board[rotateCorneri][j + rotateCornerj] = 0;
		}
		for (i = 2; i >= 0; i--) {
			for (j = 0; j < 4; j++) {
				if ((rotateCorneri - i) >= 0 && (rotateCornerj + j) < 15) {
					rotationContainer[i][j] = board[rotateCorneri - i][rotateCornerj + j];
				} else {
					rotationContainer[i][j] = 2;
				}
			}
		}
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				rotated[i][j] = rotationContainer[j][i];
			}
		}

		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				board[i + rotateCorneri][j + rotateCornerj] = rotated[i][j];
			}
		}
	}
	else if (height == 4) {
		for (i = 0; i < 4; i++) {
			rotationContainer[i][3] = 3;
			board[rotateCorneri + i][rotateCornerj] = 0;
		}
		for (i = 0; i < 4; i++) {
			for (j = 2; j > 0; j--) {
				if ((rotateCorneri - i) >= 0 && (rotateCornerj + j) < 15) {
					rotationContainer[i][j] = board[rotateCorneri - i][rotateCornerj + j];
				} else {
					rotationContainer[i][j] = 2;
				}
			}
		}
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				rotated[i][j] = rotationContainer[j][i];
			}
		}

		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				board[i + rotateCorneri][j + rotateCornerj] = rotated[i][j];
			}
		}
	}
	*/
	
}

void rotateLeft(void) {
	//Rotates the active shape 90deg to the left
	
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
					//Increment score
				}
			}
		} else {
			for (j = 3; j < 12; j++) {
				board[i+1][j] = board[i][j];
				board[i][j] = 0;
			}
			cleared =1;
		}
		
	}
}

unsigned int checkSpawn(void) {
	//Checks if any blocks are present in the spawn are, top 2 rows
	int j = 3, i = 0;
	unsigned int clear = 1;
	for (j = 3; j < 12; j++) {
		for (i = 0; i < 2; i++) {
			if (board[i][j] == 1 || board[i][j] == 3) {
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