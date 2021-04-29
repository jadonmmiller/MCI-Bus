/*
    MCI_Air_Step - An OverEngineered Controller for the pneumatic retractable step on an MCI bus
    converted to a motorhome.

    output.h - This file abstracts a general output.

    Author - Written by Jadon Miller in April 2021.

    License - The UnLicense - Feel free to use or modify this code however you find useful!

    ChangeLog - (Date - Name - Description)
    4/24/2021 - Jadon Miller - Initial Work
*/

#ifndef OUTPUT_H
#define OUTPUT_H

#include <Arduino.h>
#include "enums.h"

class output {
public:
    output(int, bool);
    void setParam(int, bool);
    void init();
    void turnOn();
    void turnOff();
    void set(switchState);
    bool on();

private:
    int Pin;
    int Invert;
    bool On;
};

#endif