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
	
	Keypad keypad;
	USART_init();
    timer_init();
	LoRa.begin(57600);
	LoRa.flush();
	LED_driver leds;
	
	
	rn2xx3 lorawan(LoRa);
	String code = String(7020);
	bool joined = false;
	joined = lorawan.initOTAA(appEui, appKey);
	String answer;
	// Set data-rate to SF7/125kHz. See. Lorawan regional paramaeters p. 16.
	lorawan.setDR(5);
	printf("%s","initialized");
	while(true){
		//String answer = lorawan.sendRawCommand("sys get ver");
		//printf("%s",answer.c_str());
		_delay_ms(1000);
		String msg = "7020";//receiveRawCommand(ATMEGA);
		leds.timed_toogle_led(GREEN, 1000);
		
		int n;
		if(msg.length()>3){
			sscanf(msg.c_str(),"%d", &n);
			unsigned char ta[2];
			ta[0] = (unsigned char)(n>>8);
			ta[1] = (unsigned char)n;
			lorawan.txBytes(&ta[0], 2);
			answer = lorawan.getRx();
		}
		printf("%s", answer.c_str());
	}
	
}
