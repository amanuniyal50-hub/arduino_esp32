#include<WiFi.h>
#include<ThingSpeak.h>
#include<ESP32Servo.h>
#include<LiquidCrystal_I2C.h>
#include<Wire.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>

LiquidCrystal_I2C lcd(0x27,16,2);
Servo s;
const char*ssid = "Airtel_CLYXN X SORXN_EXT";
const char*password = "Studio@1234";

long channelid =3428137;
const  char* apikey ="IPRPT8379PYGSOH5";
WiFiClient client;

int trig =5;
int echo=18;
long dist;
long t;
int ir = 14;
int gas = 34;
int pir = 33;
DHT dht(4, DHT11);
// for lcd use pin21 for sda and pin22 for scl

void setup() {
  pinMode(ir, INPUT);
  pinMode(gas,INPUT);
  pinMode(pir,INPUT);
  s.attach(13);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(115200);
  WiFi.begin (ssid,password);
  Serial.print("connecting");

  while(WiFi.status() != WL_CONNECTED){
    delay(200);
    Serial.print(".");
  }
  Serial.print("connected");
  ThingSpeak.begin(client);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("water level");
  lcd.setCursor(5,1);
  lcd.print("detection");
  delay (3000);

}

void loop() {

  int irvalue = digitalRead(ir); 
  int gasvalue= analogRead(gas);
  int pirvalue = digitalRead(pir); 

  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(5);
  digitalWrite(trig,LOW);
  t=pulseIn(echo,HIGH);
  dist=t*0.017;
  Serial.print("distance is ");
  Serial.print(dist);
  Serial.println();
  Serial.print("ir sensor value :");
  Serial.println(irvalue);
  Serial.print("gas sensor value :");
  Serial.println(gasvalue);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("disatnce is ");
  lcd.print(dist);
  
  lcd.setCursor(0,1);
  if(dist > 110){
    lcd.print("tank 75% full");
  }
   else if (dist >80 && dist<=110){
    lcd.print("tank 50% full");
  }
  else if (dist <= 80){
    lcd.print("tank <50%");
  }
  
  if (dist >= 80){
    s.write(90);
  }
  if(dist<80){
    s.write(0);
  }
  float h = dht.readHumidity();
  float temp = dht.readTemperature();
  Serial.println("Temperature: " + (String) temp);
  Serial.println("Humidity: " + (String) h);
  
ThingSpeak.setField(1,dist);
ThingSpeak.setField(2,ir);
ThingSpeak.setField(3,gas);
ThingSpeak.setField(4,pirvalue);
ThingSpeak.setField(5,temp);
ThingSpeak.setField(6,h);
int response = ThingSpeak.writeFields(channelid,apikey);
delay(5000);
}
