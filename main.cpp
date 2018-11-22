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
#include "LoRa_cfg.h"



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
	/*INIT*/
	timer_init();
	Keypad keypad;
	USART_init();
    timer_init();
	LED_driver leds;
	Serial.begin(57600);
	Serial.flush();
	rn2xx3 COM(Serial);
	leds.toogle(YELLOW);
	bool connected = LoRa_init(COM, appEui, appKey);
	if(connected){
		leds.toogle(YELLOW);
		leds.toogle(GREEN);
		_delay_ms(3000);
	}
	else if(!connected){
		leds.toogle(YELLOW);
		leds.toogle(RED);
		_delay_ms(3000);
	}
	//Select Mode:
	bool datacollecting = false;
	keypad.poll();
	if(keypad.get_value() == SQUARE){
		datacollecting = true;
		};
	// Timer timeout and variable:
	unsigned long timeout = 10000;
	unsigned long time = 0; // = millis();
	unsigned long time1= 0;
	// Set Red and green, to indicate that it is in dataCollect.
	leds.reset();
	leds.toogle(GREEN);
	leds.toogle(RED);
	
	while(datacollecting){
		keypad.poll();
		int value = keypad.get_value();
		byte end = 0b00000010;
		if ((millis()-time) > 1000){
			leds.toogle(YELLOW);
			time = millis();
		}
		switch (value){
			case ONE:
				COM.setDR(0);
				COM.txBytes(&end,1);
				break;
			case TWO:
				COM.setDR(1);
				COM.txBytes(&end,1);
				break;
			case THREE:
				COM.setDR(2);
				COM.txBytes(&end,1);
				break;
			case FOUR:
				COM.setDR(3);
				COM.txBytes(&end,1);
				break;
			case FIVE:
				COM.setDR(4);
				COM.txBytes(&end,1);
				break;
			case SIX:
				COM.setDR(5);
				COM.txBytes(&end,1);
				break;
			default:
				break;
		}			
	}
	
	/* Declare global variables: */
	int current_state = IDLE;
	int prev_pressed, current_pressed;
	String temp = "";
	leds.reset();
	leds.toogle(GREEN);
	leds.toogle(YELLOW);
	timeout = 10000;
	COM.setDR(5);
    /* Main Function and statemachine: */
	while(!datacollecting){
        // For every cycle: update keypad.
        keypad.poll();
        current_pressed = keypad.get_value();
        switch (current_state){
            case IDLE:
                if(keypad.is_pressed()){
                    // Toogle GREEN led to indicate POLLING:
                    leds.toogle(GREEN);
					time = millis();
					temp += current_pressed;
                    current_state = POLLING;
                };
                break;

            case POLLING:
				if (temp.length() >= 4 || (millis()-time) >= timeout){
					// A code has been entered or timeout:
					current_state = BUSY;
					break;
					}
				else if(keypad.is_pressed() && prev_pressed != current_pressed){
					// Reset timer:
					time = millis();
					temp += current_pressed;
					}
				break;


            case BUSY:
				if(temp.length() == 4){
					// Check database:
					int num;
					//String answer = "59";
					printf("%s", temp.c_str());
					String answer = LoRa_send_receive(COM, temp);
					sscanf(answer.c_str(), "%X",&num);
					
					// 0x59 is hex for "Y":
					if(num == 0x59){
						leds.toogle(GREEN);
						leds.toogle(YELLOW);
						time = millis();
					}
					// Code is wrong:
					else{
						leds.toogle(YELLOW);
						leds.toogle(RED);
						time = millis();
					}
					while(!((millis()-time) > 5000));
					// Reset:
					temp = "";
					leds.reset();
					leds.toogle(GREEN);
					leds.toogle(YELLOW);
					current_state = IDLE;
				}
				else{
					// timeout, Reset all:
					temp = "";
					leds.reset();
					leds.toogle(GREEN);
					leds.toogle(YELLOW);
					current_state = IDLE;
				}

				break;
			
            default:
                break;
        }
        // Set previously pressed number:
        prev_pressed = keypad.get_value();
	}
	
}
