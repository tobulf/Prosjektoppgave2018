/**
 * \file
 *
 * \brief IOT keypad
 *
 */

//#define F_CPU 16000000UL

 

#include <util/delay.h>
#include <stdbool.h>
#include "UARTdriver.h"
#include "Keypad.h"



#define set_bit(reg, bit ) (reg |= (1 << bit))
#define clear_bit(reg, bit ) (reg &= ~(1 << bit))
#define test_bit(reg, bit ) (reg & (1 << bit))




int main (void){
	USART_init();
	LoRa_init();
	Peripheral_init();
	keypad_init();
	while(true){
		int i = keypad_poll();
		//uint8_t i = PINB;
		//printf("%d", (i>>6)&1 );
		//_delay_ms(500);
		if (i){
			printf("%d", i-1);
		}
		
		//set_bit(PORTB,0);
		//printf("%d", poll_row(4));
		//_delay_ms(200);
		//printf("%d", poll_row(5));
		//_delay_ms(200);
		//printf("%d", poll_row(6));
		//printf("  ");
	}

}
