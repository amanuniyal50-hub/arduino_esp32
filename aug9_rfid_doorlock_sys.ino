#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define SS_PIN  10
#define RST_PIN 7
int ledr =8; //red
int ledg =4; //green
Servo s;


MFRC522 rfid(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

//alreadt authorized rfid card address 
byte validCards[][4] = { 
  {0xA3, 0xB2, 0x8C, 0xFA},
  {0x73, 0x9D, 0x78, 0xFA}
};
int totalValidCards = sizeof(validCards) / sizeof(validCards[0]);

void setup() {
  Serial.begin(9600);
  s.attach(9);
  pinMode(ledr,OUTPUT);
  pinMode(ledg,OUTPUT);

  SPI.begin();
  rfid.PCD_Init();

  lcd.init();         
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Scan your key!");
  digitalWrite(ledr,1);
    digitalWrite(ledg,0);

  Serial.println("home locked");
  Serial.println("scan your keycard");

}

void loop() {
  // Wait for RFID card
  if (!rfid.PICC_IsNewCardPresent())
    return;

  if (!rfid.PICC_ReadCardSerial())
    return;

  // Show scanned UID
  Serial.print("\nCard UID : ");
  for (byte i = 0; i < rfid.uid.size; i++) {
    if (rfid.uid.uidByte[i] < 0x10) {
      Serial.print("0");
    }
    Serial.print(rfid.uid.uidByte[i], HEX);
    lcd.print(rfid.uid.uidByte[i], HEX);
    Serial.print(" ");
  }
   Serial.println();

  //validate card  
   if (isValidCard(rfid.uid.uidByte)) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("door unclocked");
    Serial.println("Correct key");
    lcd.setCursor(0,1);
    lcd.print("WELCOME HOME!!");
    digitalWrite(ledr,0);
    digitalWrite(ledg,1);
    s.write(90);
   }
   else {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Incorrect key");
    lcd.setCursor(0,1);
    lcd.print("Access denied!!");
    digitalWrite(ledr,1);
    digitalWrite(ledg,0);
    s.write(0);
   }
   rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
  delay (2000);

  //reset system
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("home locked");
  lcd.setCursor(1,0);
  lcd.print("scan your key");
  digitalWrite(ledr,1);
    digitalWrite(ledg,0);
    s.write(0);

}
// card validation function
bool isValidCard(byte *uid) {

  for (int i = 0; i < totalValidCards; i++) {

    bool match = true;

    for (int j = 0; j < 4; j++) {
      if (uid[j] != validCards[i][j]) {
        match = false;
        break;
      }
    }

    if (match)
      return true;
  }

  return false;

}
