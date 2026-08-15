#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Define the custom pins
#define I2C_SDA 14
#define I2C_SCL 12

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Wire.begin(I2C_SDA, I2C_SCL); // have to initialize the new custom pins
  
  lcd.init();                     
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Custom Pins!");
}

void loop() {
}
