#ifndef MINI_GAME2_H_
#define MINI_GAME2_H_

#include "config.h"
#include "display_led.h"
#include "buzzer.h"
void init_game(void);
void move_pandle(void);
void check_game_over(void);
void update_ball(void);
void play_game(void);
uint8_t random_0_7(void);
int8_t random_neg1_0_1(void);

#endif /* MINI_GAME2_H_ */
