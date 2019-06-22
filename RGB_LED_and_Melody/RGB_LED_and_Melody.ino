/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 0

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone
*/

int speakerPin = 0;

int redPin = 1;
int greenPin = 2;
int bluePin = 4;

//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE

int buttonPin = 3;

int fanPin = 5;

#include "pitches.h"


// Melody adapted from https://www.letsplaykidsmusic.com/happy-birthday-easy-piano-music/
// notes in the melody:
int melody[] = {
  NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, NOTE_C4, NOTE_B3, 0, 
  NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, NOTE_D4, NOTE_C4, 0, 
  NOTE_G3, NOTE_G3, NOTE_G4, NOTE_E4, NOTE_C4, NOTE_B3, NOTE_A3, 0, 
  NOTE_F4, NOTE_F4, NOTE_E4, NOTE_C4, NOTE_D4, NOTE_C4, 0,
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 4, 2, 2, 2, 2, 4, 
  4, 4, 2, 2, 2, 2, 4, 
  4, 4, 2, 2, 2, 2, 2, 4,
  4, 4, 2, 2, 2, 1, 1,
};

void playMelody()
{
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < sizeof(melody) / 2; thisNote++) {
    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(speakerPin, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(speakerPin);
  }
}


// notes in the melody:
int melody2[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations2[] = {
  4, 8, 8, 4 , 4, 4, 4, 4
};

void playMelody2()
{
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < sizeof(melody2) / 2; thisNote++) {
    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations2[thisNote];
    tone(speakerPin, melody2[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(speakerPin);
  }
}

void fastBlink()
{
  setColor(255, 0, 0);
  delay(50);
  setColor(0, 0, 0);
  delay(50);    
}

void buttonPressed()
{
//  fastBlink();
//  fastBlink();
//  fastBlink();
}


void setup() {
  // prepare for color show
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  pinMode(fanPin, OUTPUT);
  analogWrite(fanPin, 0);

  pinMode(buttonPin, INPUT);
}


void loop() {
  int buttonState = 0;
  
  // do a color show
  setColor(255, 255, 255);  // white
  if (digitalRead(buttonPin)) buttonPressed();
  delay(1000);
  setColor(255, 0, 0);  // red
  if (digitalRead(buttonPin)) buttonPressed();
  delay(1000);
  // Note: when that many pins are connected on the Digispark,
  // it seems that green does not light up alongside with red, 
  // when green value is < 128. 
  setColor(255, 96, 0);  // orange
  if (digitalRead(buttonPin)) buttonPressed();
  delay(1000);
  setColor(192, 96, 0);  // yellow
  if (digitalRead(buttonPin)) buttonPressed();
  delay(1000);  
  setColor(0, 255, 0);  // green
  if (digitalRead(buttonPin)) buttonPressed();
  delay(1000);
  setColor(0, 0, 255);  // blue
  if (digitalRead(buttonPin)) buttonPressed();
  delay(1000);
  setColor(32, 0, 128);  // indigo
  if (digitalRead(buttonPin)) buttonPressed();
  delay(1000);
  setColor(96, 0, 128 );  // violet
  if (digitalRead(buttonPin)) buttonPressed();
  delay(1000);
  setColor(0, 255, 255);  // aqua
  if (digitalRead(buttonPin)) buttonPressed();
  delay(1000);
//  setColor(255, 0, 255);  // ???
//  delay(2000);

  analogWrite(fanPin, 128);
  playMelody2();
  analogWrite(fanPin, 0);

  if (digitalRead(buttonPin)) buttonPressed(); 
}

/*
Adafruit Arduino - Lesson 3. RGB LED
*/

void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
