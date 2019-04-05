# How to

## Flash the firwmare into an Arduino Nano
- https://skyduino.wordpress.com/2011/12/02/tutoriel-avrdude-en-ligne-de-commande/
- https://tutorial.cytron.io/2015/02/05/using-avr-usbasp-to-program-arduino/
- http://www.hmangas.com/Electronica/Datasheets/USBasp/AVR-USBasp%20User%20Manual.pdf
- https://www.fischl.de/usbasp/
- avrdude -v -pm328p -cavrisp -b19200 -P/dev/cu.usbserial-A603UXCD -D -Uflash:w:/Users/tristan/Downloads/MidiShield1.hex
- avrdude -v -p m328p -c usbasp -e -b 19200 -U flash:w:/Users/tristan/Downloads/MidiShield1.hex
- https://tosiek.pl/usbasp-v2-0-warning-cannot-set-sck-period/
- https://github.com/obdev/v-usb
- http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega48A-PA-88A-PA-168A-PA-328-P-DS-DS40002061A.pdf

## A étudier
- http://codeandlife.com/2017/09/17/5-usb-midi-adapter-with-atmega32u4/#more-2071
