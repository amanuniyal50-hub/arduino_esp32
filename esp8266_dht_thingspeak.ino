
// code for esp8266 and dht11 sensor with thingspeak


#include <DHT.h>
#include <Adafruit_Sensor.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

DHT dht(D6, DHT11);

WiFiClient client;

long myChannelNumber = 2590447;
const char myWriteAPIKey[] = "RB202B5UCGT2DGS4";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin("tantraniketan_2.4G", "tantraniketan@2022");
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());
  dht.begin();
  ThingSpeak.begin(client);
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.println("Temperature: " + (String) t);
  Serial.println("Humidity: " + (String) h);
  ThingSpeak.writeField(myChannelNumber, 1, t, myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 2, h, myWriteAPIKey);
  delay(2000);
}