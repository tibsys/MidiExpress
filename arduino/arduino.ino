/**
 * This is the MIDI controller program embedded in the Arduino chipset
 */
#include "constants.h"
#include "memory.h"
#include "midi_helper.h"

//
// Variables declarations
//
uint8_t currentPedalPosition = 0; //[0,255]
PedalType currentPedalType = PEDAL_TYPE_EXPRESSION;
uint8_t controlMessageMaxValue = 127; //Depends on the pedal type (volume or expression)
uint8_t midiChannel = 1;

//
// Setup
//
void setup() {    
  Serial.begin(MIDI_TRANSFER_RATE);
  //Verify if memory block is already initialised
  if(!isMemoryInitialised()) {
    initialiseMemory();
  }
}

//
// Main loop
//
void loop() {

  //Read current position of the pedal
  uint8_t newPosition = analogRead(INPUT_PIN);
  if(newPosition != currentPedalPosition) {
    //Prepare the new value
    uint8_t midiValue = map(newPosition, 0, 1023, 0, controlMessageMaxValue);
    sendControlCommand(MIDI_CMD_CONTROL, MIDI_CMD_EXPRESSION, midiValue);
  }

  //Read incoming MIDI configuration messages
}
