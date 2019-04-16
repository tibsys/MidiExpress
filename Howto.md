# How to

This page gathers some helpful documentation related to AVR, MIDI and enclosures.

## MIDI how tos
- https://www.arduino.cc/en/Tutorial/MidiDevice

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

## USB Firmware
- https://codeandlife.com/2017/09/17/5-usb-midi-adapter-with-atmega32u4/

## A étudier
- http://codeandlife.com/2017/09/17/5-usb-midi-adapter-with-atmega32u4/#more-2071

## Fasteners
- https://docs-emea.rs-online.com/webdocs/0314/0900766b803148ae.pdf

## Passe-fil
- https://fr.rs-online.com/web/p/passe-cables-en-caoutchouc/1879605/

## Cables
- https://fr.rs-online.com/web/p/cables-usb/3248362/
- https://fr.rs-online.com/web/p/products/1216571/?grossPrice=Y&cm_mmc=FR-PLA-DS3A-_-google-_-PLA_FR_FR_Automatisme_Et_Contrôle_De_Process-_-Boutons-Poussoirs_And_Voyant_Lumineux_Et_Boîtes_À%C2%A0Boutons_Industriels%7CBoîtes_À%C2%A0Boutons_Équipées-_-PRODUCT_GROUP&matchtype=&pla-458695438936&gclid=EAIaIQobChMI7JeMr4jS4QIVRPhRCh3LxATJEAQYAyABEgKSVPD_BwE&gclsrc=aw.ds

## AVR how tos
- https://maker.pro/custom/tutorial/how-to-take-analog-readings-with-an-avr-microcontroller

## Extra documentation
- https://www.instructables.com/id/Arduino-USB-MIDI-Interface/
- http://www.takachi-enclosure.com/data/c16-17/MX.pdf
- http://www.takachi-enclosure.com/data/c16-17/LCS.pdf
- https://fr.farnell.com/lumberg/klb-3/embase-femelle-chassis-6-35mm/dp/1217017?gclid=Cj0KCQjw1pblBRDSARIsACfUG13XFAomM-6CBaBJiAR4kC5Tq0doytaKu7zBYqhUrNV_VvNbJfvgU0gaAuHSEALw_wcB&gross_price=true&mckv=1lVx1uZ4_dc|pcrid|80993875142|&CAWELAID=120185620000056177&CAGPSPN=pla&CAAGID=13038046742&CMP=KNC-GFR-GEN-SHOPPING-1217017&CATCI=pla-134775292622
- http://www.takachi-enclosure.com/data/c16-17/2017vol3_21-23.pdf
- http://www.takachi-enclosure.com/data/c16-17/SU.pdf
- http://www.takachi-enclosure.com/data/c16-17/SW.pdf
- 
