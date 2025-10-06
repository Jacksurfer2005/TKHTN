/*
 * display_led.c
 *
 * Created: 10/4/2025 10:19:09 PM
 *  Author: DELL
 */ 
#include "display_led.h"

uint8_t hang[8];

void display_led(void){
	for (int i=0;i<8;i++){
		hang[i]=0;
	}
	// v? thân r?n
	for (int i=0;i<snake_length;i++){
		hang[snake[i].x] |= (1<<snake[i].y);
	}
	// v? th?c ?n
	hang[food.x] |= (1<<food.y);
	
	for (int i=0;i<8;i++){
		drawrows(i+1,hang[i]);
	}
}


