/**
 * \file
 *
 * \brief IOT keypad
 *
 */

#define F_CPU 16000000UL

 

#include <util/delay.h>
#include <stdbool.h>
#include "UARTdriver.h"
#include "Keypad.h"
#include "arduino/Arduino.h"
#include "rn2xx3.h"

/* Since FILES, and FDEV doesn't work in C++, a workaround had to be made to enable printf:
   This is considered a bug by the WinAvr team, however has not been fixed.
*/
extern "C" {
	#include "Debug.h"
};


/*Define Stream for LoRa comms*/
#define LoRa Serial

/* Handy macros: */
#define set_bit(reg, bit ) (reg |= (1 << bit))
#define clear_bit(reg, bit ) (reg &= ~(1 << bit))
#define test_bit(reg, bit ) (reg & (1 << bit))






int main (void){
	/*INIT*/
	Keypad keypad;
	USART_init();
	LoRa.begin(57600);
	
	
	
	while(true){
		_delay_ms(100);
		String fisk = "halla balla";
		printf("%s \n", fisk.c_str());
		//keypad.poll();
		//int i = keypad.get_value();
		//unsigned char *info = LoRa.get_answer();
		//info = LoRa.string;
		//String info = "halla";
		//printf("%s \n", info);
		//if (keypad.pressed){
			//printf("%d", i);
		//}
		
	}

}
