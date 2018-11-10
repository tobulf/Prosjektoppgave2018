/*
 * LoRa.h
 *
 * Created: 07.11.2018 15:53:58
 *  Author: tobiasu
 */ 


#ifndef LORA_H_
#define LORA_H_


#include "rn2xx3.h"
#include "arduino/Arduino.h"
#include <stdbool.h>




String LoRa_send_receive(rn2xx3& RN2483,String msg);

bool LoRa_init(rn2xx3& RN2483, const char* Eui, const char* Key);



#endif /* LORA_H_ */