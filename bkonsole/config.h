#ifndef CONFIG_H
#define CONFIG_H

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#define DDR_SPI DDRB
#define DD_MOSI PB5
#define DD_SCK  PB7
#define DD_SS   PB4
#define MATRIX_SIZE 8
#define MAX_LENGTH 32
#define BUTTON PINC
#define DDR_INIT DDRC
#define PORT_IN PORTC
/*#define len PC0
#define trai PC1
#define phai PC2
#define xuong PC3*/
#define tocdo 200

typedef struct {
	uint8_t x;
	uint8_t y;
} Point;

extern Point snake[MAX_LENGTH];
extern uint8_t snake_length;
extern uint8_t dir_x, dir_y; 
extern Point food;
extern uint8_t hang[8];

#endif

