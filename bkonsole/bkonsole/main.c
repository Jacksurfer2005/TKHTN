#include "config.h"
#include "spi_init.h"
#include "max_init.h"
#include "display_led.h"
#include "mini_game.h"
#include "draw_led.h"
#include "button.h"
#include "buzzer.h"
#include "lcd.h"
#include "mini_game2.h"

void game1(void);
void game2(void);

int main(void){
	DDR_INIT =0X00;
	PORT_IN =0XFF;
	SPI_MasterInit();
	MAX7219_Init();
	PWM_init();
	lcd_init();
    lcd_print_line1("Snake");
	lcd_print_line2("Pickle ball");
	dir_y=0;
	while (1){
		check_button2();
		if (dir_y!=0) break;
	}
	if (dir_y==1){
		lcd_print_line1("Snake");
		lcd_print_line2("play for fun");
		game1();
	}
	if (dir_y==2){
		lcd_print_line1("Pickle Ball");
		lcd_print_line2("play for fun");
		game2();
	}
}

// snake game
void game1(void){
		snake[0].x = 3; snake[0].y = 5;
		snake[1].x = 3; snake[1].y = 4;
		snake[2].x = 3; snake[2].y = 3;
		snake_length =3;
		//uint8_t dir_x = 0, dir_y = 1;
		spawnFood();
		blink_display();
		buzzer_melody2();
		while(1){
			clearMatrix();
			check_button();
			moveSnake();
			display_led();
			_delay_ms(tocdo);
		}
}

// ball game
void game2(){
	init_game();
	blink_display();
	buzzer_melody2();
	while (1)
	{
		clearMatrix();
		check_button2();
		play_game();
		_delay_ms(10);
	}
}