/*
 * Keypad.h
 *
 * Created: 05.10.2018 14:59:39
 *  Author: tobiasu
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_


#include <stdbool.h>

enum button {NOTHING=0, ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ASTERIX, SQUARE};


void keypad_init();
bool poll_row();
bool set_column();
int keypad_poll();



#endif /* KEYPAD_H_ */