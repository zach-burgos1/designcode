#ifndef DEFINITIONS_H
#define DEFINITIONS_H

// STEPPERS
const int STEPS_PER_REV = 400; 
const int SPEED_HOR = 60; 
const int SPEED_VERT = 120; // IDEK
const int SPEED_CASE = 120; 

const int HOR_DELAY = 1000; 
const int VERT_DELAY = 2000; 
const int CASE_DELAY = 1000;

// LINEAR ACTUATORS
const int LINACT_DELAY = 1000; 

// PINS
// MOTORS PINS
//Horizontal 
const int PIN_L1_EN1 = 2;
const int PIN_L1_EN2 = 7;
const int PIN_L1_IN1 = 3;
const int PIN_L1_IN2 = 4;
const int PIN_L1_IN3 = 5;
const int PIN_L1_IN4 = 6;

//Vertical 
const int PIN_L2_EN1 = 9;
const int PIN_L2_EN2 = 10;
const int PIN_L2_IN1 = 33;
const int PIN_L2_IN2 = 35;
const int PIN_L2_IN3 = 37;
const int PIN_L2_IN4 = 39;

//Case
const int PIN_L3_EN1 = 43;
const int PIN_L3_EN2 = 53;
const int PIN_L3_IN1 = 45;
const int PIN_L3_IN2 = 47;
const int PIN_L3_IN3 = 49;
const int PIN_L3_IN4 = 51;

//Linear Actuator
const int PIN_L4_EN2 = 29;
const int PIN_L4_IN3 = 25;
const int PIN_L4_IN4 = 27;

//RELAY
const int PIN_RELAY = 11;

// BreakBeam
const int PIN_BB = 30;

//SERVO
const int SERVO_1 = 42;
const int SERVO_2 = 46;

// SENSOR

#endif // DEFINITIONS_H