#include "mvmt_functions.h"

void conveyorBeltOn(){
  digitalWrite(PIN_RELAY, HIGH); 
}
void conveyorBeltOff(){
  digitalWrite(PIN_RELAY, LOW); 
}

void retractLinAct(){
  digitalWrite(PIN_L4_EN2, HIGH); 

  digitalWrite(PIN_L4_IN3, HIGH); 
  digitalWrite(PIN_L4_IN4, LOW); 
  delay(LINACT_DELAY); 

  digitalWrite(PIN_L4_EN2, LOW); 
}
void extendLinAct(){
  digitalWrite(PIN_L4_EN2, HIGH); 

  digitalWrite(PIN_L4_IN3, LOW); 
  digitalWrite(PIN_L4_IN4, HIGH); 
  delay(LINACT_DELAY); 

  digitalWrite(PIN_L4_EN2, LOW); 
  
}

void gantryDown(){
  digitalWrite(PIN_L2_EN1, HIGH);
  digitalWrite(PIN_L2_EN2, HIGH);

  int timeStart = millis(); 
  int timeNow = millis(); 

  unsigned long startMillis = millis(); // Capture the start time

  while (millis() - startMillis < 2000) { 
    stepGantryV.step(2 * STEPS_PER_REV); // Execute step
  }

  digitalWrite(PIN_L2_EN1, LOW); 
  digitalWrite(PIN_L2_EN2, LOW); 
}
void gantryUp(){
  digitalWrite(PIN_L2_EN1, HIGH);
  digitalWrite(PIN_L2_EN2, HIGH);

  unsigned long startMillis = millis(); // Capture the start time

  while (millis() - startMillis < 2000) { 
    stepGantryV.step(-2 * STEPS_PER_REV); // Execute step
  }

  digitalWrite(PIN_L2_EN1, LOW);
  digitalWrite(PIN_L2_EN2, LOW);
}

void caseForward(){
  digitalWrite(PIN_L3_EN1, HIGH);
  digitalWrite(PIN_L3_EN2, HIGH);

  unsigned long startMillis = millis(); // Capture the start time

  while (millis() - startMillis < 2000) { 
    stepCase.step(-2 * STEPS_PER_REV); // Execute step
  }

  digitalWrite(PIN_L3_EN1, LOW);
  digitalWrite(PIN_L3_EN2, LOW);
}

void caseBackward(){
  digitalWrite(PIN_L3_EN1, HIGH);
  digitalWrite(PIN_L3_EN2, HIGH);

  unsigned long startMillis = millis(); // Capture the start time

  while (millis() - startMillis < 4000) { 
    stepCase.step(2 * STEPS_PER_REV); // Execute step
  }

  digitalWrite(PIN_L3_EN1, LOW);
  digitalWrite(PIN_L3_EN2, LOW);
}

void clawOpen(){
  servo1.writeMicroseconds(1000);
  servo2.writeMicroseconds(1500);
}
void clawSemiClose(){
  servo1.writeMicroseconds(1200); 
  servo2.writeMicroseconds(1275); 
}
void clawClose(){
  servo1.writeMicroseconds(1300); 
  servo2.writeMicroseconds(1200); 
}
