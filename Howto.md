# How to

## Flash the firwmare into an Arduino Nano
https://skyduino.wordpress.com/2011/12/02/tutoriel-avrdude-en-ligne-de-commande/
avrdude -v -pm328p -cavrisp -b19200 -P/dev/cu.usbserial-A603UXCD -D -Uflash:w:/Users/tristan/Downloads/MidiShield1.hex