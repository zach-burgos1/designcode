
/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe

 */

#include <Stepper.h>
const int PIN_L1_IN1 =  8;
const int PIN_L1_IN2 =  9;
const int PIN_L1_IN3 = 10;
const int PIN_L1_IN4 = 11;


const int stepsPerRevolution = 400;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, PIN_L1_IN1, PIN_L1_IN2, PIN_L1_IN3, PIN_L1_IN4);

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(120);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(8*stepsPerRevolution); 
  delay(5000);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-8*stepsPerRevolution);
  delay(5000);
}

