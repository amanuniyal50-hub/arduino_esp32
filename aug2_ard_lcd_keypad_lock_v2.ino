#include <Keypad.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo s;

char pass[] = "1234";
int position = 0;
const byte rows = 4;
const byte cols = 4;

char keys[rows][cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowpins[rows] = {10, 9, 8, 7};
byte colpins[cols] = {6, 5, 4, 3};

Keypad keypad = Keypad(makeKeymap(keys), rowpins, colpins, rows, cols);

int green = 13;
int red = 12;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);

  s.attach(11);
  
  lcd.init();
  lcd.backlight(); 
  
  // Set initial locked state without the 3-second delay at startup
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  s.write(0);
  
  showPrompt();
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    // Print the pressed key on the second row
    lcd.setCursor(position, 1);
    lcd.print('*'); // Prints '*' for security, change to 'key' if you want to see the number

    if (key == '*' || key == '#') {
      position = 0;
      lockDoor();
    } 
    else if (key == pass[position]) {
      position++;
    } 
    else {
      position = 0; // Wrong key resets progress
      lcd.setCursor(0, 1);
      lcd.print("    "); // Clear entry line
    }

    if (position == 4) {
      unlockDoor();
      position = 0;
    }
  }
  delay(50);
}

void showPrompt() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");
}

void lockDoor() {
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  s.write(0);
  showPrompt();
}

void unlockDoor() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Access Granted!");
  
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  s.write(90);
  
  delay(3000); // Keep door open for 3 seconds
  
  lockDoor();  // Auto-relock
}
