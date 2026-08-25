#include <Adafruit_NeoPixel.h>

// Most ESP32-S3 boards link the built-in RGB LED to GPIO 38 or GPIO 48
#define RGB_PIN        38  
#define NUM_PIXELS      1  // There is only 1 onboard RGB LED

Adafruit_NeoPixel statusLED(NUM_PIXELS, RGB_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  statusLED.begin(); // Initialize the RGB chip
  statusLED.show();  // Turn off any leftover color pixels from boot
}

void loop() {
  // Set the LED to a solid Blue light (Red=0, Green=0, Blue=150)
  statusLED.setPixelColor(0, statusLED.Color(0, 0, 150));
  statusLED.show(); 
  delay(1000);
}
