/*
    MCI_Air_Step - An OverEngineered Controller for the pneumatic retractable step on an MCI bus
    converted to a motorhome.

    step.cpp - This is the source file for step.h.

    Author - Written by Jadon Miller in April 2021.

    License - The UnLicense - Feel free to use or modify this code however you find useful!

    ChangeLog - (Date - Name - Description)
    4/24/2021 - Jadon Miller - Initial Work
*/

#include "step.h"

// Constructor: Sets global variables.
step::step(cylinder* stepCylinder, cylinder* lockCylinder, int stepDelay, int lockDelay)
{
    StepCylinder = stepCylinder;
    LockCylinder = lockCylinder;
    StepDelay = stepDelay;
    LockDelay = lockDelay;
    Extended = false;
}

// Init: Starts cylinder classes.
void step::init()
{
    StepCylinder->init();
    LockCylinder->init();
}

// Extend: Extends the step.
void step::extend(bool lock)
{
    if (!Extended) {
        if (LockCylinder->extended()) {
            LockCylinder->retract();
            vTaskDelay(LockDelay / portTICK_PERIOD_MS);
        }
        StepCylinder->extend();
        vTaskDelay(StepDelay / portTICK_PERIOD_MS);
        if (lock) {
            LockCylinder->extend();
        }
        Extended = true;
    }
}

// Retract: Retracts the step.
void step::retract(bool lock)
{
    if (Extended) {
        if (LockCylinder->extended()) {
            LockCylinder->retract();
            vTaskDelay(LockDelay / portTICK_PERIOD_MS);
        }
        StepCylinder->retract();
        vTaskDelay(StepDelay / portTICK_PERIOD_MS);
        if (lock) {
            LockCylinder->extend();
        }
        Extended = false;
    }
}

// Move: Extends or retracts the step.
void step::move(motionType motion, bool lock)
{
    if (motion == motionExtend) {
        extend(lock);
    } else {
        retract(lock);
    }
}

// Extended: Returns true if the step is extended.
bool step::extended()
{
    return Extended;
}