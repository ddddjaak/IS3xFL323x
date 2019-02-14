// Include the FxLED library
#include "FxLED.h"

// Create an instance of an IS31FL3236A controller called FxLED
FL3236A FxLED;

FxRGB leds {
/* RGB LED format:
  {R,  G,  B} */
  {2,  1,  3},  // D40
  {5,  4,  6},  // D41
  {8,  7,  9},  // D42
  {11, 10, 12}, // D43
  {14, 13, 15}, // D44
  {17, 16, 18}, // D45
  {20, 19, 21}, // D46
  {23, 22, 24}, // D47
  {26, 25, 27}, // D48
  {29, 28, 30}, // D49
  {32, 31, 33}, // D50
  {35, 34, 36}  // D51
};

#define NUM_LEDS sizeof(leds)/sizeof(leds[0])

void setup() {
  FxLED.begin(); // Initialize
  FxLED.setPWMFrequency(FREQ_22KHZ);
}

void loop() {
//  // Display red, green, then blue on all LEDs one at a time
//  for(uint8_t i=0; i<NUM_LEDS; i++) {
//    leds[i] = RGB::Red;
//    FxLED.update(leds);
//    delay(50); // Delay 50ms
//  }
//  for(uint8_t i=0; i<NUM_LEDS; i++) {
//    leds[i] = RGB::Green;
//    FxLED.update(leds);
//    delay(50); // Delay 50ms
//  }
//  for(uint8_t i=0; i<NUM_LEDS; i++) {
//    leds[i] = RGB::Blue;
//    FxLED.update(leds);
//    delay(50); // Delay 50ms
//  }

//  // Display a random color on all LEDs one at a time
//  uint8_t redValue = random(0, 256);
//  uint8_t greenValue = random(0, 256);
//  uint8_t blueValue = random(0, 256);
//  for(uint8_t i=0; i<NUM_LEDS; i++) {
////    leds[0].r(redValue);
////    leds[i].pixel.g = greenValue;
////    leds[i].pixel.b = blueValue;
////    leds[i].setRGB(redValue, greenValue, blueValue);
//    leds[i] = RGB(redValue, greenValue, blueValue);
//    FxLED.update(leds);
//    delay(25); // Delay 25ms
//  }

  // Copy LED values, middle out
  uint8_t redValue = random(0, 256);
  uint8_t greenValue = random(0, 256);
  uint8_t blueValue = random(0, 256);
  leds[5] = RGB(redValue, greenValue, blueValue);
  leds[6] = leds[5];
  FxLED.update(leds);
  delay(50); // Delay 50ms
  for(uint8_t i=1; i<NUM_LEDS/2; i++) {
    leds[5-i] = leds[5];
    leds[6+i] = leds[5];
    FxLED.update(leds);
    delay(50); // Delay 50ms
  }
}