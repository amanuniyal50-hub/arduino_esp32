#include <Servo.h>
Servo s; // s is the variable name
void setup() {
  s.attach(13);
}
void loop () {
  s.write(30);
  delay(100);
  s.write(60);
  delay(100);
  s.write(90);
  delay(100);
  s.write(120);
  delay(100);
}
