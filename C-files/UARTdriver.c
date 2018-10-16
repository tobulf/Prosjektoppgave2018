

#include "UARTdriver.h"
#include <avr/io.h>

#define F_CPU 16000000UL
/* Declare different baudrates:*/
#define DEBUG_BAUD 9600UL
#define LORA_BAUD 57600UL
#define PHERIPHERAL_BAUD 9600UL





int USART_TRANSMIT_printf(char var, FILE *stream) {
	// translate \n to \r for br@y++ terminal
	if (var == '\n') USART_transmit('\r');
	USART_transmit(var);
	return 0;
}

/*Enabling prinf:*/
static FILE mystdout = FDEV_SETUP_STREAM(USART_TRANSMIT_printf, NULL, _FDEV_SETUP_WRITE);






unsigned char USART_receive(void){
	/* Wait for data to be received:*/
	while ( !(UCSR0A & (1<<RXC)) );
	/*Return data from buffer:*/ 
	return UDR0;
}



void USART_transmit( uint8_t data ){
	/* Wait for empty transmit buffer:*/
	while ( !( UCSR0A & (1<<UDRE)));
	/* Put data into buffer:*/
	UDR0 = data;
}


void USART_putstring(char *string){
	for(; *string; ++string){
		USART_transmit(*string);
	}
}




void USART_init(void){
	// Calculate ubbr:
	unsigned int ubrr =(F_CPU / (16*DEBUG_BAUD))-1U;
	/*Set baud rate */
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	/* Enable receiver and transmitter */
	UCSR0B = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 2stop bit */
	UCSR0C = (1<<USBS)|(3<<UCSZ0);
	
	
	stdout = &mystdout;
	stdin = &mystdout;
}


unsigned char LoRa_receive(void){
	/* Wait for data to be received:*/
	while ( !(UCSR1A & (1<<RXC)) );
	/*Return data from buffer:*/
	return UDR1;
}


void LoRa_putcommand(char *string){
	for(; *string; ++string){
		LoRa_transmit(*string);
	}	
};



void LoRa_transmit(uint8_t data){
	/* Wait for empty transmit buffer:*/
	while ( !( UCSR1A & (1<<UDRE)) );
	/* Put data into buffer:*/
	UDR1 = data;	
};


void LoRa_init(void){
	/*Calculate ubbr: */
	unsigned int ubrr = (F_CPU/(16*LORA_BAUD))-1U;
	/*Set baud rate */
	UBRR1H = (unsigned char)(ubrr>>8);
	UBRR1L = (unsigned char)ubrr;
	/* Enable receiver and transmitter */
	UCSR1B = (1<<RXEN)|(1<<TXEN);
	/* Set frame format:  2stop bit, 8data*/
	UCSR1C = (0<<USBS)|(3<<UCSZ0);	
};


// Peripheral UART-Communication
unsigned char Peripheral_receive(void){
	/* Wait for data to be received:*/
	while ( !(UCSR2A & (1<<RXC)) );
	/*Return data from buffer:*/
	return UDR2;
};


void Peripheral_putstring(char *string){
	for(; *string; ++string){
		Peripheral_transmit(*string);
	}
};



void Peripheral_transmit(uint8_t data){
	/* Wait for empty transmit buffer:*/
	while ( !( UCSR2A & (1<<UDRE)) );
	/* Put data into buffer, sends the data:*/
	UDR2 = data;
};


void Peripheral_init(void){
	/*Calculate ubbr: */
	unsigned int ubrr = (F_CPU/(16*PHERIPHERAL_BAUD))-1U;
	/*Set baud rate */
	UBRR2H = (unsigned char)(ubrr>>8);
	UBRR2L = (unsigned char)ubrr;
	/* Enable receiver and transmitter */
	UCSR2B = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 2stop bit */
	UCSR2C = (1<<USBS)|(3<<UCSZ0);
};