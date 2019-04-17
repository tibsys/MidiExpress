/*
   This program manages the USB expression pedal.

   The hardware is based on
   - M-AUDIO EX-P expression pedal
   - Arduino Pro Micro board

   The pedal is based on a voltage divider. We send the current VCC (+5V) in the pedal
   circuit and mesure it on the A0 analog PIN.
   Depending on the pedal position, the current measured on A0 is between 2.5V (pedal down) and 5V (pedal up).
   The position is translated to a value between 0 and 127 using the MIDI CC 4.

   Created: 2019-04-17
   Version: 1.0
   Author: Tristan Israël <tristan.israel@tibsys.com>
   
   https://www.tibsys.com/
*/

#include <MIDIUSB.h>

/**
 * Constants
 */
const bool DEBUG = false;
const int PEDAL_POSITION_INPUT = 0;  //A0 input
const uint8_t PEDAL_MAX_CURRENT = 1023; //Maximum value read on the input pin
const uint8_t PEDAL_MIN_CURRENT = PEDAL_MAX_CURRENT/2; //Minimum value read on the input pin
const uint8_t PEDAL_MAX_MIDI = 127; //Maximum value in MIDI CC
const uint8_t PEDAL_MIN_MIDI = 0; //Minimum value in MIDI CC
const uint8_t MIDI_CC_FOOTCONTROLLER = 4; //Value for Foot Controller Control Change message

/** 
 * Variables
 */
uint8_t currentPedalPosition = 0;

void setup() {
  if(DEBUG) {
    Serial.begin(115200);
    Serial.println("MIDI Expression pedal initialized and ready!");
  }
}

void loop() {
  //Read the current position of the pedal
  uint8_t pedalPosition = readPosition();

  //If position changed, send the new value to the MIDI controller
  if(pedalPosition != currentPedalPosition) {
    sendPedalPosition(pedalPosition);
    currentPedalPosition = pedalPosition;    
  } 

  if(DEBUG) {
      Serial.print("Current pedal position=");
      Serial.println(currentPedalPosition);
    }
}

/**
 * Sends the pedal position to the MIDI controller
 */
void sendPedalPosition(uint8_t position) {
  sendControlChange(MIDI_CC_FOOTCONTROLLER, position);
}

/**
 * Sends a control change message to the MIDI controller
 * control - the CC message identifier (0-127)
 * value - the value associated to the message (0-127)
 */
void sendControlChange(byte control, byte value) {
  midiEventPacket_t event = {0xB, 0xB0, control, value};
  MidiUSB.sendMIDI(event);
}

/**
 * Reads the position of the pedal in the MIDI expression range (0-127).
 *
 * Because the pedal is a voltage divider, the value measured is between 512 and 1023.
 * The lowest value (512) is converted into the MIDI value 0.
 * The highest value (1023) is converted into the MIDI value 127.
 * The values in the range [512-1023] are converted into MIDI values in the range [0-127].
 */
uint8_t readPosition()
{
  int val = analogRead(PEDAL_POSITION_INPUT);
  uint8_t pedalPosition = (uint8_t) (map(val, PEDAL_MIN_CURRENT, PEDAL_MAX_CURRENT, PEDAL_MIN_MIDI, PEDAL_MAX_MIDI));
  //Serial.print("pedal position:");
  //Serial.println(pedalPosition);
}
