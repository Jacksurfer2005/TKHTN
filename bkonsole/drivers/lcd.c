/*
 * lcd.c
 *
 * Created: 11/2/2025 12:13:59 AM
 *  Author: DELL
 */ 
#include "lcd.h"

// G?i 4 bit d? li?u
void lcd_send_4bit(uint8_t data) {
	LCD_PORT &= 0x0F;            // Xóa 4 bit cao
	LCD_PORT |= (data & 0xF0);   // G?i 4 bit cao vào PD4–PD7
	LCD_PORT |= (1 << E);
	_delay_us(1);
	LCD_PORT &= ~(1 << E);
	_delay_us(100);
}

// G?i 1 l?nh (8 bit)
void lcd_cmd(uint8_t cmd) {
	LCD_PORT &= ~(1 << RS); // RS=0 ? l?nh
	LCD_PORT &= ~(1 << RW); // RW=0 ? ghi

	lcd_send_4bit(cmd);          // G?i 4 bit cao
	lcd_send_4bit(cmd << 4);     // G?i 4 bit th?p
}

// G?i 1 ký t?
void lcd_data(uint8_t data) {
	LCD_PORT |= (1 << RS);  // RS=1 ? d? li?u
	LCD_PORT &= ~(1 << RW); // RW=0 ? ghi

	lcd_send_4bit(data);          // G?i 4 bit cao
	lcd_send_4bit(data << 4);     // G?i 4 bit th?p
}

// Hàm kh?i t?o LCD (chu?n th?c t?)
void lcd_init(void) {
	LCD_DDR |= 0xFF;   // PD0–PD7 là output
	_delay_ms(20);     // ??i ngu?n ?n ??nh

	// Reset chu?i kh?i t?o LCD 4-bit (theo chu?n datasheet)
	lcd_send_4bit(0x30); _delay_ms(5);
	lcd_send_4bit(0x30); _delay_us(100);
	lcd_send_4bit(0x30); _delay_us(100);
	lcd_send_4bit(0x20); _delay_us(100); // chuy?n sang 4-bit mode

	// C?u hình LCD
	lcd_cmd(0x28); // 4-bit, 2 dòng, font 5x8
	lcd_cmd(0x0C); // B?t hi?n th?, t?t con tr?
	lcd_cmd(0x06); // T? ??ng d?ch con tr? sang ph?i
	lcd_cmd(0x01); // Xóa màn hình
	_delay_ms(2);
}

// Xu?t chu?i ra hàng 1
void lcd_print_line1(char *str) {
	lcd_cmd(0x80); // ??t con tr? v? ??u hàng 1
	while (*str) lcd_data(*str++);
}

// Xu?t chu?i ra hàng 2
void lcd_print_line2(char *str) {
	lcd_cmd(0xC0); // ??t con tr? v? ??u hàng 2
	while (*str) lcd_data(*str++);
}