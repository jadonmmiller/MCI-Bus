/*
    MCI_Air_Step - An OverEngineered Controller for the pneumatic retractable step on an MCI bus
    converted to a motorhome.

    main.cpp - The main program file

    Author - Written by Jadon Miller in April 2021.

    License - The UnLicense - Feel free to use or modify this code however you find useful!

    ChangeLog - (Date - Name - Description)
    4/24/2021 - Jadon Miller - Initial Work
*/

#include "config.h"
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include "enums.h"
#include "hardware/input.h"
#include "hardware/output.h"
#include "hardware/upDownSwitch.h"
#include "hardware/cylinder.h"
#include "hardware/step.h"
#include "tasks.h"
#include "resources.h"

// Setup: We initialize everything and hand control over to the RTOS.
void setup() {

    Serial.begin(9600);

    PressSwitch.init();
    PBrakeSwitch.init();
    DoorSwitch.init();
    StepOutput.init();
    StepLamp.init();
    SpareOutput.init();
    kernal.start();
}

void loop() {

}