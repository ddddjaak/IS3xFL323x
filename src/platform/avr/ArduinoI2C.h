/*
  ArduinoI2C.h - Extends I2CInterface class which contains required functions for NPA 201 communication
  Created by operator@noctivore.com
*/

// Prevent weirdness from including header more than once
#ifndef ARDUINO_I2C_H
#define ARDUINO_I2C_H

// Include headers
// The Arduino wire library is used for I2C communication
#include <Wire.h>
#include <stdint.h>
#include <util/delay.h>
#include "Arduino.h"
#include "I2CInterface.h"

/**
 * ArduinoI2C is an implementation of I2CInterface for Arduino
 */
class ArduinoI2C : public I2CInterface {
public:
	/**
	 * ArduinoI2C() constructor
	 */
	ArduinoI2C();

	/**
	 * beginTransmission() begins a transmission to the I2C slave device with the given address
	 */
	void beginTransmission(uint8_t address);

	/**
	 * endTransmission() ends a transmission to a slave device that was begun by beginTransmission()
	 * and transmits the bytes that were queued by write()
	 */
	uint8_t endTransmission(void);
	
	/**
	 * available() returns the number of bytes available for retrieval with read()
	 */
	int available(void);
	
	/**
	 * read() reads a byte that was transmitted from a slave device to a master after a call to requestFrom()
	 * or was transmitted from a master to a slave
	 */
	int read(void);

	/**
	 * write() writes data from a slave device in response to a request from a master,
	 * or queues bytes for transmission from a master to slave device
	 * (in-between calls to beginTransmission() and endTransmission())
	 */
	size_t write(uint8_t data);

	/**
	 * requestFrom() is used by the I2C master to request bytes from a slave device
	 * The bytes may then be retrieved with the available() and read() functions
	 */
	uint8_t requestFrom(uint8_t address, uint8_t quantity);

	/**
	 * wait() waits the specified number of milliseconds
	 */
	void wait(uint16_t milliseconds);
};

#endif // ARDUINO_I2C