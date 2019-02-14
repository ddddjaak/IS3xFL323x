// Include the IS3xFL323x library
#include "FxLED.h"

// Create an instance of an IS31FL3236A controller called FxLED
FL3236A FxLED;

void setup() {
  FxLED.begin(); // Initialize
}

void loop() {
  for(uint8_t i=1; i<4; i++) {   // Iterate over each set of LEDS (GRB)
    for(uint8_t j=i; j<37; j+=3) // Iterate over each LED in the set
    {
      FxLED.setPWM(j, 0xFF, 0);
    }
    delay(500); // Delay 500ms
  }
  
  FxLED.fadeAll(); // Fade all LEDs to off using 64 gamma steps
  delay(500); // Delay 500ms
}