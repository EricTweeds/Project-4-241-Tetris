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

//Build matrices for each shape, keep them global. Potentials make it a seperate file


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
int main(void) {
	//unsigned short shape[][] = blockSolid; 
	int i = 0, j = 0;
	unsigned short (*blockSolid)[16][16] = &bs; 
	
	GLCD_Init();
	GLCD_Clear(0x001F);
	
	for (i = 0; i < 20; i ++) {
		for (j = 0; j < 15; j++) {
			if (board[i][j] == 1) {
				GLCD_Bitmap(16*j, 16*i, 16, 16, (unsigned char*)blockSolid);
			} else if (board[i][j] == 2) {
				GLCD_Bitmap(16*j, 16*i, 16, 16,(unsigned char*)bb);
			}
			else {
				GLCD_Bitmap(16*j, 16*i, 16, 16,(unsigned char*)bc);
			}
		}
	}
	//GLCD_Bitmap (0, 0, 16,16, (unsigned char*)board);
	//GLCD_Bitmap (180, 120, 9, 8, (unsigned char*)shape);
								
	//os_sys_init(start_tasks);
	
	
  
	while(1);
}
