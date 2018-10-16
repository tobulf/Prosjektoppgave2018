/*
 * UARTdriver.h
 *
 * Created: 05.10.2018 18:13:56
 *  Author: tobiasu
 */ 


#ifndef UARTDRIVER_H_
#define UARTDRIVER_H_


#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

#include "Arduino/Arduino.h"

/* Comms to LoRa Chip:*/

class LoRa_COM{
public:
	LoRa_COM();
	unsigned char* get_answer(void);
	unsigned char receive(void);
	void transmit( uint8_t data );
	void put_command(char *string);
protected:
	unsigned char string[150];

private:

};




/* Comms to Pheripheral:*/
class PHERIPHERAL_COM{
public:
	PHERIPHERAL_COM();
	unsigned char receive(void);
	void transmit( uint8_t data );
	void putstring(char *string);
protected:

private:
	
};








#endif /* UARTDRIVER_H_ */