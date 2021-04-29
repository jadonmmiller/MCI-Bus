/*
    MCI_Air_Step - An OverEngineered Controller for the pneumatic retractable step on an MCI bus
    converted to a motorhome.

    step.h - This contains the step class, which abstracts the step control.

    Author - Written by Jadon Miller in April 2021.

    License - The UnLicense - Feel free to use or modify this code however you find useful!

    ChangeLog - (Date - Name - Description)
    4/24/2021 - Jadon Miller - Initial Work
*/

#ifndef STEP_H
#define STEP_H

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include "enums.h"
#include "cylinder.h"

class step {
public:
    step(cylinder*, cylinder*, int, int);
    void init();
    void extend(bool);
    void retract(bool);
    void move(motionType, bool);
    bool extended();

private:
    cylinder* StepCylinder;
    cylinder* LockCylinder;
    int StepDelay;
    int LockDelay;
    bool Extended;
};

#endif