/*
 * LoRa.cpp
 *
 * Created: 07.11.2018 15:53:41
 *  Author: tobiasu
 */ 


#include "LoRa.h"


/*Define Stream for LoRa comms*/



LoRa::LoRa(Stream& serial){
    _serial(serial)
    _serial.begin(57600);
	_serial.flush();
    RN2483(serial);
	connected = false;
	connected = RN2483.initOTAA(appEui, appKey);
	// Set data-rate to SF7/125kHz. See. Lorawan regional paramaeters p. 16.
	RN2483.setDR(5);
};

String LoRa::send_receive(String msg){
    int n;
    String answer;
	if(msg.length()>3){
		sscanf(msg.c_str(),"%d", &n);
		unsigned char ta[2];
		ta[0] = (unsigned char)(n>>8);
		ta[1] = (unsigned char)n;
		lorawan.txBytes(&ta[0], 2);
		answer = lorawan.getRx();
        return answer;
	}
    else{
        return answer;
    }
};



