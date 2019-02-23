/*
  FxLED.h - Library for interfacing with the ISSI IS3xFL323x Family of FxLED Drivers
  http://ams.issi.com/US/product-analog-fxled-driver.shtml
  Created by stephen.harper@noctivore.com
*/
 
// Prevent weirdness from including header more than once
#ifndef __FXLED_H
#define __FXLED_H
 
#include "platform/config.h"

// #include "chipsets.h"
#include "structures.h"
#include "gamma.h"
 
// Define addresses
#define SHUTDOWN_REG          0x00
#ifdef FL3237
#define ADDRESS_REG           0x34
#define PWM_UPDATE_REG        0x25
#define LED_CONTROL_REG_START 0x4A
#define GLOBAL_CONTORL_REG    0x6E
#define RESET_REG             0x7F
#else
#define ADDRESS_REG           0x3C
#define PWM_UPDATE_REG        0x25
#define LED_CONTROL_REG_START 0x26
#define GLOBAL_CONTORL_REG    0x4A
#define RESET_REG             0x4F
#endif
#define OUTPUT_FREQ_REG       0x4B

// Define frequency constants
#define FREQ_3KHZ  0
#define FREQ_22KHZ 1

class IS3xFL323x
{
  public:
    IS3xFL323x(); // Constructor
    void begin(uint8_t AD=0x00);
    void reset();
    void shutdown(bool enable=true);
    void update();
    void update(FxRGB leds);
    void on(uint8_t channel);
    void off(uint8_t channel);
    void setPWM(uint8_t channel, uint8_t value=0xFF, double delay=0);
    void clear();
    void fadeAll(double delay=20);
    void displayDigit(FxSevenSegDisplay digits, uint8_t digit, char value, bool flip=false);
    void displayTime(FxSevenSegDisplay digits, int hour, int minute, uint8_t format=DEC, bool flip=false, bool leadingZero=true);
  protected:
    uint8_t sendCommand(uint8_t Reg_Add, uint8_t Reg_Dat);
    uint8_t sendCommandAuto(uint8_t Reg_Add_Start, uint8_t Reg_Add_Stop, uint8_t Reg_Dat);
    void twoDigitDisplay(FxSevenSegDisplay digits, bool isRightmostDigits, int value, uint8_t format=DEC, bool flip=false, bool leadingZero=true);
  private:
    static I2CInterface* pI2CInterface; // Pointer to the I2CInterface implementation
    uint8_t AD_BITS=0x00;
};

class FL3236 : public IS3xFL323x
{
  public:
    FL3236() : IS3xFL323x() {}
};

class FL3236A : public IS3xFL323x
{
  public:
    FL3236A() : IS3xFL323x() {}
    void setPWMFrequency(uint8_t frequency=FREQ_22KHZ);
};
 
#endif
// End of __FXLED_H