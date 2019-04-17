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

> All the soldering should be done on the top side of the Arduino in order to be able to stick it to the bottom of the pedal.

- Open the M-AUDIO pedal by unscrewing all screws

![Inside not-modified M-AUDIO EX-P pedal](/documentation/images/maudio_inside.png)

- Desolder the polarity switch wires (1)
- Cut the JACK cable and remove the grommet, we will reuse it later

![Get the grommet](/documentation/images/maudio_cable_cut_and_reuse.png)

- Solder the black wire (4) of sensitivity potentiometer (3) to Arduino GND
- Solder the black wire (5) of expression pedal potentiometer (2) to Arduino VCC
> The wire is connected to the input of the potentiometer
- Solder the black wire (6) of expression pedal potentiometer (2) to Arduino A0 
> The wire is connected to the output of the potentiometer

- Insert the bare USB cable into the grommet and solder the Micro USB connector
- Add some black tape on the USB cable in order to fix it with the grommet (the tape sticky side on the cable, the cable will adhere to the grommet by friction)
- Insert the Micro USB connector into the Arduino USB port
- Stick the Arduino board to the bottom of the pedal with some good melted glue (and let it dry)

![After sticking the Arduino](/documentation/images/maudio_inside_after.png)

- Test the pedal with you DAW

> The pedal in high position

![Pedal test](/documentation/images/maudio_wah_high_position.png)

> The pedal in low position

![Pedal test](/documentation/images/maudio_wah_low_position.png)

- Close the M-AUDIO pedal.

- You're done