#ifndef INIT_FUNCTIONS_H
#define INIT_FUNCTIONS_H

#include "definitions.h"
#include <Stepper.h>
#include <Servo.h>

Stepper stepGantryH(STEPS_PER_REV, PIN_L1_IN1, PIN_L1_IN2, PIN_L1_IN3, PIN_L1_IN4); 
Stepper stepGantryV(STEPS_PER_REV, PIN_L2_IN1, PIN_L2_IN2, PIN_L2_IN3, PIN_L2_IN4);
Stepper stepCase(STEPS_PER_REV, PIN_L3_IN1, PIN_L3_IN2, PIN_L3_IN3, PIN_L3_IN4); 

Servo servo1; 
Servo servo2; 

void initL298NS();
void initRelay();
void initBB();



#endif // L298N_FUNCTIONS_H