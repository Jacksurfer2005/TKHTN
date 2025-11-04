#include "button.h"

void check_button(void){
	static uint8_t last_button = 0xFF; // ??nh ngh?a các nút ban ??u ch?a ???c nh?n
	uint8_t current_button = PINC & 0x0F; // ??c toàn b? PORTD và l?y 4 bit cu?i (t?c là bit PD0 -> PD3)

	// X? lý ch?ng rung khi tr?ng thái button thay ??i
	if (current_button == last_button) return;
	last_button = current_button;

	// T?o bi?n v? trí con r?n t?m, n?u k có nút nào nh?n thì v? trí gi? nguyên.
	int8_t new_dir_x = dir_x;
	int8_t new_dir_y = dir_y;

	if ((PINC & (1 << PC0)) == 0) { //PD0 nh?n, r?n di chuy?n lên TRÊN
		new_dir_x = -1;
		new_dir_y = 0;
	}
	else if ((PINC & (1 << PC1)) == 0) { //PD1 nh?n, r?n di chuy?n sang TRÁI
		new_dir_x = 0;
		new_dir_y = -1;
	}
	else if ((PINC & (1 << PC2)) == 0) { //PD2 nh?n, r?n di chuy?n sang PH?I
		new_dir_x = 0;
		new_dir_y = 1;
	}
	else if ((PINC & (1 << PC3)) == 0) { //PD3 nh?n, r?n di chuy?n xu?ng D??I
		new_dir_x = 1;
		new_dir_y = 0;
	}
	else {
		return; // Không có nút nào ???c nh?n
	}

	// Ng?n r?n quay ??u 180 ??
	// Ví d? r?n ?ang ?i sang PH?I, nh?n TRÁI, n?u k ktra thì r?n t? ?âm ??u vào mình -> game over
	// Vòng l?p: ki?m tra h??ng ?i có ??I DI?N h??ng c? hay kh?
	// Có: B? QUA kh?i làm cái gì
	// Không: C?P NH?T bi?n dir_ m?i
	if (new_dir_x != -dir_x || new_dir_y != -dir_y) {
		dir_x = new_dir_x;
		dir_y = new_dir_y;
	}
}


void check_button2(void)
{
	uint8_t now = PINC;  // ??c toàn b? chân c?ng C

	// n?u không có nút nào ???c nh?n (c? PC1 và PC2 ??u = 1)
	if ((now & (1 << PC1)) && (now & (1 << PC2))) {
		dir_y = 0;
		return; // không làm gì thêm
	}

	// có nh?n ít nh?t 1 nút ? b?t ??u ch?ng d?i
	static uint8_t stable_count = 0;
	static uint8_t last_read = 0xFF;
	static uint8_t stable_state = 0xFF;

	if (now == last_read) {
		if (stable_count < 5) stable_count++;
		else stable_state = now; // ?? ?n ??nh
		} else {
		stable_count = 0;
	}
	last_read = now;

	// khi ?ã xác nh?n ?n ??nh
	if (stable_count >= 5) {
		if (!(stable_state & (1 << PC1))) {
			dir_y = 1;   // trái
		}
		else if (!(stable_state & (1 << PC2))) {
			dir_y = 2;   // ph?i
		}
		else {
			dir_y = 0;   // không nh?n
		}
	}
}


