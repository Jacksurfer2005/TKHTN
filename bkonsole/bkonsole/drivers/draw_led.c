/*
 * draw_led.c
 *
 * Created: 10/4/2025 10:03:21 PM
 *  Author: DELL
 */ 
#include "draw_led.h"

void clearMatrix(void) {
	for (uint8_t i=1; i<=8; i++) {
		MAX7219_Send(i, 0x00);
	}
}

void drawrows(uint8_t x, uint8_t y) {
	if (x <= 8) {
		MAX7219_Send(x, y);
	}
}
