#include "config.h"
#include "spi_init.h"
#include "max_init.h"
#include "display_led.h"
#include "mini_game.h"
#include "draw_led.h"
#include "button.h"

int main(void){
	DDR_INIT =0X00;
	//PORT_IN =0XFF;
	SPI_MasterInit();
	MAX7219_Init();
	snake[0].x = 3; snake[0].y = 5;
	snake[1].x = 3; snake[1].y = 4;
	snake[2].x = 3; snake[2].y = 3;
	snake_length =3;
	//uint8_t dir_x = 0, dir_y = 1;
	spawnFood();
	while(1){
		clearMatrix();
		check_button();
		moveSnake();
		display_led();
		_delay_ms(tocdo);
	}

}

