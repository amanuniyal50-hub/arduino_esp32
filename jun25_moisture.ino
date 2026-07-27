int moisture = A0;
int led = 13;
void setup ()
{
  pinMode(moisture,INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
 }
void loop ()
{
  moisture = analogRead(A0);
  Serial.println(moisture);
  if (moisture < 700)
  {
    digitalWrite(led,1);
  }
  else
  {
    digitalWrite(led,0);
  }
}