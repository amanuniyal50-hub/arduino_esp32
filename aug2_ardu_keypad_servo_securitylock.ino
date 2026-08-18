#include<Keypad.h>
#include<Servo.h>


Servo s;
char pass[] = "A123";
int position =0;
const byte rows=4;
const byte cols=4;
char keys [rows][cols]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};

byte rowpins[rows]= {10,9,8,7};
byte colpins[cols]= {6,5,4,3};

Keypad keypad = Keypad(makeKeymap(keys),rowpins,colpins,rows,cols);

int green=13;
int red=12;

void setup () {
  pinMode (red,OUTPUT);
  pinMode (green,OUTPUT);

  s.attach(11);
  lockedposition(true);

}

void loop () {
  char key=keypad.getKey();

if(key){
  if(key=='*' || key=='#'){
    position=0;
    lockedposition(true);
  }
  else if (key ==pass[position]){
    position++;
  }
  else {
    position=0;
  }
  if(position==4){
    lockedposition(false);
    position=0;
  }
}
delay(100);
}

void lockedposition(int locked){
  if (locked) {
    digitalWrite(red,1);
    digitalWrite(green,0);
    s.write(0);
  }
  else {
    digitalWrite(red,0);
    digitalWrite(green,1);
    s.write(90);
  }
}


