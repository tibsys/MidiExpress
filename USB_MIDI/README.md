# USB-MIDI

This sub-tree contains the projects related to the USB-MIDI expression pedal.

## Description

![USB-MIDI expression pedal based on M-AUDIO EX-P](/documentation/images/maudio_exp.png)

The USB-MIDI expression pedal is based on an M-AUDIO EX-P expression pedal (around 16 Euros on Amazon). The electronic device (see Jack-USB section) is embedded into the pedal and the original Jack cable is replaced with a USB cable.

This device is powered by USB.

## Architecture

> The original M-Audio EX-P pedal contains a switch for polarity inversion and a potentiometer for the sensitivity.

![Original M-Audio EX-P pedal schematic](/documentation/images/maudio_exp_schematic.png)

> We disabled the polarity switch and kept the sensitivity potentiometer to give manual control on the expression range.

![Modified M-Audio EX-P pedal schematic](/documentation/images/USB-MIDI_schematics.png)

## Protocol

The pedal does not use any specific channel, it communicates with the *ALL* channel (1-16).

**Pedal -> DAW**

The pedal only sends *Foot Controller* Control Change (MIDI CC 4) on *ALL* channel. Values are between 0 (pedal open) and 128 (pedal closed).

**DAW -> Pedal**

All messages are ignored.