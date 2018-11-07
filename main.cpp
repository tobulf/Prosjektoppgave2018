/**
 * \file
 *
 * \brief IOT keypad
 *
 */



 

#include <util/delay.h>
#include <util/delay_basic.h>
#include <stdbool.h>
#include "UARTdriver.h"
#include "Keypad.h"
#include "LED_driver.h"
#include "arduino/Arduino.h"
#include "arduino/wiring_private.h"
#include "LoRa.h"



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






/*
void printInt(int i){
    printf("%d", i);
};

void(*fcnPtr)(int i) = printInt;

int fisk(int n, void(*f)(int)){
    f(n);
    return n;
}
*/
int main (void){
	/*INIT*/
	LoRa shit(Serial);
	timer_init();
	Keypad keypad;
	USART_init();
    timer_init();
	LED_driver leds;
	
	
	while(true){
		//String answer = lorawan.sendRawCommand("sys get ver");
		//printf("%s",answer.c_str());
		_delay_ms(1000);
		String msg = "7020";//receiveRawCommand(ATMEGA);
		leds.timed_toogle(GREEN, 1000);
		
	}
	
}
