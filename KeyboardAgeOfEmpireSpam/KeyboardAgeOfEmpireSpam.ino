#include "DigiKeyboard.h"

// Spam Age of Empires 2 Taunts
// Little Digistump Programm
// @author = Rosaroterpanther

long randNumber;
boolean started = false; 

void setup() {
  // don't need to set anything up to use DigiKeyboard
  Serial.begin(9600);
  randomSeed(analogRead(0));
}


void loop() {
  // this is generally not necessary but with some older systems it seems to
  // prevent missing the first character after a delay:
  DigiKeyboard.sendKeyStroke(0);

  if(!started){
    DigiKeyboard.delay(2000);
    DigiKeyboard.print("Age of Empire 2 Spammer");
    DigiKeyboard.delay(50);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.print("Start in 2 Seconds");
    DigiKeyboard.delay(50);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(2000);
    started = true;
  }

  // Generate a random number from 1 to 42
  randNumber = random(1, 43);

  // Print a random taunt
  // Age of Empire 2 taunts overview
  // http://ageofempires.wikia.com/wiki/Taunts
  DigiKeyboard.print(randNumber);
  DigiKeyboard.delay(10);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  
}

