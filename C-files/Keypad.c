/*
 * Keypad.c
 *
 * Created: 02.10.2018 18:45:10
 *  Author: tobiasu
 */ 
#include "Keypad.h"
#include <util/delay.h>
#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
/* Some Handy Macros */



#define set_bit(reg, bit ) (reg |= (1 << bit))
#define clear_bit(reg, bit ) (reg &= ~(1 << bit))





int button_matrix[4][3] = {
	{ONE,     TWO,   THREE} ,
	{FOUR,    FIVE,  SIX}   ,
	{SEVEN,   EIGHT, NINE}  ,
	{ASTERIX, ZERO,  SQUARE}
};




void keypad_init(){
	/*Set Port B pin 4-6 to input:*/
	PORTB = (0<<PB4)|(0<<PB5)|(0<<PB6);
	/*Set Port B pin 0-7 to output:*/
	DDRB = (1<<DDB0)|(1<<DDB1)|(1<<DDB2)|(1<<DDB3)|(0<<DDB4)|(0<<DDB5)|(0<<DDB6);
};



bool poll_row(int row){
	uint8_t i = PINB;
	if((i>>row)&1){
		return true;
	} 
	else{
		return false;
	}
};

bool set_column(){
	return false;
};

int keypad_poll(){
	for(uint8_t col = 0; col < 4; col++){
		set_bit(PORTB, col);
		//_delay_ms(400);
		for(uint8_t row = 4; row < 7; row++){
			//printf("%d %d ",col,row-4);
			//prinf("     ");
			//printf("%d",poll_row(5));
			//_delay_ms(200);
			if (poll_row(row)) {
				clear_bit(PORTB,col);
				//printf("%d %d ",col,row-4);
				//_delay_ms(200);
				return button_matrix[col][row-4];
			}
		}
	clear_bit(PORTB,col);
	}
	return NOTHING;
};
	

