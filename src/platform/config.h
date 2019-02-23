
#define USE_AVR

#ifdef USE_AVR
// Include I2C implementation header
#include "platform/avr/ArduinoI2C.h"
#ifndef USE_PROGMEM
#define USE_PROGMEM
#endif
#endif

#ifdef USE_STM32
// Include I2C implementation header
// #include "platform/stm32/STM32I2C.h"
#endif