#define BLYNK_TEMPLATE_NAME "GAS SENSOR"
#define BLYNK_AUTH_TOKEN "3QFRaNGPm6RcjQZUfgfZdXfPZNmqwj9m"
#define BLYNK_TEMPLATE_ID "TMPL3n_SYzIvZ"
#define BLYNK_PRINT Serial 

#include <WiFi.h>
#include<BlynkSimpleEsp32.h>
const char* auth = "3QFRaNGPm6RcjQZUfgfZdXfPZNmqwj9m";
const char* ssid = "Airtel_CLYXN X SORXN_EXT";
const char* pass =  "Studio@1234";

#define mqpin 34
#define virtualpin1 V0
#define virtualpin2 V1
void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  WiFi.begin (ssid,pass);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
Serial.println("wifi connected");

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
