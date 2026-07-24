#include <Servo.h>
Servo s;
void setup (){
  int pos;
  s.attach(13);
}
void loop (){
  for (int pos = 0; pos <= 180; pos++){
    s.write(pos);
    delay(500);
  }
}