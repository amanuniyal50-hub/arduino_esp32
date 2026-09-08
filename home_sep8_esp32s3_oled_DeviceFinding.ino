#include <Wire.h>

void setup() {
  Wire.begin(8, 9); // replace 8, 9 with your actual SDA, SCL pins
  Serial.begin(115200);
  delay(1000);
  Serial.println("Scanning...");
}

void loop() {
  byte count = 0;
  for (byte i = 1; i < 127; i++) {
    Wire.beginTransmission(i);
    if (Wire.endTransmission() == 0) {
      Serial.print("Found device at 0x");
      Serial.println(i, HEX);
      count++;
    }
  }
  if (count == 0) Serial.println("No I2C devices found");
  delay(3000);
}