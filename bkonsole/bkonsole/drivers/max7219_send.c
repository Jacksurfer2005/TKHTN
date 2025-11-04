/*
 * max7219.c
 *
 * Created: 10/4/2025 8:44:59 PM
 *  Author: DELL
 */ 
#include "max7219_send.h"

void MAX7219_Send(uint8_t addr, uint8_t data) {
	PORTB &= ~(1<<DD_SS);
	SPI_MasterTransmit(addr);
	SPI_MasterTransmit(data);
	PORTB |= (1<<DD_SS);
}