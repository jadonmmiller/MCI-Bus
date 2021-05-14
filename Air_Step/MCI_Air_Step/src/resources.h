/*
    MCI_Air_Step - An OverEngineered Controller for the pneumatic retractable step on an MCI bus
    converted to a motorhome.

    resources.h - This file contains the class instances and global variables.

    Author - Written by Jadon Miller in April 2021.

    License - The UnLicense - Feel free to use or modify this code however you find useful!

    ChangeLog - (Date - Name - Description)
    4/24/2021 - Jadon Miller - Initial Work
*/

#ifndef RESOURCES_H
#define RESOURCES_H

#include "config.h"
#include "hardware/input.h"
#include "hardware/output.h"
#include "hardware/upDownSwitch.h"
#include "hardware/cylinder.h"
#include "hardware/step.h"
#include "tasks.h"

// Global Variables
mode ProgramMode = modeExtendHold;

// Class Instances
upDownSwitch ExternalSwitch(PINEXUPINPUT, PINEXDOWNINPUT, &ProgramMode, SWITCHUPACTION,
    SWITCHDOWNACTION, SWITCHHOLDUPACTION, SWITCHHOLDDOWNACTION, SWITCHDEBOUNCEDELAY, SWITCHHOLDDELAY);
upDownSwitch InternalSwitch(PININUPINPUT, PININDOWNINPUT, &ProgramMode, SWITCHUPACTION,
    SWITCHDOWNACTION, SWITCHHOLDUPACTION, SWITCHHOLDDOWNACTION, SWITCHDEBOUNCEDELAY, SWITCHHOLDDELAY);

//pressure switch returns true if pressure is present
input PressSwitch(PINPRESSINPUT, false, false, INPUTDEBOUNCEDELAY);

//parking brake returns true if brake on
input PBrakeSwitch(PINPBRAKEINPUT, true, false, INPUTDEBOUNCEDELAY);

//door switch returns true if opened
input DoorSwitch(PINDOORINPUT, true, false, INPUTDEBOUNCEDELAY);

cylinder StepCylinder(PINSTEPOUTPUT, false);
cylinder LockCylinder(PINLOCKOUTPUT, false);

step StepOutput(&StepCylinder, &LockCylinder, STEPMOVEDELAY, LOCKMOVEDELAY);

output StepLamp(PINLIGHTOUTPUT, true);

//this spare output is set as inverted to keep the relay off
output SpareOutput(PINSPAREOUTPUT, true);

RTOS kernal;
bool DoorExtendFlag = false;
bool DoorRetractFlag = false;

#endif