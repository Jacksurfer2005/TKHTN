/*
 * draw_ledh.h
 *
 * Created: 10/4/2025 10:03:37 PM
 *  Author: DELL
 */ 


#ifndef DRAW_LEDH_H_
#define DRAW_LEDH_H_

#include "config.h"
#include "max7219_send.h"
void clearMatrix(void);
void drawrows(uint8_t x, uint8_t y);


#endif /* DRAW_LEDH_H_ */