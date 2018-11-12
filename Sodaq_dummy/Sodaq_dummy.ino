#include "Arduino.h"
#include "Stream.h"
#include "rn2xx3.h"
#include <stdio.h>
#define LoRa Serial1
#define UART SerialUSB
#define ATMEGA Serial
#define red_led 14
#define green_led 15
#define blue_led 16
#define GPS 18
#define BUTTON 19


static rn2xx3 lorawan(LoRa);
unsigned long time;

void setup() {
    UART.begin(57600);
    LoRa.begin(57600);
    ATMEGA.begin(57600);
    LoRa.flush();
    UART.flush();
    ATMEGA.flush();
    // Set user button as INPUT:
    pinMode(19, INPUT);
    // Enable LED'S:
    pinMode(red_led, OUTPUT);
    pinMode(green_led, OUTPUT);
    pinMode(blue_led, OUTPUT);
    // Enable GPS:
    pinMode(GPS, OUTPUT);

    const char *appeui = "70B3D57ED0013824";
    const char *appkey = "0222B8B8AE6A77BE0C040ABF13B8E8E7";
    digitalWrite(red_led, HIGH);
    //digitalWrite(green_led, HIGH);
    //digitalWrite(blue_led, HIGH);
    bool joined = false;
	joined = lorawan.initOTAA(appeui, appkey);
    // Set data-rate to SF7/125kHz. See. Lorawan regional paramaeters p. 16.
    lorawan.setDR(5);
    UART.print("Initialized");
    
};

void loop() {
    byte end = 0b00000010;
    if((millis()-time) > 15000 || digitalRead(BUTTON) == LOW){
        digitalWrite(red_led, LOW);
        digitalWrite(blue_led, HIGH);
        for(int i = 0; i<5; i++){
            lorawan.setDR(i);
            lorawan.txBytes(&end, 1);
            delay(1000);
            time = millis();
        }
        digitalWrite(blue_led, LOW);
        digitalWrite(red_led, HIGH);
    };
}

