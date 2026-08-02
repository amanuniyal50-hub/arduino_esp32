int moisture = 2;
int led = 4;
void setup ()
{
  pinMode(moisture,INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
 }
void loop ()
{
  moisture = analogRead(2);
  Serial.println(moisture);
  if (moisture > 2000)
  {
    digitalWrite(led,1);
  }
  else
  {
    digitalWrite(led,0);
  }
}