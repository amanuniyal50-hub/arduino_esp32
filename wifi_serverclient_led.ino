#include <WiFi.h>

WiFiServer server(80);
WiFiClient client;

const char* ssid = "Airtel_CLYXN X SORXN_EXT";
const char* password = "Studio@1234";

int led = 2;      // Built-in LED on most ESP32 boards (change if required)

void setup()
{
  Serial.begin(9600);

  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("ESP32 Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop()
{
  client = server.available();

  if (client)
  {
    String request = client.readStringUntil('\n');
    request.trim();

    Serial.println(request);

    if (request == "GET /ledon HTTP/1.1")
    {
      digitalWrite(led, HIGH);
      Serial.println("LED ON");
    }

    if (request == "GET /ledoff HTTP/1.1")
    {
      digitalWrite(led, LOW);
      Serial.println("LED OFF");
    }

    client.stop();
  }
}
