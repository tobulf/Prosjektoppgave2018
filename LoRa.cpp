/*
 * LoRa.cpp
 *
 * Created: 07.11.2018 15:53:41
 *  Author: tobiasu
 */ 


#include "LoRa.h"


/*Define Stream for LoRa comms*/



LoRa::LoRa(rn2xx3& com){
    _LoRa = com;
	connected = false;
	connected = _LoRa.initOTAA(appEui, appKey);
	// Set data-rate to SF7/125kHz. See. Lorawan regional paramaeters p. 16.
	_LoRa.setDR(5);
};

String LoRa::send_receive(String msg){
    int n;
    String answer;
	if(msg.length()>3){
		sscanf(msg.c_str(),"%d", &n);
		unsigned char ta[2];
		ta[0] = (unsigned char)(n>>8);
		ta[1] = (unsigned char)n;
		_LoRa.txBytes(&ta[0], 2);
		answer = _LoRa.getRx();
        return answer;
	}
    else{
		
        return answer;
    }
};



