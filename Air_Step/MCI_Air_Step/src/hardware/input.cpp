/*
    MCI_Air_Step - An OverEngineered Controller for the pneumatic retractable step on an MCI bus
    converted to a motorhome.

    input.cpp - The source file for input.h.

    Author - Written by Jadon Miller in April 2021.

    License - The UnLicense - Feel free to use or modify this code however you find useful!

    ChangeLog - (Date - Name - Description)
    4/24/2021 - Jadon Miller - Initial Work
*/

#include "input.h"

// Constructor: Sets global variables.
input::input(int pin, bool invert, bool pullUp = false, int debounceDelay = 500)
{
    Pin = pin;
    Invert = invert;
    PullUp = pullUp;
    DebounceDelay = debounceDelay;
}

// Init: Configures IO.
void input::init()
{
    if (PullUp) {
        pinMode(Pin, INPUT_PULLUP);
    } else {
        pinMode(Pin, INPUT);
    }
}

// Tripped: Reads the switch and returns true if the switch is activated.
bool input::tripped()
{
    bool state;
    constexpr byte retrys = 5;
    int timeOut = 0;

    // take a reading, wait a bit, and loop until we get two the same
    do {
        state = digitalRead(Pin);
        vTaskDelay(DebounceDelay / portTICK_PERIOD_MS);
        timeOut++;
    } while (digitalRead(Pin) != state && timeOut <= retrys);

    if (Invert) {
        state = !state;
    }

    return state;
}