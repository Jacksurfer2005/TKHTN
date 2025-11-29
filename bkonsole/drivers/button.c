#include "button.h"

void check_button(void){
	static uint8_t last_button = 0xFF; 
	uint8_t current_button = PINC & 0x0F; 

	// x? lí chông rung khi button thay ??i tr?ng thái
	if (current_button == last_button) return;
	last_button = current_button;

	// kh?i t?o bi?n ban ??u
	int8_t new_dir_x = dir_x;
	int8_t new_dir_y = dir_y;

	if ((PINC & (1 << PC0)) == 0) { //PD0 nh?n là lên
		new_dir_x = -1;
		new_dir_y = 0;
	}
	else if ((PINC & (1 << PC1)) == 0) { //PD1 nh?n là trái
		new_dir_y = 1;
	}
	else if ((PINC & (1 << PC2)) == 0) { //PD2 nh?n là ph?i
		new_dir_x = 0;
		new_dir_y = -1;
	}
	else if ((PINC & (1 << PC3)) == 0) { //PD3 nh?n là d??i
		new_dir_x = 1;
		new_dir_y = 0;
	}
	else {
		return; // không nút naò nh?n
	}

	// Ng?n r?n quay ??u 180 ??
	if (new_dir_x != -dir_x || new_dir_y != -dir_y) {
		dir_x = new_dir_x;
		dir_y = new_dir_y;
	}
}


void check_button2(void)
{
	static uint8_t last_state = 0xFF;
	static uint8_t stable_state = 0xFF;
	static uint8_t counter = 0;

	uint8_t now = PINC & ((1<<PC1) | (1<<PC2));   // l?y PC1, PC2

	// ki?m tra thay ??i
	if (now == last_state) {
		if (counter < 3) counter++;   // debounce nh?n 3 l?n
		else stable_state = now;      // ?ã nh?n
		} else {
		counter = 0;                  // reset khi thay ??i
	}

	last_state = now;

	// x? lý khi ?ã nh?n
	if (counter >= 3) {
		if (!(stable_state & (1<<PC1)))
		dir_y = 2;
		else if (!(stable_state & (1<<PC2)))
		dir_y = 1;
		else
		dir_y = 0;
	}
}


