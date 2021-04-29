/*
    MCI_Air_Step - An OverEngineered Controller for the pneumatic retractable step on an MCI bus
    converted to a motorhome.

    enums.h - This file defines the global enums for the program.

    Author - Written by Jadon Miller in April 2021.

    License - The UnLicense - Feel free to use or modify this code however you find useful!

    ChangeLog - (Date - Name - Description)
    4/24/2021 - Jadon Miller - Initial Work
*/

#ifndef ENUMS_H
#define ENUMS_H

// Mode Enum: This states the current mode of the step controller.
// modeAuto - Automatically extend and retract based on the door.
// modeExtendAuto - Temporarily extend, but stay in auto mode.
// modeRetractAuto - Temporarily retract, but stay in auto mode.
// modeExtendHold - Keep the step extended except for the parking brake.
// modeRetractHold - Keep the step retracted except for the parking brake.
enum mode {
    modeAuto = 0,
    modeExtendAuto = 1,
    modeRetractAuto = 2,
    modeExtendHold = 3,
    modeRetractHold = 4
};

// MotionType Enum: This is used throughout the code for "move" functions.
// motionRetract: Denotes a retract motion.
// motionExtend: Denotes an extend motion.
enum motionType {
    motionRetract = 0,
    motionExtend = 1
};

// SwitchType Enum: Enumerates on and off.
// switchOff: Off.
// switchOn: On.
enum switchState {
    stateOff = 0,
    stateOn = 1
};

#endif