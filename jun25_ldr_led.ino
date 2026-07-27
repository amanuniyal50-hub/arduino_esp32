int led =12;
int light = 13;
void setup() {
pinMode(led, OUTPUT);
pinMode (light , INPUT );
}
void loop() {
light = digitalRead (13);
if (light ==  1)
{
  digitalWrite(led, 1);
}
  else {
  digitalWrite ( led, 0);
  }
delay(200);
}