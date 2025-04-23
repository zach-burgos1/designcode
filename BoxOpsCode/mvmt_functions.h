#ifndef MVMT_FUNCTIONS_H
#define MVMT_FUNCTIONS_H

#include "definitions.h"
#include <Stepper.h>
#include <Servo.h>


void retractLinAct();
void extendLinAct();

void gantryUp(); 
void gantryDown();

void clawOpen(); 
void clawClose(); 

void caseExport(); 
void caseImport(); 

#endif // MVMT_FUNCTIONS_H