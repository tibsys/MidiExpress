# MidiExpress

MIDIExpress is a MIDI-PC interface originaly designed to connect an expression pedal with only Jack connector to a PC.

At the end of prototyping, it appeared that there should be two devices:
- a Jack-USB device which can be directly connected to a PC
- a Jack-DIN device which can be connected to another MIDI device or to a PC usin a MIDI-USB adapter

## Licensing

The design and source codes are provided freely under a close licence. It makes you able to implement the whole project for your own usage but not to sell it.

## Presentation

The project contains an electronic part, a software part (firmware and MIDI controller) and an enclosure part.

### Electronic

- Jack-DIN is based on Arduino nano (clones compatible) with no specific firmware
- Jack-USB is based on ATMega 32u4 (Arduino micro, esplora, leonardo and clones) or based on a ATMega8 with additional components and an USB firmware.

### Firmware

Only the Jack-USB needs a specific firmware if using an ATMega8. More details to come.

### Software

The software is fully based on Arduino APIs and can be upgraded using an additionnal software provided later.

## Architecture

### Jack-USB
![Global architecture of the project](documentation/images/architecture.png)

### Jack-DIN
Here comes the schema of the architecture of the Jack-DIN project.

## Requirements

### All devices
- provide PC connectivity to an expression with a Jack connector
- ensure compatibility with all DAWs and MIDI controllers
- provide calibration to the user by discovering values range (learn mode)
- provide the user with a manual definition of the values range (0-128)
- provide the user with a choice of the pedal type (expression or volume) and adapt the MIDI message type used

### Jack-USB device
- behave as a USB device (not a serial device)

## Hardware design

### Jack-USB

<img src="documentation/images/board_schematics.png" width=400/>

### Jack-DIN

## Software design

### Firmware

More details to come.

### Arduino software

Here comes a description of the software sub-project

### Configuration software

This software is coded in C++-11 with Qt5. It is designed to make some configuration in the Arduino board in order to change or fine-tune its behaviour.

## Dependencies

Here comes the list of dependencies for this project.

## Licenses and credits

- Arduino schemas made with [Fritzing](http://fritzing.org/).
- USB driver made with ATMEL Studio 7 and based on [to be completed].
- Configuration software made with Qt 5.12.0 community.
- Graphics:
    - *to be completed*

## Documentation and references
- https://www.instructables.com/id/Arduino-USB-MIDI-Interface/
- http://www.takachi-enclosure.com/data/c16-17/MX.pdf
- http://www.takachi-enclosure.com/data/c16-17/LCS.pdf
- https://fr.farnell.com/lumberg/klb-3/embase-femelle-chassis-6-35mm/dp/1217017?gclid=Cj0KCQjw1pblBRDSARIsACfUG13XFAomM-6CBaBJiAR4kC5Tq0doytaKu7zBYqhUrNV_VvNbJfvgU0gaAuHSEALw_wcB&gross_price=true&mckv=1lVx1uZ4_dc|pcrid|80993875142|&CAWELAID=120185620000056177&CAGPSPN=pla&CAAGID=13038046742&CMP=KNC-GFR-GEN-SHOPPING-1217017&CATCI=pla-134775292622
- http://www.takachi-enclosure.com/data/c16-17/2017vol3_21-23.pdf
- http://www.takachi-enclosure.com/data/c16-17/SU.pdf
- http://www.takachi-enclosure.com/data/c16-17/SW.pdf
- 
