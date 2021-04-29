/*
    MCI_Air_Step - An OverEngineered Controller for the pneumatic retractable step on an MCI bus
    converted to a motorhome.

    cylinder.h - This file contains the cylinder class, which abstracts the control of an air
    cylinder solenoid valve.

    Author - Written by Jadon Miller in April 2021.

    License - The UnLicense - Feel free to use or modify this code however you find useful!

    ChangeLog - (Date - Name - Description)
    4/24/2021 - Jadon Miller - Initial Work
*/

#ifndef CYLINDER_H
#define CYLINDER_H

#include <Arduino.h>
#include "enums.h"
#include "output.h"

class cylinder {
public:
    cylinder(int, bool);
    void init();
    void extend();
    void retract();
    void move(motionType);
    bool extended();

private:
    int Pin;
    bool Invert;
    bool Extended;
};

#endif