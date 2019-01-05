/*
 * RN2483.cpp
 *
 * Created: 12/25/2018 3:17:52 PM
 *  Author: tobul
 */ 


/*
 * UARTdriver.cpp
 *
 * Created: 05.10.2018 18:13:16
 *  Author: tobiasu
 */ 

#include "RN2483.h"



/* Declare different baudrates:*/
#define LORA_BAUD 57600UL
/* Declare UART Message terminators: */
#define LF (uint8_t)10
#define CR (uint8_t)13



unsigned char LoRa_COM::receive(void){
	/* Wait for data to be received:*/
	while ( !(UCSR0A & (1<<RXC)) );
	/*Return data from buffer:*/
	return UDR0;
}



unsigned char* LoRa_COM::get_answer(void){
	 unsigned char byte;
	 uint8_t i = 0;
	 /*receive bytes and put them in a string: */
	 while( (byte = receive()) >= LF ){
		 /*LF termination: */
		if(byte == LF){
			break;
		}
		/* Merge the bytes together to a string: */
		string[i++] = byte;
	};
	/* insert NULL to terminate the string in C-Fashion: */
	string[i] = '\0';
	return string;
 };
	
	
void LoRa_COM::send_command(char* string){
	for(; *string; ++string){
		transmit(*string);
	}
	/*Terminate using CR-LF*/
	transmit(CR);
	transmit(LF);
};



void LoRa_COM::transmit(uint8_t data){
	/* Wait for empty transmit buffer:*/
	while ( !( UCSR0A & (1<<UDRE)) );
	/* Put data into buffer:*/
	UDR0 = data;
};




LoRa_COM::LoRa_COM(){
	/*Calculate ubbr: */
	unsigned int ubrr = (F_CPU/(16*LORA_BAUD))-1U;
	/*Set baud rate */
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	/* Enable receiver and transmitter */
	UCSR0B = (1<<RXEN)|(1<<TXEN);
	/* Set frame format:  2stop bit, 8data*/
	UCSR0C = (1<<USBS)|(3<<UCSZ0);
};



RN2483::RN2483(){
}



