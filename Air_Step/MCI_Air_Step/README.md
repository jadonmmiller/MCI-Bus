# MCI Air Step
This is an over-engineered Arduino-based controller for the pneumatic retractable step on our 1993 MCI bus custom-converted into a motorhome.

<br>

## Code
This is the source code for the Arduino. It runs on a Pro Mini, and although I don't have time to refactor it simply for the sake of better code, it is fully functional, and I will fix bugs as I find them.

The pin assignments and other frequently-changed settings are listed in the config.h file.

<br>

## Hardware
This runs on an Arduino Pro Mini soldered to a custom perfboard circuit. 

### Circuit Board
Seven inputs (Pins 2-9) run through a terminal block, are reduced from 24V to 5V by a voltage divider (1.1K and 5K Ohm Resistors), then fed into the Arduino. Four outputs (Pins 10-13) go directly to a 4-channel relay board. The entire system is powered by a buck converter set to 5V.

### Bus Circuitry
The circuit board is powered by 24V coming from the old plug and a ground lug. The inputs consist of a 24V parking brake signal from the plug, a GND signal from the door switch, as well as a pressure switch and two SPDT switches used as control inputs.

The relays get wired to two Automation Direct five-port solenoids (one for the step cylinder and one for the lock cylinder), as well as switching the wires for the "Step Out" indicator light signal on the dash.
