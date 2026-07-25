#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int led =13;
int pir = 12;

void setup() {
  lcd.init(); // init= initialisation of lcd 
  lcd.backlight(); // to turn the backlight 
pinMode(led, OUTPUT);
pinMode (pir , INPUT );
Serial.begin (9600);
}

void loop() {
pir = digitalRead (12);
if (pir ==  1)
{
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print(" on ");
  delay(1000);
  digitalWrite(led, 1);
  Serial.print(pir);
  Serial.print("pir");
}
else {
  digitalWrite ( led, 0);
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print(" off ");
  delay(1000);
}
delay (150);
}
