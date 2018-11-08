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
    LoRa(rn2xx3& com);
    String send_receive(String msg);
    
private:
    rn2xx3& _LoRa;
    bool connected;
};







#endif /* LORA_H_ */