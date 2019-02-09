// Include the IS3xFL323x library
#include "IS3xFL323x.h"

// Create an instance of IS3xFL323x called FxLED
IS3xFL323x FxLED(FL3236A);

FxSevenSegDisplay digits {
/* Segment format:
  {A,  B,  C,  D,  E,  F,  G,  DP} */
  {1,  6,  7,  4,  3,  2,  5,  0},
  {11, 16, 17, 14, 13, 12, 15, 0},
  {20, 25, 26, 23, 22, 21, 24, 0},
  {30, 35, 36, 33, 32, 31, 34, 0}
};

void setup() {
  FxLED.begin(); // Initialize
}

void loop() {
  // Display the time in normal format
  FxLED.displayTime(digits, minutes(), seconds());
  FxLED.update();

  // Display the time in HEX format
  //FxLED.displayTime(digits, minutes(), seconds(), HEX);
  //FxLED.update();

  // Display the time in normal format, flipped
  //FxLED.displayTime(digits, minutes(), seconds(), DEC, true);
  //FxLED.update();

  // Display the time in HEX format with no leading zeros
  //FxLED.displayTime(digits, minutes(), seconds(), HEX, false, false);
  //FxLED.update();

  delay(1000);
}

unsigned long minutes() {
  unsigned long minutes = (millis()/60000)%60;
  return minutes;
}

unsigned long seconds() {
  unsigned long seconds = (millis()/1000)%60;
  return seconds;
}