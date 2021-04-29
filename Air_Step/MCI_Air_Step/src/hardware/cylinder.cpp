/*
    MCI_Air_Step - An OverEngineered Controller for the pneumatic retractable step on an MCI bus
    converted to a motorhome.

    cylinder.cpp - This is the source file for cylinder.h.

    Author - Written by Jadon Miller in April 2021.

    License - The UnLicense - Feel free to use or modify this code however you find useful!

    ChangeLog - (Date - Name - Description)
    4/24/2021 - Jadon Miller - Initial Work
*/

#include "cylinder.h"

// Constructor: Sets global configuration variables,
cylinder::cylinder(int pin, bool invert)
{
    Pin = pin;
    Invert = invert;
    Extended = false;
}

// Init: Configures IO.
void cylinder::init()
{
    pinMode(Pin, OUTPUT);
    if (Invert) {
        digitalWrite(Pin, HIGH); //set pin automatically on if inverted
    }
}

// Extend: Extends cylinder.
void cylinder::extend()
{
    digitalWrite(Pin, !Invert);
    Extended = true;
}

// Retract: Retracts cylinder.
void cylinder::retract()
{
    digitalWrite(Pin, Invert);
    Extended = false;
}

// Move: Retracts or Extends cylinder.
void cylinder::move(motionType motion)
{
    if (motion == motionExtend) {
        extend();
    } else {
        retract();
    }
}

// Extended: Returns true if the cylinder is extended.
bool cylinder::extended()
{
    return Extended;
}