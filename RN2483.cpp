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



String LoRa_COM::get_answer(void){
	 String received;
	 unsigned char byte;
	 /*receive bytes and put them in a string: */
	 while( (byte = receive()) >= LF){
		 /*CR+LF termination: */
		 if(byte == CR){
		 	 /*Empty the buffer before breaking.*/
		 	 byte = receive();
		 	 break;
		 }
		 /* Merge the bytes together to a string: */
		 received.concat((char)byte);
	 }; 
	 return received;
 };
	
	
void LoRa_COM::send_command(String command){
	for(uint16_t i = 0; i < command.length();i++){
		transmit(command[i]);
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
	send_command("sys reset");
	/*Empty the buffer.*/
	get_answer();
	_delay_ms(500);
	
}


String RN2483::get_version(){
	send_command("sys get ver");
	return get_answer();
}


bool RN2483::assert_response(String response){
	if(response != String("ok")){
		return false;
	}
	return true;
}


bool RN2483::init_OTAA(String app_EUI, String app_key){
	bool success = true;
	String answer;
	/*Reset chip and set to 868.*/
	send_command("mac reset 868");
	if (!assert_response(get_answer())){return false;};
	/*Get device EUI*/
	send_command("sys get hweui");
	answer = get_answer();
	/*Set the device EUI*/
	send_command(String("mac set deveui ")+=answer);
	if (!assert_response(get_answer())){return false;};
	/* Set the application EUI*/
	send_command(String("mac set appeui ")+=app_EUI);
	if (!assert_response(get_answer())){return false;};
	/* Set Appkey.*/
	send_command(String("mac set appkey ")+=app_key);
	if (!assert_response(get_answer())){return false;};
	/*Set powerindex to 1, for 863 MHz(0 for 433 MHz.)*/
	send_command(String("mac set pwridx 1"));
	if (!assert_response(get_answer())){return false;};
	/* TTN does not support adaptive data-rate, thus it is turned off.*/
	send_command(String("mac set adr off"));
	if (!assert_response(get_answer())){return false;};
	/*Save current settings on the RN2483.*/
	send_command(String("mac save"));
	if (!assert_response(get_answer())){return false;};
	/* Try to join the a LoRa Network...*/
	//If it fails, retry 3 times.
	for(uint8_t i=0;i<3;i++){
		send_command(String("mac join otaa"));
		get_answer();
		answer = get_answer();
		if(answer != String("accepted")){
			success = false;
		}
		else{
			break;
		}
	}
	return success;
} 

bool RN2483::set_DR(uint8_t DR){
	send_command(String("mac set dr ")+=String(DR));
	return assert_response(get_answer());
}


bool RN2483::set_RX_window_size(uint16_t milliseconds){
	send_command(String("mac set rxdelay1 ")+=String(milliseconds));
	return assert_response(get_answer());
}

String RN2483::char_to_hex(uint8_t character){
	String hex_string;
	uint8_t msb = character >> 4;
	uint8_t lsb = character & 0x0f;
	if (msb<=9){
		hex_string.concat(msb);
	}
	else{
		hex_string.concat((char)(msb+55));
		
	}
	if (lsb<=9){
		hex_string.concat(lsb);
	}
	else{
		hex_string.concat((char)(lsb+55));
	}
	return hex_string;
};


String RN2483::TX_bytes(String data, int port){
	String hex_data;
	for (uint8_t i; i < data.length(); i++){
		hex_data.concat(char_to_hex(data[i]));
	}
	send_command(String("mac tx uncnf ")+=String(port)+=String(" ")+=hex_data);
	String answer = get_answer();
	/*Assert if the command was ok. */
	if (!assert_response(answer)) {
		send_command(String("mac tx uncnf ")+=String(port)+=String(" ")+=hex_data);
	}
	/*Assert answer: */
	answer = get_answer();
	while (!(answer.startsWith("mac_rx") ^ answer.startsWith("mac_tx"))){
		/**
		 * \todo{What to return. can be something... or nothing. maybe internal variable is an option? or return NULL value if nothing?}
		 * 
		 */
		answer = get_answer();
		switch (answer)
		{
			case answer.startsWith("not_join");
				/* code */
				break; 

			case answer.startsWith("no_free"):
				/* code */
				break;

			case answer.startsWith("silent"):
				/* code */
				break;

			case answer.startsWith("frame_count"):
				/* code */
				break;
		
			case answer.startsWith("busy"):
				/* code */
				break;


			case answer.startsWith("mac_paused"):
				/* code */
				break;

			case answer.startsWith("invalid_data"):
				/* code */
				break;
				
			case answer.startsWith("mac_err"):
				/* code */
				break;

			default:
				break;
		}
	}
	return answer;
};
	
	



