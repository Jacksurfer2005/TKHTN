/*
 * max_init.c
 *
 * Created: 10/4/2025 9:51:40 PM
 *  Author: DELL
 */ 
#include "max_init.h"

void MAX7219_Init(void) {
	MAX7219_Send(0x0F, 0x00); // display test: off
	MAX7219_Send(0x0C, 0x01); // shutdown: normal
	MAX7219_Send(0x0B, 0x07); // scan limit = 8 LEDs
	MAX7219_Send(0x0A, 0x08); // intensity: medium
	MAX7219_Send(0x09, 0x00); // decode: none

	for (uint8_t i=1; i<=8; i++) {
		MAX7219_Send(i, 0x00); // clear all
	}
}
