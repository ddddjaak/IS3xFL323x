/*
  IS3xFL323x.h - Library for interfacing with the ISSI IS3xFL323x Family of FxLED Drivers
  http://ams.issi.com/US/product-analog-fxled-driver.shtml
  Created by stephen.harper@noctivore.com
*/
 
// Prevent weirdness from including header more than once
#ifndef __IS3XFL323D_H
#define __IS3XFL323X_H
 
// Include I2C implementation header
#include "platform/avr/ArduinoI2C.h"

#include "chipsets.h"
#include "structures.h"
#include "gamma.h"
#include "sevenSeg.h"
 
// Define address and read commands
#define ADDRESS_REG         0x78
#define SHUTDOWN_REG        0x00
#define PWM_UPDATE_REG      0x25
#define GLOBAL_CONTORL_REG  0x4A
#define OUTPUT_FREQ_REG     0x4B
#define RESET_REG           0x4F

// Define frequency constants
#define FREQ_3KHZ  0
#define FREQ_22KHZ 1

// typedef uint8_t sevenSeg[4][8];

// Class IS3xFL323x
class IS3xFL323x
{
  public:
    IS3xFL323x(); // Constructor
    void begin();
    void reset();
    void shutdown(bool enable=true);
    void setFrequency(uint8_t frequency=FREQ_22KHZ);
    void update();
    void update(FxRGB leds);
    void on(uint8_t channel);
    void off(uint8_t channel);
    // void setColor(FxRGB leds, uint8_t led, );
    void setPWM(uint8_t channel, uint8_t value=0xFF, double delay=0);
    void clearAll();
    void fadeAll(double delay=20);
    void displayDigit(FxSevenSeg digits, uint8_t digit, char value, bool flip=false);
    void displayTime(FxSevenSeg digits, int hour, int minute, uint8_t format=DEC, bool flip=false, bool leadingZero=true);
  private:
    static I2CInterface* pI2CInterface; // Pointer to the I2CInterface implementation
    uint8_t sendCommand(uint8_t Reg_Add, uint8_t Reg_Dat); // Sends the I2C command to read data
    void twoDigitDisplay(FxSevenSeg digits, bool isRightmostDigits, int value, uint8_t format=DEC, bool flip=false, bool leadingZero=true);
};
 
#endif
// End of __IS3XFL323D_H