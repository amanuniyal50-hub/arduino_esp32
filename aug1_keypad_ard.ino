#include <Keypad.h>

const byte r=4;
const byte c=4;

char keys[r][c] =
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte row[r] ={13,12,11,10};
byte coloumn[c]= {9,8,7,6};

Keypad keypad1 = Keypad(makeKeymap(keys),row,coloumn,r,c);

void setup() {
Serial.begin(9600);
}

void loop() {
char key1= keypad1.getKey();
if(key1){
  Serial.println(key1);
}
}
