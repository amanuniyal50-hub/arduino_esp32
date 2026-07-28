char value;
int motor =13;
int fan = 12;
int led = 11;

void setup() {
  pinMode(motor, OUTPUT);
  pinMode(fan, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while(Serial.available()>0){
    value = Serial.read();
    Serial.print(value);
    if(value == 'A' || value == 'a' || value == 'B' || value == 'b' || value == 'C' || value == 'c'){
      if (value =='A'){
      digitalWrite (motor , 1);
    }
    if ( value == 'a'){
      digitalWrite (motor , 0);
    }
    if(value == 'B'){
      digitalWrite (fan , 1);
    }
    if(value == 'b'){
      digitalWrite (fan , 0);
    }
    if(value == 'C'){
      digitalWrite (led , 1);
    }
    if(value == 'c'){
      digitalWrite (led , 0);
    }
    }
    else {
      digitalWrite (motor , 0);
      digitalWrite (fan , 0);
      digitalWrite (led , 0);
    }
  }
delay(150);
}
