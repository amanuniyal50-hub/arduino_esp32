#define BLYNK_PRINT Serial 
#define BLYNK_TEMPLATE_ID "TMPL3wblZpJOd"
#define BLYNK_TEMPLATE_NAME "water irrigation"
#define BLYNK_AUTH_TOKEN "8GIdny_ooXqJKgp_Ib0rQtc5rODMde_Q"

#include<Wire.h>
#include <WiFi.h>
#include<BlynkSimpleEsp32.h>
#include<ESP32Servo.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

const char* ssid = "Airtel_CLYXN X SORXN";
const char* pass =  "Studio@1234";
const char* auth ="8GIdny_ooXqJKgp_Ib0rQtc5rODMde_Q";

#define virtualpin1 V0
#define virtualpin2 V1
#define moisture 34

int motor =13;
int led1 =5; //red
int led2 =4; //green
bool manual =false;
int moisturevalue=0;

BLYNK_WRITE(V1){
  int value = param.asInt();
  value ? digitalWrite(13 , HIGH) : digitalWrite(13,LOW);
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

pinMode (motor,OUTPUT);
pinMode (moisture,INPUT);
pinMode (led1,OUTPUT);
pinMode (led2,OUTPUT);

lcd.init();
lcd.backlight (); 
lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("water irrigation");
  delay (3000);
}

void loop() {
 moisturevalue = analogRead(moisture);
Serial.println(moisturevalue);
Blynk.virtualWrite(virtualpin1,moisturevalue);

if (manual==false){ 
if (moisturevalue <2000) {
  digitalWrite(led1,1);
  digitalWrite(led2,0);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("moisture: ");
  lcd.print(moisturevalue);
  digitalWrite(motor,0);
  lcd.setCursor(0, 1);
  lcd.print("motor off");
} 
else {
  digitalWrite(led2,1);
  digitalWrite(led1,0);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("moisture: ");
  lcd.print(moisturevalue);
  digitalWrite(motor,1);
  lcd.setCursor(0, 1);
  lcd.print("motor on");

}
}

Blynk.run();
delay(1500);
}
