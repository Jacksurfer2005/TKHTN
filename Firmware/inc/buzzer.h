/*
 * buzzer.h
 *
 * Created: 10/4/2025 8:41:44 PM
 *  Author: DELL
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_

#include "config.h"
void PWM_init(void);
void buzzer_on(void);
void buzzer_off(void);
void buzzer_melody(void);
void buzzer_melody2(void);


#endif /* BUZZER_H_ */