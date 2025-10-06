/*
 * mini_game.c
 *
 * Created: 10/4/2025 10:18:52 PM
 *  Author: DELL
 */ 
#include "mini_game.h"

Point snake[MAX_LENGTH];
uint8_t snake_length = 3;
uint8_t dir_x = 0, dir_y = 1; // h??ng ban ??u: sang ph?i
Point food;

int randomRange(int min, int max) {
	return min + rand() % (max - min + 1);
}


void spawnFood(void) {
	int valid;
	do {
		valid = 1;  // gi? s? v? trí h?p l?
		food.x = randomRange(0,7);
		food.y = randomRange(0,7);

		// ki?m tra có trùng v?i thân r?n không
		for (int i = 0; i < snake_length; i++) {
			if (snake[i].x == food.x && snake[i].y == food.y) {
				valid = 0; // trùng ? không h?p l?
				break;
			}
		}
	} while (!valid); // n?u trùng thì sinh l?i
}

uint8_t checkCollision(Point head) {
	for (uint8_t i=1; i<snake_length; i++) {
		if (head.x == snake[i].x && head.y == snake[i].y) return 1;
	}
	return 0;
}

void moveSnake(void) {
	Point newHead;
	newHead.x = (snake[0].x + dir_x + MATRIX_SIZE) % MATRIX_SIZE;
	newHead.y = (snake[0].y + dir_y + MATRIX_SIZE) % MATRIX_SIZE;

	if (checkCollision(newHead)) {
		// Game Over: reset snake
		snake_length = 3;
		snake[0].x = 3; snake[0].y = 4;
		snake[1].x = 3; snake[1].y = 3;
		snake[2].x = 3; snake[2].y = 2;
		dir_x = 1; dir_y = 0;
		spawnFood();
		return;
	}

	for (int i = snake_length; i > 0; i--) {
		snake[i] = snake[i-1];
	}
	snake[0] = newHead;

	if (newHead.x == food.x && newHead.y == food.y) {
		snake_length++;
		//if (snake_length > MAX_LENGTH) snake_length = MAX_LENGTH;
		spawnFood();
	}
}
