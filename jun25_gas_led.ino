int gas = A0;
int led = 13;
void setup ()
{
  pinMode(gas,INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
 }
void loop ()
{
  gas = analogRead(A0);
  Serial.println(gas);
  if (gas > 180)
  {
    digitalWrite(led,1);
  }
  else
  {
    digitalWrite(led,0);
  }
}
      