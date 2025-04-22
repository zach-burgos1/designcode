#include "definitions.h"
#include "init_functions.h"
#include "mvmt_functions.h"

void setup() {
  // Setup Steppers & Linear Actuator
  initL298NS(); 

  // Setup Relay
  initRelay(); 

  // Setup Breakbeam
  initBB(); 

}

// the loop function runs over and over again forever
void loop() {
  // extendLinAct(); 
  // retractLinAct(); 

  // digitalWrite(PIN_L1_EN1, HIGH);
  // digitalWrite(PIN_L1_EN2, HIGH);
  // stepGantryH.step(2*STEPS_PER_REV); // towareds product
  // delay(HOR_DELAY); 
  // stepGantryH.step(-2*STEPS_PER_REV); // towards case
  // delay(HOR_DELAY); 
  // digitalWrite(PIN_L1_EN1, LOW);
  // digitalWrite(PIN_L1_EN2, LOW);
  
  digitalWrite(PIN_L2_EN1, HIGH);
  digitalWrite(PIN_L2_EN2, HIGH);
  stepGantryV.step(2*STEPS_PER_REV);
  delay(VERT_DELAY); 
  stepGantryV.step(-2*STEPS_PER_REV);
  delay(VERT_DELAY); 
  digitalWrite(PIN_L2_EN1, LOW);
  digitalWrite(PIN_L2_EN2, LOW);
}
