/*
 * mini_game2.c
 * Game bóng n?y trên LED ma tr?n 8x8 (MAX7219)
 * Quy ??c: x = hàng (0..7), y = c?t (0..7)
 */

#include "mini_game2.h"

uint8_t random_0_7(void) {
	return rand() % 8;  // sinh ra giá tr? 0,1,2,3,4,5,6,7
}

int8_t random_neg1_0_1(void) {
	int r = rand() % 3;   // r = 0, 1, 2
	return r - 1;         // k?t qu?: -1, 0, 1
}

//================ GLOBAL =================//
Point paddle;
Point ball;
uint8_t dir_x_ball, dir_y_ball;
uint8_t hang[8];

//================ INIT =================//
void init_game(void) {
    paddle.x = 7;
    paddle.y = 4; // gi?a
    ball.x = 0;
    ball.y = random_0_7();
    dir_x_ball = 1;  // xu?ng
    dir_y_ball = random_neg1_0_1();  // sang ph?i
}

void move_pandle(void)
{
	if (dir_y == 2) {           // lên
		if (paddle.y > 0) paddle.y -= 1;
		} else if (dir_y == 1) {    // xu?ng
		if (paddle.y < (8 - PADDLE_LEN)) paddle.y += 1;
	}
	dir_y = 0; // reset sau m?i b??c
}



//================ CHECK GAME OVER =================//
void check_game_over(void) {
	if (ball.x > 7) {
		blink_display();
		buzzer_melody();
		init_game();
	}
}


void update_ball(void) {
	int8_t next_x = ball.x + dir_x_ball;
	int8_t next_y = ball.y + dir_y_ball;

	// --- Va t??ng trái/ph?i ---
	if (next_y < 0) {
		next_y = 0;
		dir_y_ball = -dir_y_ball;
		} else if (next_y > 7) {
		next_y = 7;
		dir_y_ball = -dir_y_ball;
	}

	// --- Va tr?n ---
	if (next_x < 0) {
		next_x = 0;
		dir_x_ball = 1; // ?i xu?ng
	}

	// --- Va paddle ---
	// Ch? x? lý n?u paddle h?p l? (y t? 0..5) và bóng ? hàng cu?i (x = 7)
	if (next_x == 7 && paddle.y >= 0 && paddle.y <= 5) {
		if (next_y >= paddle.y && next_y <= paddle.y + 2) {
			dir_x_ball = -1; // n?y lên

			// H??ng ngang tùy v? trí ch?m paddle
			if (next_y == paddle.y) dir_y_ball = -1;
			else if (next_y == paddle.y + 2) dir_y_ball = 1;
			else dir_y_ball = 0;

			next_x = 6; // tránh dính paddle
		}
	}

	// --- C?p nh?t v? trí bóng ---
	ball.x = next_x;
	ball.y = next_y;
}


//================ PLAY =================//
void play_game(void)
{
	move_pandle();      // di chuy?n paddle tr??c
	update_ball();      // c?p nh?t bóng, n?y n?u trúng paddle
	check_game_over();  // ki?m tra bóng l?t xu?ng
	display_led2();     // hi?n th? ma tr?n
}

