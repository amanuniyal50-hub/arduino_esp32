int buzzerPin = 9; // Connect the buzzer's Signal (S) pin to pin 9

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // PART 1: Send a steady ON signal (Testing for Active Buzzer)
  digitalWrite(buzzerPin, HIGH); 
  delay(2000); // Keep it on for 2 seconds
  digitalWrite(buzzerPin, LOW);
  delay(1000); // Pause for 1 second

  // PART 2: Send a pulsing musical tone (Testing for Passive Buzzer)
  tone(buzzerPin, 1000); // Send a 1000Hz sound wave
  delay(2000); // Play for 2 seconds
  noTone(buzzerPin); // Stop the tone
  delay(2000); // Pause for 2 seconds before repeating
}
