
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
// const int PIN_L1_IN1 =  47;
// const int PIN_L1_IN2 =  49;
// const int PIN_L1_IN3 =  51;
// const int PIN_L1_IN4 =  53;

const int PIN_L1_ENA = 9; 
const int PIN_L1_ENB = 10; 
const int PIN_L1_IN1 =  33;
const int PIN_L1_IN2 =  35;
const int PIN_L1_IN3 =  37;
const int PIN_L1_IN4 =  39;

//Vertical 
const int PIN_L2_EN1 = 9;
const int PIN_L2_EN2 = 10;
const int PIN_L2_IN1 = 33;
const int PIN_L2_IN2 = 35;
const int PIN_L2_IN3 = 37;
const int PIN_L2_IN4 = 39;


const int stepsPerRevolution = 400;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, PIN_L1_IN1, PIN_L1_IN2, PIN_L1_IN3, PIN_L1_IN4);

void setup() {
  // set the speed at 60 rpm: 
  // tested at 120
  //myStepper.setSpeed(120); // for case rail
  // 60 for belt???
  myStepper.setSpeed(120); // for belt!!!
  // initialize the serial port:
  Serial.begin(9600);

  pinMode(PIN_L1_ENA, OUTPUT);     
  digitalWrite(PIN_L1_ENA, HIGH); // turn on the pullup
  pinMode(PIN_L1_ENB, OUTPUT);     
  digitalWrite(PIN_L1_ENB, HIGH); // turn on the pullup

}

void loop() {
  // step one revolution  in one direction:
  Serial.println("clockwise"); // moves the belt away from stepper

  //myStepper.step(16*stepsPerRevolution);  case rail
  myStepper.step(2*stepsPerRevolution); // belt
  delay(1000);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  // myStepper.step(-16*stepsPerRevolution); case rail
  myStepper.step(-2*stepsPerRevolution);  // belt


  delay(1000);
}

