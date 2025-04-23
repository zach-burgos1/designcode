#include "definitions.h"
#include "init_functions.h"
#include "mvmt_functions.h"

enum CaseState {
  DO_FORWARD,
  WAIT_FORWARD,
  DO_BACK,
  WAIT_BACK
};

CaseState caseState = DO_FORWARD;
unsigned long stateStart = 0;

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

  // initServos(); 

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
  
  // extendLinAct(); 
  // retractLinAct(); 
  unsigned long now = millis();

  switch (caseState) {
    case DO_FORWARD:
      // Do the 2-rev forward move
      stepCase.step(2 * STEPS_PER_REV);
      // Transition to waiting
      stateStart = now;
      caseState  = WAIT_FORWARD;
      break;



    case WAIT_FORWARD:
      // After CASE_DELAY has elapsed, go do the reverse
      if (now - stateStart >= CASE_DELAY) {
        caseState  = DO_BACK;
      }
      break;

    case DO_BACK:
      // Do the 2-rev back move
      stepCase.step(-2 * STEPS_PER_REV);
      // Transition to waiting
      stateStart = now;
      caseState  = WAIT_BACK;
      break;

    case WAIT_BACK:
      // After CASE_DELAY has elapsed, loop back to forward
      if (now - stateStart >= CASE_DELAY) {
        caseState = DO_FORWARD;
      }
      break;
  }

  // — You can insert other non-blocking tasks here —

    // GANTRY VERTICAL  
  // delay(1000); 
  // digitalWrite(PIN_L2_EN1, HIGH);
  // digitalWrite(PIN_L2_EN2, HIGH);
  // delay(1000); 
  // stepGantryV.step(-1*STEPS_PER_REV);
  // delay(VERT_DELAY); 
  // //digitalWrite(PIN_L2_EN1, LOW);
  // //digitalWrite(PIN_L2_EN2, LOW);
  // delay(1000);
  // //digitalWrite(PIN_L2_EN1, HIGH);
  // //digitalWrite(PIN_L2_EN2, HIGH);
  // stepGantryV.step(1*STEPS_PER_REV);
  // delay(VERT_DELAY); 
  // delay(1000); 
  // //digitalWrite(PIN_L2_EN1, LOW);
  // //digitalWrite(PIN_L2_EN2, LOW);
  // delay(1000); 
/*
  // CASE RAIL
   digitalWrite(PIN_L3_EN1, HIGH); 
   digitalWrite(PIN_L3_EN2, HIGH); 
  //stepCase.step(2*STEPS_PER_REV);
  delay(1000);
  for (int i = 0; i < 200; i++){
    caseBackwards();
    delay(5);
  }
  digitalWrite(PIN_L3_EN1, LOW);
  digitalWrite(PIN_L3_EN2, LOW);
  // Serial.println("clockwise");
  //for(int i = 0; i < 100; i++){
  //  delay(i*2981); 
  //} 
  //delay(CASE_DELAY); 
*/
  //stepCase.step(-2*STEPS_PER_REV);
  //Serial.println("counterclockwise");
  //delay(CASE_DELAY); 
  // digitalWrite(PIN_L3_EN1, LOW); 
  // digitalWrite(PIN_L3_EN2, LOW); 
/*
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
    servo1.writeMicroseconds(1850);
    servo2.writeMicroseconds(475);
  //  Go Up
    count = 0;
    action = false;
  }
*/
  // // SERVO
  servo1.write(90); 
  servo2.write(90);
  delay(1000);
}

