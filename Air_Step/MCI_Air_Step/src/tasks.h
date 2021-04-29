/*
    MCI_Air_Step - An OverEngineered Controller for the pneumatic retractable step on an MCI bus
    converted to a motorhome.

    tasks.h - This file contains the program kernal.

    Author - Written by Jadon Miller in April 2021.

    License - The UnLicense - Feel free to use or modify this code however you find useful!

    ChangeLog - (Date - Name - Description)
    4/24/2021 - Jadon Miller - Initial Work
*/

#ifndef TASKS_H
#define TASKS_H

#include <Arduino_FreeRTOS.h>
#include "config.h"
#include "hardware/input.h"
#include "hardware/output.h"
#include "hardware/upDownSwitch.h"
#include "hardware/step.h"

//declare the external variables
extern mode ProgramMode;
extern bool DoorExtendFlag;
extern bool DoorRetractFlag;
extern upDownSwitch ExternalSwitch;
extern upDownSwitch InternalSwitch;
extern input PressSwitch;
extern input PBrakeSwitch;
extern input DoorSwitch;
extern step StepOutput;
extern output StepLamp;

// Class RTOS: Controls the RTOS of the program.
class RTOS {
public:
    void start();
};

//RTOS Tasks: The definitions are in tasks.cpp
void switchesTask(void* pvParameters);
void coordinatorTask(void* pvParameters);
void serialTask(void* pvParameters);

#endif