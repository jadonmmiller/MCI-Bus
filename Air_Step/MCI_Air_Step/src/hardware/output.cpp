/*
    MCI_Air_Step - An OverEngineered Controller for the pneumatic retractable step on an MCI bus
    converted to a motorhome.

    output.cpp - This is the source file for output.h

    Author - Written by Jadon Miller in April 2021.

    License - The UnLicense - Feel free to use or modify this code however you find useful!

    ChangeLog - (Date - Name - Description)
    4/24/2021 - Jadon Miller - Initial Work
*/

#include "output.h"

// Constructor: Sets the global variables.
output::output(int pin, bool invert)
{
    Pin = pin;
    Invert = invert;
    On = false;
}

// Init: Configures the IO.
void output::init()
{
    pinMode(Pin, OUTPUT);

    //automatically turn off if the output is inverted
    if (Invert) {
        digitalWrite(Pin, HIGH);
    }
}

// Turn On: Sets the output on.
void output::turnOn()
{
    digitalWrite(Pin, !Invert);
    On = true;
}

// Turn Off: Sets the output off.
void output::turnOff()
{
    digitalWrite(Pin, Invert);
    On = false;
}

// Set: Sets the output to the state specified.
void output::set(switchState state)
{
    if (state == stateOn) {
        turnOn();
    } else {
        turnOff();
    }
}

// On: Returns true if the output is on.
bool output::on()
{
    return On;
}
