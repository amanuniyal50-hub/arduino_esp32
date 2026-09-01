#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <LiquidCrystal_I2C.h>

Adafruit_MPU6050 mpu;
LiquidCrystal_I2C lcd(0x27, 16, 2);
int buzzerPin = 8;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.begin();
  lcd.init();
  lcd.backlight();
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  float pitch = atan2(a.acceleration.y, a.acceleration.z) * 180 / PI;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pitch: "); lcd.print(pitch);
  lcd.setCursor(0, 1);

  if (abs(pitch) > 30) {
    lcd.print("TILT ALERT!");
    tone(buzzerPin, 1000);
  } else {
    lcd.print("Stable");
    noTone(buzzerPin);
  }

  delay(200);
}
