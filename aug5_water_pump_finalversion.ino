#define BLYNK_PRINT Serial 
#define BLYNK_TEMPLATE_ID "TMPL3wblZpJOd" 
#define BLYNK_TEMPLATE_NAME "water irrigation" 
#define BLYNK_AUTH_TOKEN "8GIdny_ooXqJKgp_Ib0rQtc5rODMde_Q" 

#include <Wire.h> 
#include <WiFi.h> 
#include <BlynkSimpleEsp32.h>  
#include <LiquidCrystal_I2C.h> 

LiquidCrystal_I2C lcd(0x27, 16, 2); 
BlynkTimer timer; 

const char* ssid = "Airtel_CLYXN X SORXN"; 
const char* pass = "Studio@1234"; 
const char* auth = "8GIdny_ooXqJKgp_Ib0rQtc5rODMde_Q"; 

#define virtualpin1 V0 
#define virtualpin2 V1 
#define virtualpin3 V2 // green
#define virtualpin4 V3 //red
#define moisture 34 

int motor = 13; 
int led1 = 5;  // Red LED
int led2 = 4;  // Green LED
bool manual = false; 
int moisturevalue = 0; 


void updateDisplay(const char* motorStatus) {
  lcd.clear(); 
  lcd.setCursor(0, 0); 
  lcd.print("Moisture: "); 
  lcd.print(moisturevalue); 
  lcd.setCursor(0, 1); 
  lcd.print(motorStatus); 
}

BLYNK_WRITE(V1) { 
  int value = param.asInt(); 
  if (value == 1) { 
    manual = true; 
    digitalWrite(led2, 1); 
    digitalWrite(led1, 0); 
    digitalWrite(motor, 0); 
    updateDisplay("Motor ON (M)");
    Blynk.virtualWrite(virtualpin3, 1); 
    Blynk.virtualWrite(virtualpin4, 0); 
  } else { 
    manual = false; 
    digitalWrite(led1, 1); 
    digitalWrite(led2, 0); 
    digitalWrite(motor, 1); 
    updateDisplay("Motor OFF (A)");
    Blynk.virtualWrite(virtualpin3, 0); 
    Blynk.virtualWrite(virtualpin4, 1); 
  } 
} 


void checkSystem() {
  moisturevalue = analogRead(moisture); 
  Serial.print("Moisture Value: ");
  Serial.println(moisturevalue); 
  
  Blynk.virtualWrite(virtualpin1, moisturevalue); 
  
  if (manual == false) { 
    if (moisturevalue < 3000) { 
      digitalWrite(led1, 1); 
      digitalWrite(led2, 0); 
      digitalWrite(motor, 0); 
      updateDisplay("Motor on"); 
      Blynk.virtualWrite(virtualpin3, 1); 
    Blynk.virtualWrite(virtualpin4, 0); 
    } else { 
      digitalWrite(led2, 1); 
      digitalWrite(led1, 0); 
      digitalWrite(motor, 1); 
      updateDisplay("Motor off"); 
      Blynk.virtualWrite(virtualpin3, 0); 
    Blynk.virtualWrite(virtualpin4, 1); 
    } 
  } 
}

void setup() { 
  Serial.begin(115200); 
  
  lcd.init(); 
  lcd.backlight(); 
  lcd.clear(); 
  lcd.setCursor(0, 0); 
  lcd.print("Connecting WiFi..."); 

  Blynk.begin(auth, ssid, pass); 

  pinMode(motor, OUTPUT); 
  pinMode(moisture, INPUT); 
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT); 

  lcd.clear();
  lcd.print("Irrigation Ready"); 
  delay(2000); 

  
  timer.setInterval(1500L, checkSystem); 
} 

void loop() { 
  Blynk.run(); 
  timer.run(); 
}
