#include "DigiKeyboard.h"

/*
 * Template for Digispark
 * This template allows you to open a console
 * with admin rights
 * and let you run all your commands
 * @author = Rosaroterpanther
*/

int iterationCounter = 0;
boolean dev = true;

void setup() {
  // don't need to set anything up to use DigiKeyboard
}


void loop() {
  DigiKeyboard.update();

  if(iterationCounter == 0){
    // this is generally not necessary but with some older systems it seems to
    // prevent missing the first character after a delay:
    DigiKeyboard.sendKeyStroke(0);
  }
  iterationCounter++;
  
  // Open a cmd console cmd with admin rights
  // Search for cmd
  DigiKeyboard.sendKeyStroke(0, MOD_GUI_LEFT);
  DigiKeyboard.delay(50);
  DigiKeyboard.print("cmd");
  DigiKeyboard.delay(50);
  // Open cmd with admin rights
  DigiKeyboard.sendKeyStroke(KEY_ENTER, MOD_CONTROL_LEFT | MOD_SHIFT_LEFT);
  DigiKeyboard.delay(900);
  // Accept Opening with Admin rights
  DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(200);

  //========================================================================
  // Be aware if you have a German or Us Keyboard activated in windows
  // For example German /a is -a in US
  // Run your own code
  
  runCommand("echo We have full control …");
  // German Keyboard
  runCommand("arp /a"); // US Keyboard runCommand("arp -a");

  //========================================================================

  // Clean up
  // You delete this up in a real use case
  if(dev){
    DigiKeyboard.delay(5000);
  }
  
  DigiKeyboard.print("exit");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  
  // You delete this up in a real use case
  if(dev){
    // Only for Development reasons
    DigiKeyboard.delay(5000);
  }
}

void runCommand(String cmd){
  DigiKeyboard.print(cmd);
  DigiKeyboard.delay(50);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(50);
}
