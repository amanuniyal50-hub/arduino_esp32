#define BLYNK_PRINT Serial 
#define BLYNK_TEMPLATE_NAME "servo gas led"
#define BLYNK_AUTH_TOKEN "QfaC2C6m9sIJXD2qBDNFPTdvj97FkAzl"
#define BLYNK_TEMPLATE_ID "TMPL3QigMcrQX"

#include <WiFi.h>
#include<BlynkSimpleEsp32.h>
#include<ESP32Servo.h>
const char* ssid = "Airtel_CLYXN X SORXN_EXT";
const char* pass =  "Studio@1234";
const char* auth = "QfaC2C6m9sIJXD2qBDNFPTdvj97FkAzl";
#define mqpin 34
#define virtualpin1 V0
#define virtualpin2 V1
#define virtualpin3 V2
Servo s;
BLYNK_WRITE(V2){
  int value = param.asInt();
  s.write(value);
}

BLYNK_WRITE(V3){
  int value = param.asInt();
  value ? digitalWrite(2 , HIGH) : digitalWrite(2,LOW);
}
BLYNK_WRITE(V4){
  int value = param.asInt();
  value ? digitalWrite(4 , HIGH) : digitalWrite(4,LOW);
}
BLYNK_WRITE(V5){
  int value = param.asInt();
  value ? digitalWrite(18 , HIGH) : digitalWrite(18,LOW);
}


void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  WiFi.begin (ssid,pass);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
Serial.println("wifi connected");
s.attach(5);
pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(18,OUTPUT);
}

void loop() {
  int gasvalue= analogRead(mqpin);
  Blynk.virtualWrite(virtualpin1,gasvalue);
  float percentagegas = (gasvalue/4095.0) *100;
  Blynk.virtualWrite(virtualpin2,percentagegas);
  Serial.print("Gas Sensor Value: ");
  Serial.println(gasvalue);
  Serial.println(percentagegas);

  Blynk.run();
  delay(1500);

}
