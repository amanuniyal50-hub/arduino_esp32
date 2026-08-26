// Define the musical notes and their sound frequencies (pitches)
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440

int buzzerPin = 9; // Connect the buzzer's Signal (S) pin to pin 9

// The notes of the song in order
int melody[] = {
  NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4,
  NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4
};

// The duration of each note (4 = quarter note, 2 = half note)
int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2
};

void setup() {
  // Loop through the 14 notes of the melody
  for (int thisNote = 0; thisNote < 14; thisNote++) {

    // Calculate how long the note should play in milliseconds
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzerPin, melody[thisNote], noteDuration);

    // Add a tiny pause between notes so they don't blur together
    int pauseBetweenNotes = noteDuration * 1.2;
    delay(pauseBetweenNotes);
    
    // Stop the sound before playing the next note
    noTone(buzzerPin);
  }
}

void loop() {
  // Left empty because we only want the song to play once at startup!
}

