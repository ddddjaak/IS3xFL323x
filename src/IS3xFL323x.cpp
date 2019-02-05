/*
  IS3xFL323x.cpp - Library for interfacing with the ISSI IS3xFL323x Family of FxLED Drivers
  http://ams.issi.com/US/product-analog-fxled-driver.shtml
  Created by stephen.harper@noctivore.com
*/
 
// Include headers
#include "IS3xFL323x.h"

ArduinoI2C i2c;
I2CInterface* IS3xFL323x::pI2CInterface = &i2c;
// uint8_t IS3xFL323x::NPADATA[5] = { };
 
// Constructor
IS3xFL323x::IS3xFL323x()
{

}

void IS3xFL323x::begin()
{
  for(uint8_t i=0x26;i<=0x49;i++)
  {
    sendCommand(i,0xff); // Enable all LED Control Registers
  }
  for(uint8_t i=0x01;i<=0x24;i++)
  {
    sendCommand(i,0x00); // Set all PWM Registers to 0x00
  }

  sendCommand(PWM_UPDATE_REG,0x00); // Write PWM Update Registers
  sendCommand(OUTPUT_FREQ_REG,0x01); // Set frequency to 22KHz
  sendCommand(SHUTDOWN_REG,0x01); // Normal operation
}

// Reset device and all registers to default values
void IS3xFL323x::reset() {
  sendCommand(RESET_REG,0x00); // Write Reset Register
}

// Software shutdown enable
void IS3xFL323x::shutdown(bool enable) {
  sendCommand(SHUTDOWN_REG,(enable) ? (0x00) : (0x01));
}

// Set the frequency of PWM output
void IS3xFL323x::setFrequency(uint8_t frequency) {
  if(frequency == FREQ_3KHZ || frequency == FREQ_22KHZ) {
    sendCommand(OUTPUT_FREQ_REG, frequency); // Set frequency
  }
}

// Update the PWM Control registers
void IS3xFL323x::update() {
  sendCommand(PWM_UPDATE_REG,0x00);//update PWM & control registers
}

// Turn on a specific channel, full brightness
void IS3xFL323x::on(uint8_t channel) {
  sendCommand(channel+0x25,0xff); // Enable channel
  setPWM(channel);
}

// Turn off a specific channel
void IS3xFL323x::off(uint8_t channel) {
  sendCommand(channel+0x25,0x00); // Disable channel
}

// Set Channel PWM Frequency
void IS3xFL323x::setPWM(uint8_t channel, uint8_t value, double delay) {
  sendCommand(channel,value);//set PWM
  _delay_ms(delay);
}

// Clear all channels
void IS3xFL323x::clearAll() {
  for(uint8_t i=0x01;i<=0x24;i++)
  {
    sendCommand(i,0x00); // Set all PWM Registers to 0x00
  }
}

// Fade all LEDs off
void IS3xFL323x::fadeAll(double delay) {
  for (int8_t i=63; i>=0; i--)//all LED breath falling
  {
    for(uint8_t j=1; j<37; j++)
    {
      sendCommand(j, pgm_read_byte(&PWM_Gamma64[i]));//set all PWM
    }
    update();
    _delay_ms(delay);
  }
}

// Display a digit on a seven segment display
void IS3xFL323x::displayDigit(uint8_t digits[][8], uint8_t digit, char value, bool flip) {
  uint8_t segment;
  uint8_t flipped[8] = {3, 4, 5, 0, 1, 2, 6, 7};

  for(uint8_t i=0; i<8; i++)
  {
    // Handle rearranging of segments to flip display
    if(flip)
    {
      segment = digits[digit][flipped[i]];
    }
    else
    {
      segment = digits[digit][i];
    }
    
    // If corresponding bit of value is 1 and segment is not disabled (0)
    if(((value >> i) & 1) && (segment != 0))
    {
      sendCommand(segment+0x25,0xff); // Enable channel
      setPWM(segment, 0x3F, 0);
    }
    else if(segment != 0)
    {
      sendCommand(segment+0x25,0x00); // Disable channel
    }
  }
}

// Display the time on a 4-digit seven segment display
void IS3xFL323x::displayTime(uint8_t digits[][8], int hour, int minute, uint8_t format, bool flip, bool leadingZero) {
  if(hour>(format-1))
  {
    displayDigit(digits, (flip) ? (3) : (0), sevenSegCharMap[hour/format], flip);
    displayDigit(digits, (flip) ? (2) : (1), sevenSegCharMap[hour%format], flip);
  } else
  {
    if (leadingZero)
    {
      displayDigit(digits, (flip) ? (3) : (0), sevenSegCharMap[0], flip);
    }
    displayDigit(digits, (flip) ? (2) : (1), sevenSegCharMap[hour], flip);
  }

  if(minute>(format-1))
  {
    displayDigit(digits, (flip) ? (1) : (2), sevenSegCharMap[minute/format], flip);
    displayDigit(digits, (flip) ? (0) : (3), sevenSegCharMap[minute%format], flip);
  }
  else
  {
    if (leadingZero)
    {
      displayDigit(digits, (flip) ? (1) : (2), sevenSegCharMap[0], flip);
    }
    displayDigit(digits, (flip) ? (0) : (3), sevenSegCharMap[minute], flip);
  }
}
 
// Sends the I2C command to read data
// Returns the status of the transmission
uint8_t IS3xFL323x::sendCommand(uint8_t Reg_Add, uint8_t Reg_Dat)
{
  // Begin transmission
  // The NPA 201 slave address is 0x27(HEX)
  // This address can be changed if required as per AAS-910-290
  pI2CInterface->beginTransmission(ADDRESS_REG/2);
  // Send the command read full measurement data
  // 0xAC(HEX) is the command byte to read data
  // It is the only command supported by the NPA 201
  pI2CInterface->write(Reg_Add);
  pI2CInterface->write(Reg_Dat);
  // End the transmission (stop transmitting)
  // return the status of the transmission
  // 0:success
  // 1:data too long to fit in transmit buffer
  // 2:received NACK on transmit of address
  // 3:received NACK on transmit of data
  // 4:other error
  return pI2CInterface->endTransmission();
}