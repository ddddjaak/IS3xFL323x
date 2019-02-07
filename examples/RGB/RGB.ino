// Include the IS3xFL323x library
#include "IS3xFL323x.h"

// Create an instance of IS3xFL323x called FxLED
IS3xFL323x FxLED;

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
//  {2,  1,  3,0,0,0},  // D40
//  {5,  4,  6,0,0,0},  // D41
//  {8,  7,  9,0,0,0},  // D42
//  {11, 10, 12,0,0,0}, // D43
//  {14, 13, 15,0,0,0}, // D44
//  {17, 16, 18,0,0,0}, // D45
//  {20, 19, 21,0,0,0}, // D46
//  {23, 22, 24,0,0,0}, // D47
//  {26, 25, 27,0,0,0}, // D48
//  {29, 28, 30,0,0,0}, // D49
//  {32, 31, 33,0,0,0}, // D50
//  {35, 34, 36,0,0,0}  // D51
};

#define NUM_LEDS sizeof(leds)/sizeof(leds[0])

void setup() {
  FxLED.begin(); // Initialize
}

void loop() {
//  // Iterate over each set of LEDS (RGB)
//  for(uint8_t i=0; i<NUM_LEDS; i++) {
//    leds[i] = RGB::Red;
//    FxLED.update(leds);
//    delay(200); // Delay 200ms
//  }
//  for(uint8_t i=0; i<NUM_LEDS; i++) {
//    leds[i] = RGB::Green;
//    FxLED.update(leds);
//    delay(200); // Delay 200ms
//  }
//  for(uint8_t i=0; i<NUM_LEDS; i++) {
//    leds[i] = RGB::Blue;
//    FxLED.update(leds);
//    delay(200); // Delay 200ms
//  }

  for(int j=0; j<64; j++) {
    for(uint8_t i=0; i<NUM_LEDS; i++) {
      leds[i].red = pgm_read_byte(&PWM_Gamma64[j]);
      leds[i].green = pgm_read_byte(&PWM_Gamma64[j]);
      leds[i].blue = pgm_read_byte(&PWM_Gamma64[j]);
      FxLED.update(leds);
    }
  }
  for(int k=63; k>=0; k--) {
    for(uint8_t i=0; i<NUM_LEDS; i++) {
      leds[i].red = pgm_read_byte(&PWM_Gamma64[k]);
      leds[i].green = pgm_read_byte(&PWM_Gamma64[k]);
      leds[i].blue = pgm_read_byte(&PWM_Gamma64[k]);
      FxLED.update(leds);
    }
  }
}