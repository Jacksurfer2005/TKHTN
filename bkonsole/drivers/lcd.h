/*
 * lcd.h
 *
 * Created: 11/2/2025 12:13:47 AM
 *  Author: DELL
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "config.h"
void lcd_send_4bit(uint8_t data);
void lcd_cmd(uint8_t cmd);
void lcd_data(uint8_t data);
void lcd_init(void);
void lcd_print_line1(char *str);
void lcd_print_line2(char *str);



#endif /* LCD_H_ */