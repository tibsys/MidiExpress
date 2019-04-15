/*
 MIDI helper functions
*/
void sendControlCommand(int control, int command, int value) {
  Serial.write(control);
  Serial.write(command);
  Serial.write(value);
}
