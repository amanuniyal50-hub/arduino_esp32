int x=A4;
int y=A5;
int sw = 3;

void setup() {
  Serial.begin(9600);
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

  delay(250);

}
