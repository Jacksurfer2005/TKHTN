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
	// c?p nh?t t?a ?? thân r?n
	for (int i=0;i<snake_length;i++){
		hang[snake[i].x] |= (1<<snake[i].y);
	}
	// c?p nh?t t?a ?? th?c ?n
	hang[food.x] |= (1<<food.y);
	
	// v? lên led
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
		if (col < 8)  // tránh tránh v??t quá c?t
		hang[paddle.x] |= (1 << (7 - col));  // c?p nh?t v? trí pandle
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
	_delay_ms(15);
	clearMatrix();
	_delay_ms(15);
	for (uint8_t r = 0; r < 8; r++)
	drawrows(r + 1, hang[r]);
	_delay_ms(15);
	clearMatrix();
}


// v? m?t c??i
void smiley_display(void) {
	uint8_t hang[8] = {
		0x3C, // 00111100
		0x42, // 01000010
		0xA5, // 10100101
		0x81, // 10000001
		0xA5, // 10100101
		0x99, // 10011001
		0x42, // 01000010
		0x3C  // 00111100
	};

	// Xu?t t?ng dòng ra LED
	for (uint8_t r = 0; r < 8; r++)
	drawrows(r + 1, hang[r]);
}


// v? m?t bu?n
void sad_display(void) {
	uint8_t hang[8] = {
		0x3C, // 00111100
		0x42, // 01000010
		0xA5, // 10100101
		0x81, // 10000001
		0x99, // 10011001
		0xA5, // 10100101
		0x42, // 01000010
		0x3C  // 00111100
	};

	// Xu?t t?ng dòng ra LED
	for (uint8_t r = 0; r < 8; r++)
	drawrows(r + 1, hang[r]);
}









