#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
void setup (){
  lcd.init(); // init= initialisation of lcd 
  lcd.backlight (); // to turn the backlight 
}
void loop (){
  lcd.setCursor (0,0);
  lcd.print("hey ");
}
// click on the lcd display in tinkercad and select pcf based type and the address u have selected 