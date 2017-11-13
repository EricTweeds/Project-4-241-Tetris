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

void LED_Display_Int(uint32_t num) {

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
	os_tsk_create(spawnShape ,1);
	os_tsk_create(updateGameBoard ,1);
	os_tsk_create(readPeripherals ,1);
	os_tsk_delete_self();
}

int main(void) {
	GLCD_Init();
	GLCD_Clear(0x001F);
	os_sys_init(start_tasks);
	
	
  
	while(1);
}
