/*
    MCI_Air_Step - An OverEngineered Controller for the pneumatic retractable step on an MCI bus
    converted to a motorhome.

    upDownSwitch.cpp - The source file for upDownSwitch.h.

    Author - Written by Jadon Miller in April 2021.

    License - The UnLicense - Feel free to use or modify this code however you find useful!

    ChangeLog - (Date - Name - Description)
    4/24/2021 - Jadon Miller - Initial Work
*/

#include "upDownSwitch.h"

// Constructor: Sets global configuration variables.
upDownSwitch::upDownSwitch(const int upPin, const int downPin, mode* outputMode,
    mode upAction, mode downAction, mode holdUpAction,
    mode holdDownAction, int debounceDelay, int holdDelay)
{
    UpPin = upPin;
    DownPin = downPin;
    OutputMode = outputMode;
    UpAction = upAction;
    DownAction = downAction;
    HoldUpAction = holdUpAction;
    HoldDownAction = holdDownAction;
    DebounceDelay = debounceDelay;
    HoldDelay = holdDelay;
}

// Init: Configures IO.
void upDownSwitch::init()
{
    pinMode(UpPin, INPUT);
    pinMode(DownPin, INPUT);
}

// Spin: Polls the switch; provides debouncing and hold detection.
void upDownSwitch::spin()
{
    //get the current switch position
    switchPosition position = readPosition();

    //if the position has changed - we ignore when the switch is released
    if (position != LastPosition && position != positionMiddle) {

        //wait a bit and read again for debouncing
        LastPosition = position;
        vTaskDelay(DebounceDelay / portTICK_PERIOD_MS);
        position = readPosition();
        if (position == LastPosition) {

            //we have a valid switch movement
            if (position == positionUp) {
                *OutputMode = UpAction;
            } else if (position == positionDown) {
                *OutputMode = DownAction;
            }

            //wait a bit and check for a hold command
            vTaskDelay(HoldDelay / portTICK_PERIOD_MS);
            position = readPosition();
            if (position == LastPosition) {

                //we have a hold command
                if (position == positionUp) {
                    *OutputMode = HoldUpAction;
                } else if (position == positionDown) {
                    *OutputMode = HoldDownAction;
                }
            }
        }
    }

    LastPosition = position;
}

// Read Position: Reads the switch inputs and provides a position variable.
upDownSwitch::switchPosition upDownSwitch::readPosition()
{
    bool switchUp = digitalRead(UpPin);
    bool switchDown = digitalRead(DownPin);
    switchPosition position;

    if (switchUp) {
        position = positionUp;
    } else if (switchDown) {
        position = positionDown;
    } else {
        position = positionMiddle;
    }

    return position;
}