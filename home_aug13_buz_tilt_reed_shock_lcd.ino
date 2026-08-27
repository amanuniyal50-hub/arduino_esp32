#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int tiltPin = 2;
int shockPin = 3;
int reedPin = 4;
int buzzerPin = 8;
int led =9;


void setup() {
  pinMode(tiltPin, INPUT);
  pinMode(shockPin, INPUT);
  pinMode(reedPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  lcd.init();         
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("tilt,shock,reed");
  lcd.setCursor(0,1);
  lcd.print("for buzzer to beep");
  delay(2000);
}

void loop() {
  bool tilted = digitalRead(tiltPin) == LOW;
  bool shocked = digitalRead(shockPin) == LOW;
  bool doorOpen = digitalRead(reedPin) == LOW; // check: may need flipping per your board

  if (tilted || shocked || doorOpen) {
    tone(buzzerPin, 1000);
    digitalWrite(led,0);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("buzzer on !!!");
    lcd.setCursor(0,1);
    lcd.print("t");lcd.print(digitalRead(tiltPin));
    lcd.setCursor(3,1);
    lcd.print("s");lcd.print(digitalRead(shockPin));
    lcd.setCursor(6,1);
    lcd.print("r");lcd.print(digitalRead(reedPin));
  } else {
    noTone(buzzerPin);
    digitalWrite(led,1);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("buzzer off !!!");
    lcd.setCursor(0,1);
    lcd.print("t");lcd.print(digitalRead(tiltPin));
    lcd.setCursor(3,1);
    lcd.print("s");lcd.print(digitalRead(shockPin));
    lcd.setCursor(6,1);
    lcd.print("r");lcd.print(digitalRead(reedPin));
  }


  Serial.print("tilt:"); Serial.print(digitalRead(tiltPin));
  Serial.print(" shock:"); Serial.print(digitalRead(shockPin));
  Serial.print(" reed:"); Serial.println(digitalRead(reedPin));
  delay(500);

  lcd.clear();
  
  delay(100);
}