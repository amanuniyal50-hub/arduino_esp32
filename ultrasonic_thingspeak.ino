#include<WiFi.h>
#include<ThingSpeak.h>

const char* ssid = "Airtel_CLYXN X SORXN_EXT";
const char* password = "Studio@1234";

long channelid = 3426131;
const  char* apikey ="ELHSJHB9UUUEQ843";
WiFiClient client;

int trig =5;
int echo=18;
long dist;
long t;

void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(115200);
  WiFi.begin(ssid,password);
  Serial.print("connecting");

  while( WiFi.status() != WL_CONNECTED) {
    delay(300);
    Serial.print(".");
  }
  Serial.println("connected");
  ThingSpeak.begin(client);
}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(5);
  digitalWrite(trig,LOW);
  t = pulseIn(echo,HIGH);
  dist = t*0.017;
  Serial.print("the distance is= ");
  Serial.print(dist);
  Serial.println();

  ThingSpeak.setField(1,dist);
  int response = ThingSpeak.writeFields(channelid,apikey);

  delay(300);
}
