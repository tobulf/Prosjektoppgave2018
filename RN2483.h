/*
 * RN2483.h
 *
 * Created: 12/25/2018 3:18:25 PM
 *  Author: tobul
 */ 


#ifndef RN2483_H_
#define RN2483_H_

#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>




class LoRa_COM{
	public:
	LoRa_COM();
	unsigned char* get_answer(void);
	unsigned char receive(void);
	void transmit( uint8_t data );
	void send_command(char *string);
	protected:
	
	private:
	unsigned char string[150];
};



class RN2483: public LoRa_COM {
	public:
	RN2483();
	protected:
	private:
};






#endif /* RN2483_H_ */