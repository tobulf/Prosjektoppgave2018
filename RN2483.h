
/**
 * @file RN2483.h
 * @author Tobias U. Rasmussen (tobulf@gmail.com)
 * @brief A simple driver for the RN2483 chip.
 * @date 2019-03-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */


#ifndef RN2483_H_
#define RN2483_H_

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arduino/WString.h"



/**
 * @brief Communications class using UART. 
 * 
 */
class LoRa_COM{
	public:
	/**
	 * @brief Construct a new LoRa_COM object
	 * 
	 */
	LoRa_COM();
	/**
	 * @brief Returns the corresponding answer to a command. 
	 * 
	 * @return String 
	 */
	String get_answer(void);
	/**
	 * @brief Receives a single byte via UART.
	 * 
	 * @return unsigned char 
	 */
	unsigned char receive(void);
	/**
	 * @brief Transmit a single byte via UART.
	 * 
	 * @param uint8_t data 
	 */
	void transmit(uint8_t data);
	/**
	 * @brief Send a command via UART.
	 * 
	 * @param String command 
	 */
	void send_command(String command);
	private:
};

/**
 * @brief Driver Class for the RN2483, functionality for LoRa class A.
 * 
 */

class RN2483: public LoRa_COM {
	public:
	/**
	 * @brief Construct a new RN2483 object
	 * 
	 */
	RN2483();
	/**
	 * @brief Get the HW-version of the RN2483 chip.
	 * 
	 * @return String 
	 */
	String get_version(void);
	/**
	 * @brief Initialize over the air activation according to LoRa Standards.
	 * 
	 * @param app_EUI 
	 * @param app_key 
	 * @return true 
	 * @return false 
	 */
	bool init_OTAA(String app_EUI, String app_key); 
	private:
};






#endif /* RN2483_H_ */