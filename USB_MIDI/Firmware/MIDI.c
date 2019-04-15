/*
             LUFA Library
     Copyright (C) Dean Camera, 2015.

  dean [at] fourwalledcubicle [dot] com
           www.lufa-lib.org
*/

/*
  Copyright 2015  Dean Camera (dean [at] fourwalledcubicle [dot] com)

  Permission to use, copy, modify, distribute, and sell this
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.

  The author disclaims all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

//First shoot of the firmware
//Based on article: https://codeandlife.com/2017/09/17/5-usb-midi-adapter-with-atmega32u4/
//This code will be replaced with the firmware of the MIDI pedal

/** \file
 *
 *  Main source file for the MIDI demo. This file contains the main tasks of
 *  the demo and is responsible for the initial application hardware configuration.
 */

#include "MIDI.h"

/** LUFA MIDI Class driver interface configuration and state information. This structure is
 *  passed to all MIDI Class driver functions, so that multiple instances of the same class
 *  within a device can be differentiated from one another.
 */
USB_ClassInfo_MIDI_Device_t Keyboard_MIDI_Interface =
	{
		.Config =
			{
				.StreamingInterfaceNumber = INTERFACE_ID_AudioStream,
				.DataINEndpoint           =
					{
						.Address          = MIDI_STREAM_IN_EPADDR,
						.Size             = MIDI_STREAM_EPSIZE,
						.Banks            = 1,
					},
				.DataOUTEndpoint          =
					{
						.Address          = MIDI_STREAM_OUT_EPADDR,
						.Size             = MIDI_STREAM_EPSIZE,
						.Banks            = 1,
					},
			},
	};


#define BUTTON PD2
#define BUTTONPIN PIND
#define BUTTONPORT PORTD

int main() {
    uint16_t debounce = 0;
    uint8_t keydown = 0;

    /* Disable watchdog if enabled by bootloader/fuses */
    MCUSR &= ~_BV(WDRF);
    wdt_disable();

    /* Disable clock division */
    clock_prescale_set(clock_div_1);

    /* Hardware Initialization */
    LEDs_Init();
    USB_Init();
    BUTTONPORT |= _BV(BUTTON); // weak pullup

    LEDs_TurnOnLEDs(LEDS_LED1); // keep LED1 on until initialized
    GlobalInterruptEnable();

    while(1) {
        if(debounce) debounce--;
        else if(!(BUTTONPIN & _BV(BUTTON)) != keydown) { // button state change
            keydown = !keydown; // keydown to reflect current state
            LEDs_ToggleLEDs(LEDS_LED2);
            if(keydown)
                sendMIDI(MIDI_COMMAND_NOTE_ON, 1, 60, 50);
            else
                sendMIDI(MIDI_COMMAND_NOTE_OFF, 1, 60, 0);
            debounce = 10000;
        }


        MIDI_EventPacket_t ReceivedMIDIEvent;
        while(MIDI_Device_ReceiveEventPacket(&Keyboard_MIDI_Interface,
                    &ReceivedMIDIEvent)) {
            // Discard received events
        }

        MIDI_Device_USBTask(&Keyboard_MIDI_Interface);
        USB_USBTask();
    }
}

/** Checks for changes in the position of the board joystick, sending MIDI events to the host upon each change. */
void sendMIDI(uint8_t command, uint8_t channel, uint8_t data1, uint8_t data2) {
    MIDI_EventPacket_t event = (MIDI_EventPacket_t) {
        .Event       = MIDI_EVENT(0, command),
        .Data1       = command | channel,
        .Data2       = data1,
        .Data3       = data2,
    };

    MIDI_Device_SendEventPacket(&Keyboard_MIDI_Interface, &event);
    MIDI_Device_Flush(&Keyboard_MIDI_Interface);
}

/** Event handler for the library USB Connection event. */
void EVENT_USB_Device_Connect() {
	LEDs_TurnOffLEDs(LEDS_LED1);
}

/** Event handler for the library USB Disconnection event. */
void EVENT_USB_Device_Disconnect() {
	LEDs_TurnOnLEDs(LEDS_LED1); // keep LED1 on until initialized
}

/** Event handler for the library USB Configuration Changed event. */
void EVENT_USB_Device_ConfigurationChanged() {
	bool ConfigSuccess = true;

	ConfigSuccess &= MIDI_Device_ConfigureEndpoints(&Keyboard_MIDI_Interface);

    if(!ConfigSuccess) LEDs_TurnOnLEDs(LEDS_LED1);
}

/** Event handler for the library USB Control Request reception event. */
void EVENT_USB_Device_ControlRequest() {
	MIDI_Device_ProcessControlRequest(&Keyboard_MIDI_Interface);
}

