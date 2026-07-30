#include<LiquidCrystal_I2C.h>
#include <Servo.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int led =13;
int pir = 12;
int pingPin =A0; 
Servo s;

void setup() {
  Serial.begin(9600);
  
lcd.init(); // init= initialisation of lcd 
lcd.backlight(); // to turn the backlight 
pinMode(led, OUTPUT);
pinMode (pir , INPUT );
s.attach (10);
lcd.setCursor (0,0);
lcd.print("pir for door ");
lcd.setCursor (0,1);
lcd.print("dist for lift");
delay (3000);
}

long getDistance() {
  long duration;

  // Send a short trigger pulse on the SAME pin
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // Switch pin to INPUT to listen for the echo
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH, 30000);

  // Convert duration to distance in cm
  long distanceCm = duration / 29 / 2;
  return distanceCm;
}

void loop() {
  
pir = digitalRead (12);
long distance = getDistance() ;
 

  Serial.print("distance: ");
  Serial.println(distance);
  
  if (pir == 1){
  s.write(90);
  delay(500);
  s.write(0);
}
 if (distance <100 && distance >0 ) {
  digitalWrite(led, 1);
  delay(1000);
}
  
lcd.clear();
  
  lcd.setCursor (0,0);
  if (pir == 1) {
    lcd.print("door is open ");
  }
  else {
    lcd.print("door is closed ");
  }
  lcd.setCursor (0,1);
  if (distance <100 && distance >0 ){
    lcd.print("lift is here ");
  }
  else {
    lcd.print("lift not here ");
  }
  

delay (150);
}