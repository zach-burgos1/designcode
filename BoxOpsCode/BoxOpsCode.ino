#include "definitions.h"
#include "init_functions.h"
#include "mvmt_functions.h"

// SENSOR
int count = 0;
int sensorState = 0;
int lastState = 0;
bool action = false; 

void setup() {
  // Setup Steppers & Linear Actuator
  initL298NS(); 

  // Setup Relay
  initRelay(); 

  // Setup Breakbeam
  initBB();

  initServos(); 

  // Enable the Case Driver
  digitalWrite(PIN_L3_EN1, HIGH); 
  digitalWrite(PIN_L3_EN2, HIGH); 

  pinMode(PIN_RELAY, OUTPUT);
  digitalWrite(PIN_RELAY, LOW);

  Serial.begin(9600);  

  // Initialize timer
  stateStart = millis();
}

void loop() {
  // RELAY
  sensorState = digitalRead(PIN_BB);
  if (!sensorState && lastState){
    count++; //Counts Products
  }
  lastState = sensorState;
  if (count == 2 && !action) {
    delay(1000);
   digitalWrite(PIN_RELAY, LOW);
   delay(1000);
   extendLinAct();
   retractLinAct();
   digitalWrite(PIN_RELAY, HIGH);
   action = true;  //allows the LA to only work once while waiting for next product to load
  }
  if (count == 4){ //Grabs Products before the LA and resets basically every four.
    delay(1000);
    clawClose(); 
  //  Go Up
    count = 0;
    action = false;
  }



  // SERVO
  // servo1.write(90); 
  // servo2.write(90);
  // delay(1000);
}

