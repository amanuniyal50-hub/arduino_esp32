int led =13;
int pir = 12;

void setup() {
pinMode(led, OUTPUT);
pinMode (pir , INPUT );
Serial.begin (9600);
}

void loop() {
pir = digitalRead (12);
if (pir ==  1)
{
  digitalWrite(led, 1);
  Serial.print(pir);
  Serial.print("pir");
}
else {
  digitalWrite ( led, 0);
}
delay (150);
}
