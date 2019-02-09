/*
  I2CInterface.h - A virtual class with required functions for NPA 201 communication
  Created by stephen.harper@noctivore.com
*/

// Prevent weirdness from including header more than once
#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

// Include headers
#include <stdint.h>

/**
 * This pure virtual class represents an I2C implementation.
 */
class I2CInterface {
public:
  /**
   * Begin a transmission to the I2C slave device with the given address
   *
   * @param address - The 7-bit address of the device to transmit to
   * @return none
   */
  virtual void beginTransmission(uint8_t address) = 0;

  /**
   * Ends a transmission to a slave device that was begun by beginTransmission() and transmits the bytes that were queued by write()
   *
   * @return byte indicating status of transmission:
   * 0:success
   * 1:data too long to fit in transmit buffer
   * 2:received NACK on transmit of address
   * 3:received NACK on transmit of data
   * 4:other error
   */
  virtual uint8_t endTransmission(void) = 0;

  /**
   * Determines if the I2C bus has bytes available to read
   *
   * @return the number of bytes available for reading
   */
  // virtual int available(void) = 0;

  /**
   * Reads a byte that was transmitted from a slave device to a master after a call to requestFrom()
   * or was transmitted from a master to a slave
   *
   * @return the next byte received
   */
  // virtual int read(void) = 0;

  /**
   * Writes data from a slave device in response to a request from a master,
   * or queues bytes for transmission from a master to slave device
   * (in-between calls to beginTransmission() and endTransmission())
   *
   * @param data - A value to send as a single byte
   * @return number of bytes written
   */
  virtual size_t write(uint8_t data) = 0;

  /**
   * Used by the master to request bytes from a slave device
   *
   * @param address - The 7-bit address of the device to request bytes from
   * @param quantity - The number of bytes to request
   * @return the number of bytes returned from the slave device
   */
  // virtual uint8_t requestFrom(uint8_t address, uint8_t quantity) = 0;

  /**
   * An implementation of delay
   *
   * @param milliseconds - The number of milliseconds to delay
   */
  // virtual void wait(uint16_t milliseconds) = 0;
};

#endif  // I2C_INTERFACE_H_