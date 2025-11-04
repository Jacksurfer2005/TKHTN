/*
 * max7219.h
 *
 * Created: 10/4/2025 8:44:44 PM
 *  Author: DELL
 */ 


#ifndef MAX7219_H_
#define MAX7219_H_
#include "config.h"
#include "spi_transmits.h"

void MAX7219_Send(uint8_t addr, uint8_t data);

#endif /* MAX7219_H_ */