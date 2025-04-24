#include "definitions.h"
#include "init_functions.h"
#include "mvmt_functions.h"

// SENSOR
int count = 0;
int countphase = 0; 
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

  initLimit(); 

  clawOpen(); 
  retractLinAct();

  caseBackward(); 
  delay(2000);
  caseForward(); 


  // Serial.begin(9600); 
}

void loop() {
  // if(digitalRead(PIN_LIMIT)){
  //   Serial.println("pressed");
  // } else {
  //   Serial.println("Not pressed"); 
  // }

  // gantryPush();
  // gantryPull();

  // return; 


  conveyorBeltOn();
  // RELAY
  sensorState = digitalRead(PIN_BB);
  if (!sensorState && lastState){
    count++; //Counts Products
    delay(250);
    conveyorBeltOff();
    if(count == 1 || 3){
      delay(4000);
    }
    
  }
  lastState = sensorState;
  if (count == 2 && !action) {
    delay(250);
    digitalWrite(PIN_RELAY, LOW);
    delay(250);
    extendLinAct();
    retractLinAct();
    digitalWrite(PIN_RELAY, HIGH);
    action = true;  //allows the LA to only work once while waiting for next product to load
  }
  if (count == 4){ //Grabs Products before the LA and resets basically every four.
    delay(1000);
    partExtLinAct();
    retractLinAct();
    delay(1000);

    gantryUp();
    delay(1000); 
    clawSemiCloseLoad();
    delay(250); 
    gantryDown();
    delay(1000);
    clawClose();
    delay(250);
    gantryUp();
    delay(1000);
    gantryPush(); 
    delay(1000); 
    gantryDownCase(); 
    delay(250); 
    clawSemiCloseCase(); 
    delay(250);
    gantryUpCase(); 
    delay(250);
    gantryPull(); 
    delay(250); 
    clawOpen(); 
    delay(250); 
    gantryDown(); 
    delay(250);

    count = 0;
    countphase++; 
    action = false;
  }
  if(countphase == 2){
    caseForward();
    delay(250); 
    caseBackward(); 
    delay(250); 

    caseBackward(); 
    delay(2000); 
    caseForward();
    delay(250);
    countphase = 0; 
  }
}

