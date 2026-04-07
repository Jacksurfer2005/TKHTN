/*
 * buzzer.c
 *
 * Created: 10/4/2025 8:41:27 PM
 *  Author: DELL
 */ 

#include "buzzer.h"

void PWM_init(void) {
	DDRB |= (1 << PB1);   // OC1A output

	// C?u hình Fast PWM 8-bit (nh?ng KHÔNG b?t PWM ngay)
	TCCR1A = (1 << WGM10);          // Fast PWM
	TCCR1B = (1 << WGM12);          // Fast PWM
	OCR1A = 0;

	// im l?ng
	buzzer_off();
}

void buzzer_on(void) {
	// b?t PWM non-inverting
	TCCR1A |= (1 << COM1A1);

	TCCR1B = (1 << WGM12) | (1 << CS10);

	OCR1A = 128;     // duty ~50%
}

void buzzer_off(void) {
	// T?t PWM hoàn toàn chân không dao ??ng
	TCCR1A &= ~(1 << COM1A1);

	// Kéo chân xu?ng m?c 0, im l?ng tuy?t ??i
	PORTB &= ~(1 << PB1);
}

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
