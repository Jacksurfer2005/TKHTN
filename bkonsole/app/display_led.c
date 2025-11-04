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

//================ DISPLAY LED =================//
void display_led2(void)
{
	// Xóa buffer
	for (uint8_t i = 0; i < 8; i++) hang[i] = 0;

	// V? paddle
	for (uint8_t i = 0; i < PADDLE_LEN; i++)
	{
		int col = paddle.y + i;
		if (col < 8)  // tránh v??t quá c?t
		hang[paddle.x] |= (1 << (7 - col));  // ??o bit gi?ng bóng
	}

	// V? bóng
	hang[ball.x] |= (1 << (7 - ball.y));

	// Xu?t ra MAX7219
	for (uint8_t r = 0; r < 8; r++)
	drawrows(r + 1, hang[r]);
}

void blink_display(void){
	for (int i=0;i<8;i++){
		for (int j=0;j<8;j++) hang[i]|=(1<<j);
	}
	for (uint8_t r = 0; r < 8; r++)
	drawrows(r + 1, hang[r]);
	_delay_ms(25);
	clearMatrix();
	_delay_ms(25);
	for (uint8_t r = 0; r < 8; r++)
	drawrows(r + 1, hang[r]);
	_delay_ms(25);
	clearMatrix();
}









