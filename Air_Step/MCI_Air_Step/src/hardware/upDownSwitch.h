/*
    MCI_Air_Step - An OverEngineered Controller for the pneumatic retractable step on an MCI bus
    converted to a motorhome.

    upDownSwitch.h - This file contains the upDownSwitch class, which abstracts switch operation.

    Author - Written by Jadon Miller in April 2021.

    License - The UnLicense - Feel free to use or modify this code however you find useful!

    ChangeLog - (Date - Name - Description)
    4/24/2021 - Jadon Miller - Initial Work
*/

#ifndef UPDOWNSWITCH_H
#define UPDOWNSWITCH_H

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include "enums.h"

// Class upDownSwitch: Abstracts the switch control.
class upDownSwitch {
public:
    upDownSwitch(int, int, mode*, mode, mode, mode, mode, int, int);
    void init();
    void spin();

private:
    enum switchPosition {
        positionMiddle = 0,
        positionUp = 1,
        positionDown = 2
    };

    switchPosition readPosition();

    //configureation variables
    int UpPin;
    int DownPin;
    mode* OutputMode;
    mode UpAction;
    mode DownAction;
    mode HoldUpAction;
    mode HoldDownAction;
    int DebounceDelay;
    int HoldDelay;

    //used for debouncing
    switchPosition LastPosition = positionMiddle;
};

#endif