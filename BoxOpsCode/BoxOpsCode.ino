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
  extendLinAct(); 
  retractLinAct(); 
  
  

}
