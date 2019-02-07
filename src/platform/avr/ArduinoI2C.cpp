/*
  ArduinoI2C.cpp - Implements functions required by I2CInterface for NPA 201 communication
  Created by operator@noctivore.com
*/

// Include headers
#include <stdio.h>   /* Standard input/output definitions */
#include "ArduinoI2C.h"

/**
 * ArduinoI2C constructor
 * calls Wire.begin() with no arguments to join the I2C bus as a master
 */
ArduinoI2C::ArduinoI2C()
{
  Wire.begin();
}

/**
 * beginTransmission() begins a transmission to the I2C slave device with the given address
 */
void ArduinoI2C::beginTransmission(uint8_t address)
{
    Wire.beginTransmission(address);
}

/**
 * endTransmission() ends a transmission to a slave device that was begun by beginTransmission()
 * and transmits the bytes that were queued by write()
 */
uint8_t ArduinoI2C::endTransmission(void)
{
	return Wire.endTransmission();
}

/**
 * available() returns the number of bytes available for retrieval with read()
 */
int ArduinoI2C::available(void)
{
    return Wire.available();
}

/**
 * read() reads a byte that was transmitted from a slave device to a master after a call to requestFrom()
 * or was transmitted from a master to a slave
 */
int ArduinoI2C::read(void)
{
    return Wire.read();
}

/**
 * write() writes data from a slave device in response to a request from a master,
 * or queues bytes for transmission from a master to slave device
 * (in-between calls to beginTransmission() and endTransmission())
 */
size_t ArduinoI2C::write(uint8_t data)
{
    return Wire.write(data);
}

/**
 * requestFrom() is used by the I2C master to request bytes from a slave device
 * The bytes may then be retrieved with the available() and read() functions
 */
uint8_t ArduinoI2C::requestFrom(uint8_t address, uint8_t quantity)
{
    return Wire.requestFrom(address, quantity);
}

/**
 * wait() waits the specified number of milliseconds
 */
void ArduinoI2C::wait(uint16_t milliseconds)
{
  // _delay_ms calls __builtin_avr_delay_cycles wich expects a compile time integer constant
  // To get around this a for() loop is used to call a constant 1ms delay
  for(uint16_t i = 0; i < milliseconds; i++)
  {
    _delay_ms(1);
  }
}