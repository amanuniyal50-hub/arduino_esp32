#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DHT.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDRESS 0x3C   // use YOUR confirmed address from Day 1

#define DHTPIN 4
#define DHTTYPE DHT11

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Wire.begin(8, 9); // your OLED's SDA, SCL pins from Day 1

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    Serial.println("OLED init failed");
    while (1);
  }

  dht.begin();
  display.clearDisplay();
}

void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);

  if (isnan(h) || isnan(t)) {
    display.println("Sensor read failed");
  } else {
    display.print("Temp: ");
    display.print(t);
    display.println(" Celcius");
    display.print("Humidity: ");
    display.print(h);
    display.println(" %");
  }

  display.display();
}