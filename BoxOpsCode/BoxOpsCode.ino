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
  clawOpen(); 
  retractLinAct();
  // clawClose(); 
  // retractLinAct(); 
  // return; 

  // Enable the Case Driver
  // digitalWrite(PIN_L3_EN1, HIGH); 
  // digitalWrite(PIN_L3_EN2, HIGH); 

  // pinMode(PIN_RELAY, OUTPUT);
  // digitalWrite(PIN_RELAY, HIGH);

  Serial.begin(9600);  

  // Initialize timer
//  stateStart = millis();
}

void loop() {
  // partExtLinAct(); 
  // delay(5000);
  // gantryUp();
  // delay(2000);
  // gantryDown();
  // delay(2000);
  // return;

  conveyorBeltOn();
  // RELAY
  sensorState = digitalRead(PIN_BB);
  if (!sensorState && lastState){
    count++; //Counts Products
    delay(1000);
    conveyorBeltOff();
    delay(4000);
    
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
    partExtLinAct();
    delay(1000);

    gantryUp();
    delay(1000); 
    clawSemiClose();
    delay(1000); 
    gantryDown();
    delay(1000);
    clawClose();
    delay(1000);
    gantryUp();
    delay(1000);
    gantryDown();
    delay(1000);

    count = 0;
    action = false;
  }

  

  // SERVO
  
}

