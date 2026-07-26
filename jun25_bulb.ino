int bulb = 13;

void setup() {
  pinMode(bulb, OUTPUT);

}

void loop() {
  digitalWrite(bulb, HIGH );
  delay (2000);
  digitalWrite(bulb, LOW);
  delay (2000);

}
