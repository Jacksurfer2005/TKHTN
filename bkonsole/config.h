#ifndef CONFIG_H
#define CONFIG_H

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#define DDR_SPI DDRB
#define DD_MOSI PB3
#define DD_SCK  PB5
#define DD_SS   PB2
#define MATRIX_SIZE 8
#define MAX_LENGTH 32
#define BUTTON PINC
#define DDR_INIT DDRC
#define PORT_IN PORTC
#define BUZZER PB1 
#define LCD_PORT PORTD
#define LCD_DDR  DDRD

#define RS PD0
#define RW PD1
#define E  PD2
#define tocdo 10

typedef struct {
	uint8_t x;
	uint8_t y;
} Point;
#define PADDLE_LEN 3

extern Point snake[MAX_LENGTH];
extern uint8_t snake_length;
extern uint8_t dir_x, dir_y; 
extern Point food;
extern uint8_t hang[8];
extern Point paddle;
extern Point ball;
extern uint8_t dir_x_ball, dir_y_ball;

#endif

