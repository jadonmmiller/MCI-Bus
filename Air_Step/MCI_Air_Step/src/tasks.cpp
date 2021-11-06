/*
    MCI_Air_Step - An OverEngineered Controller for the pneumatic retractable step on an MCI bus
    converted to a motorhome.

    tasks.cpp - The source file for tasks.h

    Author - Written by Jadon Miller in April 2021.

    License - The UnLicense - Feel free to use or modify this code however you find useful!

    ChangeLog - (Date - Name - Description)
    4/24/2021 - Jadon Miller - Initial Work
*/

#include "tasks.h"

//declare the supporting functions
void stepLogic();
void stepLampLogic();
void printMode();
void printStatuses();

// Start: This hand the program control over to the kernal, starting the tasks.
void RTOS::start()
{
    xTaskCreate(switchesTask, "Switches", 128, NULL, 5, NULL);
    xTaskCreate(coordinatorTask, "Coordinator", 128, NULL, 4, NULL);
    xTaskCreate(serialTask, "Serial", 128, NULL, 3, NULL);
}

// SwitchesTask: This polls the up/down switch logic.
void switchesTask(void* pvParameters)
{
    (void)pvParameters;
    while (1) {

        InternalSwitch.spin();
        ExternalSwitch.spin();
    }
}

// CoordinatorTask: This is the main task that calls the step logic.
void coordinatorTask(void* pvParameters)
{
    (void)pvParameters;
    while (1) {

        stepLogic();
        stepLampLogic();
    }
}

// SerialTask: This periodically sends a Serial status update.
void serialTask(void* pvParameters)
{
    (void)pvParameters;
    while (1) {

        Serial.println("----- MCI Air Step -----");
        printMode();
        printStatuses();
        Serial.println();
        Serial.println();
        vTaskDelay(250 / portTICK_PERIOD_MS);
    }
}

// StepLogic: This is the conditional logic that runs the step.
void stepLogic()
{
    //We don't do anything unless there's air pressure
    if (PressSwitch.tripped()) {

        switch (ProgramMode) {

            //in auto mode, we extend if the door is open and retract when it's closed
        case modeAuto:
            //reset door flags from other modes
            DoorExtendFlag = false;
            DoorRetractFlag = false;

            if (DoorSwitch.tripped()) {
                StepOutput.extend(true);
            } else {
                StepOutput.retract(true);
            }
            break;

            //in extend auto mode, we extend the step and return to auto mode when the door is closed
        case modeExtendAuto:
            //reset flags from other modes
            DoorRetractFlag = false;

            //this retracts the step when the parking brake goes off
            if (PBrakeSwitch.tripped()) {
                StepOutput.extend(true);
            } else {
                StepOutput.retract(true);
            }

            //if the door is opened, we set the flag
            if (DoorSwitch.tripped()) {
                DoorExtendFlag = true;

                //if the door is shut, we reset to the auto mode
            } else {
                if (DoorExtendFlag) {
                    ProgramMode = modeAuto;
                    DoorExtendFlag = false;
                }
            }
            break;

            //in retract auto mode, we retract the step and return to auto mode when the door is opened
        case modeRetractAuto:
            // reset door flags from other modes
            DoorExtendFlag = false;

            StepOutput.retract(true);

            //if the door is shut, we set the flag
            if (!DoorSwitch.tripped()) {
                DoorRetractFlag = true;

                //if the door is opened, we wait a bit to debounce, then reset to the auto mode
            } else {
                if (DoorRetractFlag) {
                    ProgramMode = modeAuto;
                    DoorRetractFlag = false;
                }
            }
            break;

            //in extend hold mode, the step always stays out unless the parking brake is off.
        case modeExtendHold:
            //reset door flags from other modes
            DoorExtendFlag = false;
            DoorRetractFlag = false;

            if (PBrakeSwitch.tripped()) {
                StepOutput.extend(true);
            } else {
                //extend the step if the door is open while the parking brake is off
                if (DoorSwitch.tripped()) {
                    StepOutput.extend(true);
                } else {
                    StepOutput.retract(true);
                }
            }
            break;

            //in retract hold mode, the step always stays in.
        case modeRetractHold:
            //reset door flags from other modes
            DoorExtendFlag = false;
            DoorRetractFlag = false;

            StepOutput.retract(true);
            break;
        }
    }
}

// stepLampLogic: This sets the step lamp to match the step.
void stepLampLogic()
{
    if (StepOutput.extended()) {
        StepLamp.turnOn();
    } else {
        StepLamp.turnOff();
    }
}

// PrintMode: Prints a human-readable version of the current mode.
void printMode()
{
    Serial.print("Current Mode: ");
    switch (ProgramMode) {
    case modeAuto:
        Serial.println("Auto");
        break;
    case modeExtendAuto:
        Serial.println("Auto - Temporarily Extended");
        break;
    case modeRetractAuto:
        Serial.println("Auto - Temporarily Retracted");
        break;
    case modeExtendHold:
        Serial.println("Hold Extended");
        break;
    case modeRetractHold:
        Serial.println("Hold Retracted");
        break;
    }
}

// Print Statuses: Prints the status of the IO.
void printStatuses()
{
    Serial.print("Door: ");
    Serial.println(DoorSwitch.tripped() ? "Opened" : "Closed");
    Serial.print("Pressure Switch: ");
    Serial.println(PressSwitch.tripped() ? "Pressurized" : "Depressurized");
    Serial.print("Parking Brake: ");
    Serial.println(PBrakeSwitch.tripped() ? "On" : "Off");
    Serial.print("Step: ");
    Serial.println(StepOutput.extended() ? "Extended" : "Retracted");
    Serial.print("Tell-Tale Light: ");
    Serial.println(StepLamp.on() ? "On" : "Off");
}