#define BLYNK_TEMPLATE_ID "TMPL3y2xj964m"
#define BLYNK_TEMPLATE_NAME "button automation"
#define BLYNK_AUTH_TOKEN "2YY4AqmL7-3A0vI29JcDaHKnmu9d50gS"

#define BLYNK_PRINT Serial 

#include <WiFi.h>
#include<BlynkSimpleEsp32.h>

const char* auth = "2YY4AqmL7-3A0vI29JcDaHKnmu9d50gS";
const char* ssid = "Airtel_CLYXN X SORXN_EXT";
const char* pass =  "Studio@1234";

BLYNK_WRITE(V0){
  int value = param.asInt();
  value ? digitalWrite(2 , HIGH) : digitalWrite(2,LOW);
}
BLYNK_WRITE(V1){
  int value = param.asInt();
  value ? digitalWrite(4 , HIGH) : digitalWrite(4,LOW);
}
BLYNK_WRITE(V2){
  int value = param.asInt();
  value ? digitalWrite(5 , HIGH) : digitalWrite(5,LOW);
}

void setup() {
  Serial.begin(9600);

  WiFi.begin (ssid,pass);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
Serial.println("wifi connected");

  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  
  Blynk.begin(auth , ssid , pass);

}

void loop() {
  Blynk.run();

}
