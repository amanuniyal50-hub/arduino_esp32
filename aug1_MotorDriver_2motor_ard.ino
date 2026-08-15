int m1 =10;
int m2 =11;
int m3 =12;
int m4 =13;



void setup() {
pinMode(m1,OUTPUT);
pinMode(m2,OUTPUT);
pinMode(m3,OUTPUT);
pinMode(m4,OUTPUT);

}

void loop() {
  // this is code so that both motor will move forward
digitalWrite(m1,1);
digitalWrite(m2,0);
digitalWrite(m3,1);
digitalWrite(m4,0);
 
 // code for both motor to go back 
/*
digitalWrite(m1,0);
digitalWrite(m2,1);
digitalWrite(m3,0);
digitalWrite(m4,1); 
*/ 

// code to move right 
/*
basically left side motor moving and right side motor stopped 
digitalWrite(m1,1);
digitalWrite(m2,0);
digitalWrite(m3,0);
digitalWrite(m4,0);
*/
}
