/*
 * Keypad.h
 *
 * Created: 05.10.2018 14:59:39
 *  Author: tobiasu
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <util/delay.h>
#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "UARTdriver.h"


enum button {NOTHING=-1, ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ASTERIX=42, SQUARE=35};


class Keypad{
private:
    /*Due to an error in reading the datasheet, the matrix is a mirrored self:
    // Original:
    int button_matrix[4][3] = {
	{ONE,     TWO,   THREE} ,
	{FOUR,    FIVE,  SIX}   ,
	{SEVEN,   EIGHT, NINE}  ,
	{ASTERIX, ZERO,  SQUARE}
    };*/
    // Mirrored:
    int button_matrix[4][3] = {
    {SQUARE, ZERO,  ASTERIX},
    {NINE,   EIGHT, SEVEN}  ,
    {SIX,    FIVE,  FOUR}   ,
	{THREE,     TWO,   ONE}
    };
    int value;
public:
    bool pressed;
    Keypad();
    bool poll_row(int row);
    void poll();
    int get_value();
};













#endif /* KEYPAD_H_ */