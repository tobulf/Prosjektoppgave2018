/*
 * Keypad.c
 *
 * Created: 02.10.2018 18:45:10
 *  Author: tobiasu
 */ 



#include "Keypad.h"


/* Some Handy Macros */
#define set_bit(reg, bit ) (reg |= (1 << bit))
#define clear_bit(reg, bit ) (reg &= ~(1 << bit))





Keypad::Keypad(){
	/*Set Port B pin 4-6 to input:*/
	PORTB = (0<<PB4)|(0<<PB5)|(0<<PB6);
	/*Set Port B pin 0-7 to output:*/
	DDRB = (1<<DDB0)|(1<<DDB1)|(1<<DDB2)|(1<<DDB3)|(0<<DDB4)|(0<<DDB5)|(0<<DDB6);
	pressed = false;
	value = NOTHING;
};



bool Keypad::poll_row(int row){
	/* Check if bit-row on PIN-B, is high: */
	if((PINB>>row)&1){
		return true;
	} 
	else{
		return false;
	}
};




void Keypad::poll(){
	/* Temp value to check if a button is held: */
	bool hold = false;
	/* Iterate through the columns: */
	for(uint8_t col = 0; col < 4; col++){
		/* Set Col high: */
		set_bit(PORTB, col);
		/* Iterate through the rows: */
		for(uint8_t row = 4; row < 7; row++){
			/* Poll each row: */
			if (poll_row(row)){
				/* Hold set true and col set low: */
				hold = true;
				clear_bit(PORTB,col);
				if(!pressed){
					/* Pressed set true and value updated: */
					pressed = true;
					value = button_matrix[col][row-4];
					break;
				}
			}
		}
		/* Set Col low: */
		clear_bit(PORTB,col);
		/* If it iterates through the whole thing whitout a button being pressed, 
		and it has been pressed before, it is reset:*/
		if(col==3 && !hold && pressed){
			pressed = false;
		}
	}
	/* A button has not been pressed, value is set to nothing: */
	if(!pressed){
		value = NOTHING;
	}
	
};


/* To protect value, it is kept private: */
int Keypad::get_value(){
	return value;
};
	