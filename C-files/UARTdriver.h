

#ifndef UARTDRIVER_H_
#define UARTDRIVER_H_


#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>





/*Uart for debug:*/
int USART_TRANSMIT_printf(char var, FILE *stream);
unsigned char USART_receive(void);
void USART_transmit( uint8_t data );
void USART_putstring(char *string);
void USART_init(void);
/* Comms to LoRa Chip:*/ 
unsigned char LoRa_receive(void);
void LoRa_transmit( uint8_t data );
void LoRa_putcommand(char *string);
void LoRa_init(void);
/* Comms to Pheripheral:*/
unsigned char Peripheral_receive(void);
void Peripheral_transmit( uint8_t data );
void Peripheral_putstring(char *string);
void Peripheral_init(void);




#endif /* UARTDRIVER_H_ */
