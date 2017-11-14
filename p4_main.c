//November 13, 2017
//Motgan Yeung (m26yeung)
//Eric Tweedle (emtweedl)

#include <LPC17xx.h>
#include "stdio.h"
#include "stdbool.h"
#include "uart.h"
#include "GLCD.h"
#include "joystick.h"
#include "led.h"
#include "timer.h"
#include "potentiometer.h"
#include <RTL.h>
#include "bitmaps.h"


/*
unsigned short rotateShape(unsigned short shape[]) {
	//rotate the matrix
}



__task void spawnShape(void) {
	//Introduces a new shape at the top once the last one has settled
}
__task void updateGameBoard(void) {
	//Shifts the shape down and rotate or shift side to side if possible
}
__task void readPeripherals(void) {
	//reads potentiometer to rotate shape
}

__task void start_tasks(void){
	//Need better scheduling with timers and delays so the game reacts at a reactable speed
	os_tsk_create(spawnShape ,1);
	os_tsk_create(updateGameBoard ,1);
	os_tsk_create(readPeripherals ,1);
	os_tsk_delete_self();
	//uncomment task function in potentionmeter.c
}
*/
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
			}
			else {
				GLCD_Bitmap(16*j, 16*i, 16, 16,(unsigned char*)blockClear);
			}
		}
	}
}

int main(void) {
	initializeGameBoard();
								
	//os_sys_init(start_tasks);
	
	
  
	while(1);
}
