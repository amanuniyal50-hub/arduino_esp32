int ldrPin = A0;
int ledPin = 9;

void setup() { pinMode(ledPin, OUTPUT); }

void loop() {
  int light = analogRead(ldrPin);       // 0 (dark) to 1023 (bright)
  int brightness = map(light, 0, 1023, 255, 0); // inverse: dark = bright LED
  analogWrite(ledPin, brightness);
  delay(50);
}
