
//
// Constants definitions
//
const uint8_t INPUT_PIN = A0;

const uint8_t MIDI_CMD_CONTROL = 0xB1;
const uint8_t MIDI_CMD_VOLUME = 7;
const uint8_t MIDI_CMD_EXPRESSION = 11;
const uint16_t MIDI_TRANSFER_RATE = 31250;
const uint8_t MIDI_MAX_EXPRESSION = 127;
const uint8_t MIDI_MAX_VOLUME = 254;

const uint8_t MEMORY_INIT_MAGIC = 0xFA;
enum MemorySlot {
  MEMORY_SLOT_INIT = 0,
  MEMORY_SLOT_PEDALTYPE = 1
};

enum PedalType {
  PEDAL_TYPE_VOLUME = 1,
  PEDAL_TYPE_EXPRESSION = 2,
};
