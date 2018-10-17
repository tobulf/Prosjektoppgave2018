/**
 * \file
 *
 * \brief IOT keypad
 *
 */



 

#include <util/delay.h>
#include <stdbool.h>
#include "UARTdriver.h"
#include "Keypad.h"
#include "arduino/Arduino.h"
#include "rn2xx3.h"
#include "arduino/wiring_private.h"
/* Since FILES, and FDEV doesn't work in C++, a workaround had to be made to enable printf:
   This is considered a bug by the WinAvr team, however has not been fixed.
*/
extern "C" {
	#include "Debug.h"
};


/* Handy macros: */
#define set_bit(reg, bit ) (reg |= (1 << bit))
#define clear_bit(reg, bit ) (reg &= ~(1 << bit))
#define test_bit(reg, bit ) (reg & (1 << bit))


/*Define Stream for LoRa comms*/
#define LoRa Serial




int main (void){
	/*INIT*/
	Keypad keypad;
	USART_init();
    timer_init();
	LoRa.begin(57600);
	rn2xx3 test(LoRa);
	
	while(true){
        delay(800);
		String fisk = "sys get ver";
        String Svar = test.sendRawCommand(fisk);
        printf("%s \n", Svar.c_str());

		
	}

}
