#include <WiFi.h>

const char*ssid ="Airtel_CLYXN X SORXN_EXT";
const char*password="Studio@1234";
int led=2;
WiFiClient client;
WiFiServer server(80);

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

  server.begin();
  pinMode(led,OUTPUT);

}

void loop () {
  client= server.available();
  if (client ==1){
    String request = client.readStringUntil ('\n');
    Serial.println(request);
    request.trim();
    if (request == "GET/ ledon HTTP/1.1")
    {
      digitalWrite(led,1);
    }
    if (request == "GET/ ledoff HTTP/1.1")
    {
      digitalWrite(led,0);
    }
    client.stop();
  }
}