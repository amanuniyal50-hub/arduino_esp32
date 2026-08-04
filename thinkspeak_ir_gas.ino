#include <WiFi.h>
#include <ThingSpeak.h>

const char* ssid = "Airtel_CLYXN X SORXN_EXT";
const char* password ="Studio@1234";

unsigned long channelID = 3425700;
const char* apiKey = "PV7PBBXW73QBWBLW";

WiFiClient client;
int ir = 14;
int gas = 34;

void setup() {
  Serial.begin(115200);
  pinMode(ir, INPUT);
  pinMode(gas,INPUT);
   WiFi.begin(ssid, password);
   Serial.print("Connecting to wifi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
  ThingSpeak.begin(client);

}

void loop() {
  int irvalue = digitalRead(ir); 
  int gasvalue= analogRead(gas);
  Serial.print("ir sensor value :");
  Serial.println(irvalue);
  Serial.print("gas sensor value :");
  Serial.println(gasvalue);

  ThingSpeak.setField(1,irvalue); // set thingspeak field number 1
  ThingSpeak.setField(2,gasvalue);
  int response = ThingSpeak.writeFields(channelID,apiKey);

  delay(200);
}
