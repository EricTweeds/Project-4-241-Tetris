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
uint16_t newPot =0;
uint16_t oldPot =0;
uint32_t jstick =0;
//unsigned char *direction = "NO DIR";
//unsigned char *pushed = "Not Pressed";
uint32_t pbutton=0;
int spin=0;
int score=0;
OS_SEM s1;
OS_SEM s2;
OS_SEM s3;
int newTick=0;
int oldTick=0;
__task void newShape(void){
	while(1){
	os_sem_wait(&s1,0xffff);
	spawnShape();
	os_sem_send(&s2);
	os_tsk_pass();
	}
}

__task void readPeripherals(void) {
	//reads potentiometer to rotate shape
	newPot=potentiometer_read();
	oldPot=newPot;
	while(1){
		os_sem_wait(&s2,0xffff);
		//gravity
		newTick=os_time_get();
		if ((newTick-oldTick)>200){
			downShift();
			oldTick=newTick;
		}
		
		newPot=potentiometer_read();
		if((newPot - oldPot) >= 100){
			oldPot=newPot;
			leftShift();
			//rotate left
			}
		else if((oldPot - newPot) >= 100){
			//rotate right
			oldPot=newPot;
			rightShift();
			}	
		//joystick read
		jstick=joystick_read();
		if ((jstick &(1<<3))== (1<<3)) {
			leftShift();
		}
		if ((jstick &(1<<5))== (1<<5)) {
			rightShift();
		}
		if ((jstick &(1<<6))== (1<<6)) {
			downShift();
		}
		if ((jstick &(1<<4))== (1<<4)) {
			//16
			//direction="up";
			score++;
		}
		if ((jstick &(1<<0))== (1<<0)) {
			//pushed ="pushed";
			score+=100;
		}
		//printf("%s, %s \n", direction, pushed);
		//Push button read
		pbutton = LPC_GPIO2->FIOPIN;
		if ((pbutton & (1<<10)) == 0){
		//drop block
		score+=1000;
		}
		os_sem_send(&s3);
		os_tsk_pass();
	}
}

__task void screenUpdate(void) {
	while(1){
	os_sem_wait(&s3,0xffff);
	checkFullRows();
	updateGameBoard();
	if(stopped==1){
		stopped=0;
		if (cleared==1){
		score++;
		LED_display(score);
		cleared=0;
		}
		os_sem_send(&s1);
	}
	else{
		os_sem_send(&s2);
	}
	os_tsk_pass();
	}	
}
__task void start_tasks(void){
	os_sem_init(&s1,1);
	os_sem_init(&s2,0);
	os_sem_init(&s3,0);
	os_tsk_create(newShape ,1);
	os_tsk_create(readPeripherals ,1);
	os_tsk_create(screenUpdate,1);
	os_tsk_delete_self();
}


int main(void) {
	spawnShape();
	LED_setup();
	printf(" \n");
	joystick_setup();
	potentiometer_setup();
	initializeGameBoard();
	os_sys_init(start_tasks);
	while(1);
}