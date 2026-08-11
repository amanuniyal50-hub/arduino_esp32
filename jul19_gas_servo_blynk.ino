#define BLYNK_PRINT Serial 
#define BLYNK_TEMPLATE_NAME "servo plus gas"
#define BLYNK_AUTH_TOKEN "Bl622YrIk9no0Wp7R_xadciDI_QGwkry"
#define BLYNK_TEMPLATE_ID "TMPL3COi0XIpd"

#include <WiFi.h>
#include<BlynkSimpleEsp32.h>
#include<ESP32Servo.h>
const char* ssid = "Airtel_CLYXN X SORXN_EXT";
const char* pass =  "Studio@1234";
const char* auth = "Bl622YrIk9no0Wp7R_xadciDI_QGwkry";
#define mqpin 34
#define virtualpin1 V0
#define virtualpin2 V1
#define virtualpin3 V2
Servo s;
BLYNK_WRITE(V2){
  int value = param.asInt();
  s.write(value);
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
