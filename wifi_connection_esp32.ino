#include <WiFi.h>

const char*ssid ="Airtel_CLYXN X SORXN";
const char*password="Studio@1234";

void setup() {
  Serial.begin(9600);

  WiFi.begin(ssid,password);
  Serial.print("connecting to wifi");

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n wifi connected");
  Serial.print(" IP Address: ");
  Serial.println(WiFi.localIP());

}

void loop (){
  

}