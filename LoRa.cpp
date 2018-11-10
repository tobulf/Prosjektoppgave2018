/*
 * LoRa.cpp
 *
 * Created: 07.11.2018 15:53:41
 *  Author: tobiasu
 */ 


#include "LoRa.h"



bool LoRa_init(rn2xx3& RN2483, const char* Eui, const char* Key){
	bool connected = false;
	connected = RN2483.initOTAA(Eui, Key);
	// Set data-rate to SF7/125kHz. See. Lorawan regional paramaeters p. 16.
	RN2483.setDR(5);
	return connected;
};


String LoRa_send_receive(rn2xx3& RN2483,String msg){
    int n;
    String answer;
	if(msg.length()>3){
		sscanf(msg.c_str(),"%d", &n);
		byte end = 0b00000010;
		unsigned char ta[2];
		ta[0] = (unsigned char)(n>>8);
		ta[1] = (unsigned char)n;
		RN2483.txBytes(&ta[0], 2);
		RN2483.txBytes(&end, 1);
		answer = RN2483.getRx();
        return answer;
	}
    else{
		
        return answer;
    }
};



