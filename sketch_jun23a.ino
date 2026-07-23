#include<LiquidCrystal.h>
// LiquidCrystal lcd ( RS, E, D4,D5,D6,D7); ( this is the order )
// lcd is the variable name
LiquidCrystal lcd ( 13,12,11,10,9,8);
void setup ()
{
  lcd.begin (16,2); // 16x2 display 
}
void loop()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("hello ");
}