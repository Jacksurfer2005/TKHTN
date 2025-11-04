/*
 * buzzer.c
 *
 * Created: 10/4/2025 8:41:27 PM
 *  Author: DELL
 */ 
#include "buzzer.h"

void PWM_init(void) {
	DDRB = DDRB | (1 << PB1);
	TCCR1A = (1 << COM1A1) | (1 << WGM10);
	TCCR1B = (1 << WGM12) | (1 << CS11) | (1 << CS10);
	OCR1A = 0;
}

void buzzer_on(void) { OCR1A = 128; }
void buzzer_off(void) { OCR1A = 0; }

void buzzer_melody(void) {
	buzzer_on();
	_delay_ms(100);
	buzzer_off();
	_delay_ms(50);
	buzzer_on();
	_delay_ms(50);
	buzzer_off();
}

void buzzer_melody2(void) {
	buzzer_on();
	_delay_ms(50);
	buzzer_off();
	_delay_ms(50);
	buzzer_on();
	_delay_ms(100);
	buzzer_off();
}