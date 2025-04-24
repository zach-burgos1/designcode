#ifndef MVMT_FUNCTIONS_H
#define MVMT_FUNCTIONS_H

#include "definitions.h"
#include <Stepper.h>
#include <Servo.h>

void conveyorBeltOn();
void conveyorBeltOff();

void retractLinAct();
void extendLinAct();

void gantryUp(); 
void gantryDown();

void caseForward();
void caseBackward();

void clawOpen(); 
void clawClose(); 

void caseExport(); 
void caseImport(); 

#endif // MVMT_FUNCTIONS_H