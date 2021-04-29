/*
    MCI_Air_Step - An OverEngineered Controller for the pneumatic retractable step on an MCI bus
    converted to a motorhome.

    input.h - Contains the input class. Abstracts the switchs.

    Author - Written by Jadon Miller in April 2021.

    License - The UnLicense - Feel free to use or modify this code however you find useful!

    ChangeLog - (Date - Name - Description)
    4/24/2021 - Jadon Miller - Initial Work
*/

#ifndef INPUT_H
#define INPUT_H

#include <Arduino.h>

class input {
public:
    input(int, bool, bool);
    void init();
    bool tripped();

private:
    int Pin;
    bool Invert;
    bool PullUp;
};

#endif