/*
    MCI_Air_Step - An OverEngineered Controller for the pneumatic retractable step on an MCI bus
    converted to a motorhome.

    config.h - This file includes the majority of the complier macros and includes and is meant to
    be included at the top of other source code files.

    Author - Written by Jadon Miller in April 2021.

    License - The UnLicense - Feel free to use or modify this code however you find useful!

    ChangeLog - (Date - Name - Description)
    4/24/2021 - Jadon Miller - Initial Work
*/

#ifndef CONFIG_H
#define CONFIG_H

// Switch Actions: These set the operation of the up/down switches. Use mode values
// from resources.h. (modeAuto, modeExtendAuto, modeRetractAuto, modeExtendHold,
// modeRetractHold)
#define SWITCHUPACTION modeExtendAuto
#define SWITCHDOWNACTION modeRetractAuto
#define SWITCHHOLDUPACTION modeExtendHold
#define SWITCHHOLDDOWNACTION modeRetractHold

// Switch Timing: These set the delays that control switch operation.
#define SWITCHDEBOUNCEDELAY 100
#define SWITCHHOLDDELAY 1000
#define DOORSWITCHDEBOUNCEDELAY 500

// Step Timing: These delays control the step operation
#define STEPMOVEDELAY 2000
#define LOCKMOVEDELAY 500

// Pin Assignments: Set the IO pins here.
#define PINPBRAKEINPUT 3
#define PINPRESSINPUT 4
#define PINDOORINPUT 5
#define PINEXUPINPUT 6
#define PINEXDOWNINPUT 7
#define PININUPINPUT 8
#define PININDOWNINPUT 9

#define PINLOCKOUTPUT 10
#define PINSTEPOUTPUT 11
#define PINLIGHTOUTPUT 12
#define PINSPAREOUTPUT 13

#endif