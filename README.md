# A MIDI-USB expression pedal for 25 Euros

MIDIExpress is a MIDI-PC interface originaly designed to connect an expression pedal to a **PC** or an **iPad** using USB.

## Current version

**Version 1.0**

## Licensing

The design and source codes are provided freely under a closed licence. It makes you able to implement the whole project for your own usage but not to sell it.

If you want to use it in a commercial project please contact me at tristan.israel@tibsys.com.

## IMPORTANT: USB device PID and VID

The current values for PID and VID are random values (PID=0x2340, VID=Ox8030). They are not registered with USB-FI. You may override these values but your are not allowed to sell a product using these ID.

## Cost

_Prices include VAT 20%_

| Part              | Unit (€) | Qty | Sub-total (€) |
|-------------------|----------|-----|---------------|
| M-AUDIO EX-P      | 16.00    | 1   | 16.00         |
| ATmega 32u4       | 4.00     | 1   | 4.00          |
| USB cable (1)     | 2.60     | 1   | 2.60          |
| USB connector (2) | 1.70     | 1   | 1.70          |
| Small parts       | 0.50     | -   | 0.50          |
|-------------------|----------|-----|---------------|
| Total             | 24.80    | 1   | 24.80         |

(1): Bare USB cable
(2): USB Micro B connector

If you dont' want to do it yourself, please contact me at tristan.israel@tibsys.com.

## Requirements

- provide PC connectivity to an expression with a Jack connector
- ensure compatibility with all DAWs and MIDI controllers

## Presentation

The project consists in an electronic device which is responsible of converting the pedal into a MIDI device. 

## Licenses and credits

- Arduino schemas made with [Fritzing](http://fritzing.org/).
- Configuration software made with Qt 5.12.0 community edition.

# Do It Yourself

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

> Before mounting the pedal you'll have to flash the Arduino program. (See Arduino folder). 

If you want the device to have a more friendly name than *Arduino Leonardo*, install the board description files into Arduino IDE (see support folder) and use the *MIDI Expression pedal* board instead of *Arduino Leonardo*.

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
