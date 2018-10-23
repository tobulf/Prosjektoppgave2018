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
#include "LoRa_config.h"
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

void printInt(int i){
    printf("%d", i);
};

void(*fcnPtr)(int i) = printInt;

int fisk(int n, void(*f)(int)){
    f(n);
    return n;
}

int main (void){
	/*INIT*/
	Keypad keypad;
	USART_init();
    timer_init();
	LoRa.begin(57600);
    LoRa.flush();
    rn2xx3 lora(LoRa);
    String code = String(7020);
	while(true){
        lora.sendRawCommand(code); 
        delay(1000);
    }
}
