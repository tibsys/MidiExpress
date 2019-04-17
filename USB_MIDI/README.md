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

## Mounting procedure

- Open the M-AUDIO pedal by unscrewing all screws

![Inside not-modified M-AUDIO EX-P pedal](/documentation/images/maudio_inside.png)

- Desolder the polarity switch (1), unscrew and remove it
- Cut the JACK cable (C) and remove it

![After removing the polarity switch](/documentation/images/maudio_step1.png)

- Solder the black wire (4) of sensitivity potentiometer (3) to Arduino GND

![After GND soldering](/documentation/images/maudio_step2.png)

- Solder the black wire (5) of expression pedal potentiometer (2) to Arduino VCC
> The wire is connected to the input of the potentiometer
- Solder the black wire (6) of expression pedal potentiometer (2) to Arduino A0 
> The wire is connected to the output of the potentiometer

![After VCC and A0 soldering](/documentation/images/maudio_step3.png)

- Insert the bare USB cable into the grommet and solder the Micro USB connector

![After Micro USB soldering](/documentation/images/maudio_step4.png)

- Stick the Arduino board with the pedal with some good melted glue (and let it dry)

![After sticking the Arduino](/documentation/images/maudio_step5.png)

- Test the pedal with you DAW

![Pedal test](/documentation/images/maudio_test.png)

- Close the M-AUDIO pedal.

- You're done