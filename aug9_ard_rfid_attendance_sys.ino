#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN  10
#define RST_PIN 7

MFRC522 rfid(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte validCards[][4] = { // authorized rfid card tags 
  {0xA3, 0xB2, 0x8C, 0xFA},
  {0x73, 0x9D, 0x78, 0xFA}
};
int totalValidCards = sizeof(validCards) / sizeof(validCards[0]);

void setup() {
  Serial.begin(9600);

  SPI.begin();
  rfid.PCD_Init();

  lcd.init();         
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Scan RFID Card");

  Serial.println(" RFID ATTENDANCE SYSTEM ");
  Serial.println("System Ready - Scan RFID Card");

}

void loop() {
  // Wait for RFID card
  if (!rfid.PICC_IsNewCardPresent())
    return;

  if (!rfid.PICC_ReadCardSerial())
    return;

  // Show scanned UID
  Serial.print("\nCard UID : ");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("UID:");
  lcd.setCursor(0, 1);

  for (byte i = 0; i < rfid.uid.size; i++) {
    if (rfid.uid.uidByte[i] < 0x10) {
      Serial.print("0");
      lcd.print("0");
    }
    Serial.print(rfid.uid.uidByte[i], HEX);
    lcd.print(rfid.uid.uidByte[i], HEX);
    Serial.print(" ");
    lcd.print(" ");
  }
  Serial.println();

  //  Validate card
  if (isValidCard(rfid.uid.uidByte)) {

    Serial.println("RESULT   : VALID CARD");
    Serial.print("VALID UID: ");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("VALID CARD");
    lcd.setCursor(0, 1);

    for (byte i = 0; i < rfid.uid.size; i++) {
      if (rfid.uid.uidByte[i] < 0x10) {
        Serial.print("0");
        lcd.print("0");
      }
      Serial.print(rfid.uid.uidByte[i], HEX);
      lcd.print(rfid.uid.uidByte[i], HEX);
      Serial.print(" ");
      lcd.print(" ");
    }
    Serial.println();

  } else {

    Serial.println("RESULT   : INVALID CARD");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("INVALID CARD    ");
  }

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();

  delay(3000);

  //  Reset display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scan RFID Card");

  Serial.println("Waiting for Next Card...");
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
