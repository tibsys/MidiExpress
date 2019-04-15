/**
 * Memory management
 */
#include <EEPROM.h>

void storePedalType(PedalType pedalType) {
  EEPROM.write(MEMORY_SLOT_PEDALTYPE, pedalType); 
}

uint8_t retrievePedalType() {
  return EEPROM.read(MEMORY_SLOT_PEDALTYPE);  
}

bool isMemoryInitialised() {
  return (EEPROM.read(MEMORY_SLOT_INIT) == MEMORY_INIT_MAGIC);
}

void initialiseMemory() {
  storePedalType(PEDAL_TYPE_EXPRESSION);
  EEPROM.write(MEMORY_SLOT_INIT, MEMORY_INIT_MAGIC);
}
