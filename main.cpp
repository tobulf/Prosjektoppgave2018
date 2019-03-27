/**
 * \file
 *
 * \brief IOT keypad
 *
 */



 

#include <util/delay.h>
#include <util/delay_basic.h>
#include <stdbool.h>
#include "RN2483.h"
#include "Keypad.h"
#include "LED_driver.h"
#include "LoRa_cfg.h"
#include "arduino/WString.h"



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


enum state {IDLE, POLLING, BUSY};



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
	//USART_init();
	//RN2483 fisk;
	//while (true){
	//	//RN2483 fisk;
	//	fisk.send_command("sys get ver");
	//	unsigned char* answer = fisk.get_answer();
	//	printf("%s", answer);
	//	_delay_ms(1000);
	//}

	USART_init();
	RN2483 fisk;
	//bool something = fisk.init_OTAA(appEui, appKey);
	while (true){
		
		_delay_ms(1000);
	}

}
