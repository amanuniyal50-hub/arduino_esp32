int x=A4;
int y=A5;
int sw = 2;

#include<Servo.h>

Servo s1;
Servo s2;
Servo s3;
Servo s4;

void setup() {
  Serial.begin(9600);
  s1.attach(3);
  s2.attach(4);
  s3.attach(5);
  s4.attach(6);

  pinMode(sw,INPUT_PULLUP);
}

void loop() {
  int xValue = analogRead(x);
  int yValue = analogRead(y);
  int buttonState = digitalRead(sw);

  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print(" | Y: ");
  Serial.print(yValue);
  Serial.print(" | Button: ");
  Serial.println(buttonState == LOW ? "Pressed" : "Released");

  if (xValue <= 500 && yValue >400 && yValue <600){
    s1.write(180);
    s2.write(0);
    s3.write(0);
    s4.write(0);
  }
  else if (xValue >= 550 && yValue>400 && yValue <600){
    s1.write(0);
    s2.write(180);
    s3.write(0);
    s4.write(0);
  }
  else if(xValue >500 && xValue <600 && yValue >600){
    s1.write(0);
    s2.write(0);
    s3.write(180);
    s4.write(0);
  }
  else if (xValue >500  && xValue <600 && yValue <400 ){
    s1.write(0);
    s2.write(0);
    s3.write(0);
    s4.write(180);
  }
  else {
    s1.write(0);
    s2.write(0);
    s3.write(0);
    s4.write(0);
  }
if(buttonState == 0){
  s1.write(90);
  s2.write(90);
  s3.write(90);
  s4.write(90);
}
delay(200);
}
