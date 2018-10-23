#include "Arduino.h"
#include "Stream.h"
#include "rn2xx3.h"
#include "LoRa_config.h"
#include <stdio.h>
#define LoRa Serial1
#define UART SerialUSB
#define ATMEGA Serial


String sendRawCommand(Stream& _serial, String command){
    delay(100);
    while(_serial.available()){};
    _serial.read();
    _serial.println(command);
    String ret = _serial.readStringUntil('\n');
    ret.trim();
    //TODO: Add debug print
    return ret;
}

String receiveRawCommand(Stream& _serial){
    _serial.read();
    String ret = _serial.readStringUntil('\n');
    ret.trim();
    return ret;
}


void setup() {
    UART.begin(57600);
    LoRa.begin(57600);
    ATMEGA.begin(57600);
    LoRa.flush();
    UART.flush();
    ATMEGA.flush();
 
}

void loop() {
    rn2xx3 lorawan(LoRa);
    bool joined = false;
	joined = lorawan.initOTAA(appEui, appKey);
    // Set data-rate to SF7/125kHz. See. Lorawan regional paramaeters p. 16.
    lorawan.setDR(5);
    while(joined){
        String msg = receiveRawCommand(ATMEGA);
        int n;
        if(msg.length()>3){
            sscanf(msg.c_str(),"%d", &n);
            unsigned char ta[2];
            ta[0] = (unsigned char)(n>>8);
            ta[1] = (unsigned char)n;
            lorawan.txBytes(&ta[0], 2);
            }
        }



   

    



    /*
    String answer;
    String command;
    command = receiveRawCommand(ATMEGA);
        if(command.length() > 3){
            UART.print(command);
            UART.write('\n');
            if (command == "mac join otaa"){
                String rec = sendRawCommand(LoRa, command);
                answer = LoRa.readStringUntil('\n');
                UART.print(rec);
                UART.print(answer);
            }
            else{
                answer = sendRawCommand(LoRa, command);
            }
            ATMEGA.print(answer);
            ATMEGA.write('\n');
            UART.print(answer);
            UART.write('\n');
    }
    */
}




// First try, before porting Arduiono code to the atmega.
/*
#define LF (uint8_t)10
#define CR (uint8_t)13




void WriteCommand(Stream& serial, const char *command){
        delay(100);
        writestring(serial, (unsigned char*)*command);
};

void writestring(Stream& serial, unsigned char *string){
    for(; *string; ++string){
    serial.write(*string);
    }
    serial.write('\n');
};



unsigned char* readstring(Stream& serial){
    unsigned char string[150];
	unsigned char byte;
	 uint8_t i = 0;
	 /*receive bytes and put them in a string:
	 while( (byte = serial.read()) >= LF ){
        if(byte==LF || byte == CR){
            break;[]
		}
		/* Merge the bytes together to a string: 
        string[i++] = byte;
        //UART.print(byte);
    };
    /* insert NULL to terminate the string 
    //string[i] = '\0';
    return string;
}

    //String answer = sendRawCommand(LoRa, command);
    //delay(100);
    //UART.print(fish);
    //command = readstring(UART);
    //writestring(ATMEGA, command);
    /*
    //send and receive data with serial
     if (UART.available()){
        command = readstring(UART);
        msg = readstring(LoRa);
        writestring(LoRa, command);
        msg = readstring(LoRa);

        };
    
    delay(10);
        //writestring(ATMEGA, command);
        //const char *msg = "sys get ver";
    /*
    if(LoRa.available()){
        //UART.print("jizess");
        //delay(200);
        msg = readstring(LoRa);
        writestring(ATMEGA, msg);
        };
    

    /*
    if (LoRa.available()){
        //debugSerial.print("RECEIVE: ");
        unsigned char* answer = readstring(LoRa);
        writestring(UART, answer);
    }
    */   
