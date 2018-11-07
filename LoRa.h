/*
 * LoRa.h
 *
 * Created: 07.11.2018 15:53:58
 *  Author: tobiasu
 */ 


#ifndef LORA_H_
#define LORA_H_


#include "rn2xx3.h"
#include "LoRa_config.h"
#include "arduino/Arduino.h"
#include <stdbool.h>



class LoRa{

public:
    LoRa(Stream& serial);
    String send_receive(String msg);
    
private:
    Stream& _serial;
    rn2xx3 RN2483;
    bool connected;
};







#endif /* LORA_H_ */