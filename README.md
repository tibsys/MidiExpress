# MidiExpress

MIDIExpress is a MIDI-PC interface originaly designed to connect an expression pedal with only Jack connector to a PC.

Eventually, we decided to create 3 devices:
- a USB-MIDI expression pedal which can be directly connected to a PC.
- a Jack-USB device which is able to connect a Jack pedal to a PC.
- a Jack-DIN device which is able to connect a Jack pedal to a MIDI controller.

## Current status

The project is currently under design. The proof-of-concept has been realized and we are now designing the first device (USB-MIDI expression pedal).

- USB-MIDI expression pedal: under development
- Jack-USB: not started
- Jack-DIN: not started

Status updated on 2019-04-15.

## Licensing

The design and source codes are provided freely under a closed licence. It makes you able to implement the whole project for your own usage but not to sell it.
If you want to use it in a commercial project please contact me at tristan.israel@tibsys.com.

## IMPORTANT: USB device PID and VID

The current values for PID and VID are random values (PID=0x2340, VID=Ox8030). They are not registered with USB-FI. You may override these values but your are not allowed to sell a product using these ID.

## Cost

Estimated cost of each device is detailed in [this page](costs.md). 

You can buy prebuilt devices by sending an email to tristan.israel@tibsys.com.

## Requirements

- provide PC connectivity to an expression with a Jack connector
- ensure compatibility with all DAWs and MIDI controllers
- provide firmware update capabilities (using USB)

## Presentation

The project consists in an electronic device which is responsible of converting the pedal into a MIDI device. 

### USB-MIDI expression pedal

[See README.md for this sub-project](USB_MIDI/README.md)

### Jack-USB connector

_The design is not fixed yet_

[See README.md for this sub-project](JACK_USB/README.md)

### Jack-DIN connector

[See README.md for this sub-project](JACK_DIN/README.md)

## Software design

### Firmware

More details to come.

### Upgrade software

This software is coded in C++-11 with Qt5. It is designed to make some configuration in the Arduino board in order to change or fine-tune its behaviour.

### Configuration software

This software is coded in C++-11 with JUCE and can be used as a standalone application or a VST/AU plugin so you can record different settings in your patches.

## Dependencies

Here comes the list of dependencies for this project.

## Licenses and credits

- Arduino schemas made with [Fritzing](http://fritzing.org/).
- Configuration software made with Qt 5.12.0 community edition.
- Graphics:
    - *to be completed*
