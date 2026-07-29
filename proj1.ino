#include<LiquidCrystal_I2C.h>
#include <Servo.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int led =13;
int touch = 12;
int ir =11; 
Servo s;

void setup() {
lcd.init(); // init= initialisation of lcd 
lcd.backlight(); // to turn the backlight 
pinMode(led, OUTPUT);
pinMode (touch , INPUT );
pinMode (ir , INPUT );
s.attach (10);
lcd.setCursor (0,0);
lcd.print("touch for door ");
lcd.setCursor (0,1);
lcd.print("ir for lift");
delay (3000);
}

void loop() {
touch = digitalRead (12);
ir= digitalRead (11);
if (touch == 1){
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print("door is open ");
  delay(1000);
  s.write(90);
  delay(500);
  s.write(0);
}
 if (ir ==  0)
{
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print("lift is here ");
  delay(2000);
  digitalWrite(led, 1);
  delay(2000);
}

if (touch != 1 , ir !=0)
{
lcd.clear();
lcd.setCursor (0,0);
lcd.print("door is closed ");
lcd.setCursor (0,1);
lcd.print("lift not here");
digitalWrite(led, 0);
s.write(0);  

}
delay (150);
}