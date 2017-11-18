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
#include "shapeController.h"
#include <math.h>

//globals
uint32_t newPot =0;
uint32_t oldPot =0;


/*
unsigned short rotateShape(unsigned short shape[]) {
	//rotate the matrix
}



__task void spawnShape(void) {
	//Introduces a new shape at the top once the last one has settled
}
__task void updateGameBoard(void) {
	//Shifts the shape down and rotate or shift side to side if possible
	//update score here after?
}
__task void readPeripherals(void) {
	//reads potentiometer to rotate shape
	uint32_t newPot=potentiometer_read();

	//joystick read
	uint32_t jstick=joystick_read();
	unsigned char *direction = "NO DIR";
	unsigned char *pushed = "Not Pressed";
	if ((jstick &(1<<3))== (1<<3)) {
		//8
		direction="left";
	}
	if ((jstick &(1<<5))== (1<<5)) {
		//32
		direction="RIGHT";
	}
	if ((jstick &(1<<6))== (1<<6)) {
		//64
		direction="DOWN";
	}
	if ((jstick &(1<<4))== (1<<4)) {
		//16
		direction="up";
	}
	if ((jstick &(1<<0))== (1<<0)) {
		pushed ="pushed";
	}
	
	//Push button read
	uint32_t pbutton = LPC_GPIO2->FIOPIN;
	if ((pbutton & (1<<10)) == 0){
	//drop block
	}
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
	/*
	LED_setup();
	LED_display(3);
	printf(" \n");
	//joystick_setup();
	potentiometer_setup();
	while(1){
	newPot=potentiometer_read();
	if(newPot-oldPot>100){
		printf("%x \n",newPot);
		}
	oldPot=newPot;
	}
	*/
	int spin = 0, i = 0;
	printf(" \n");
	spawnShape();
	initializeGameBoard();
	checkFullRows();
	for (i = 0; i < 50; i++) {
		for (spin = 0; spin < 17000000; spin ++);
		downShift();
		updateGameBoard();
		if (i % 2 == 0){
			rotateRight();
		} else {
		}
		
		updateGameBoard();
		if (i == 21) {
			spawnShape();
		}
		
	}
	//os_sys_init(start_tasks);
	//while(1);
	
}
