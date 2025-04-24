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
void partExtLinAct(){
  // Set direction to extend
  digitalWrite(PIN_L4_IN3, LOW);
  digitalWrite(PIN_L4_IN4, HIGH);

  // Set PWM speed (0-255)
  analogWrite(PIN_L4_EN2, 200);  // Lower value = slower speed

  // Run for a precise time
  delay(300);  // Adjust to how far you want to extend

  // Stop actuator
  analogWrite(PIN_L4_EN2, 0);

  digitalWrite(PIN_L4_IN3, HIGH); 
  digitalWrite(PIN_L4_IN4, LOW); 
  unsigned long startTime = millis();
  while(millis() - startTime < 100){delay(1);}
  delay(1000);

  return;

  digitalWrite(PIN_L4_EN2, HIGH); 
  // unsigned long startTime = millis(); 

  digitalWrite(PIN_L4_IN3, LOW); 
  digitalWrite(PIN_L4_IN4, HIGH); 
  while(millis() - startTime < 100){delay(1);}
  digitalWrite(PIN_L4_IN3, HIGH); 
  digitalWrite(PIN_L4_IN4, LOW); 
  startTime = millis();
  while(millis() - startTime < 100){delay(1);}

  digitalWrite(PIN_L4_EN2, LOW); 
}

void gantryDownCase(){
  digitalWrite(PIN_L2_EN1, HIGH);
  digitalWrite(PIN_L2_EN2, HIGH);

  unsigned long startMillis = millis(); // Capture the start time

  while (millis() - startMillis < 0.7*VERT_DELAY) { 
    stepGantryV.step(2 * STEPS_PER_REV); // Execute step
  }

  digitalWrite(PIN_L2_EN1, LOW); 
  digitalWrite(PIN_L2_EN2, LOW); 
}
void gantryUpCase(){
  digitalWrite(PIN_L2_EN1, HIGH);
  digitalWrite(PIN_L2_EN2, HIGH);

  unsigned long startMillis = millis(); // Capture the start time

  while (millis() - startMillis < 0.7*VERT_DELAY) { 
    stepGantryV.step(-2 * STEPS_PER_REV); // Execute step
  }

  digitalWrite(PIN_L2_EN1, LOW);
  digitalWrite(PIN_L2_EN2, LOW);
}

void gantryDown(){
  digitalWrite(PIN_L2_EN1, HIGH);
  digitalWrite(PIN_L2_EN2, HIGH);

  unsigned long startMillis = millis(); // Capture the start time

  while (millis() - startMillis < VERT_DELAY) { 
    stepGantryV.step(2 * STEPS_PER_REV); // Execute step
  }

  digitalWrite(PIN_L2_EN1, LOW); 
  digitalWrite(PIN_L2_EN2, LOW); 
}
void gantryUp(){
  digitalWrite(PIN_L2_EN1, HIGH);
  digitalWrite(PIN_L2_EN2, HIGH);

  unsigned long startMillis = millis(); // Capture the start time

  while (millis() - startMillis < VERT_DELAY) { 
    stepGantryV.step(-2 * STEPS_PER_REV); // Execute step
  }

  digitalWrite(PIN_L2_EN1, LOW);
  digitalWrite(PIN_L2_EN2, LOW);
}

void gantryPull(){
  digitalWrite(PIN_L1_EN1, HIGH);
  digitalWrite(PIN_L1_EN2, HIGH);

  stepGantryH.step(4.1 * STEPS_PER_REV);
  delay(500); 

  // unsigned long startMillis = millis(); // Capture the start time

  // while (millis() - startMillis < HOR_DELAY) { 
  //   stepGantryH.step(2 * STEPS_PER_REV); // Execute step
  // }

  // stepGantryH.step(2*STEPS_PER_REV); // towareds product
  // delay(HOR_DELAY); 
  digitalWrite(PIN_L1_EN1, LOW);
  digitalWrite(PIN_L1_EN2, LOW);
}
void gantryPush(){
  digitalWrite(PIN_L1_EN1, HIGH);
  digitalWrite(PIN_L1_EN2, HIGH);

  stepGantryH.step(-4.1*STEPS_PER_REV); 
  delay(500);

  // unsigned long startMillis = millis(); // Capture the start time

  // while (millis() - startMillis < HOR_DELAY) { 
  //   stepGantryH.step(-2 * STEPS_PER_REV); // Execute step
  // }

  // stepGantryH.step(-2*STEPS_PER_REV); // towards case
  // delay(HOR_DELAY); 
  digitalWrite(PIN_L1_EN1, LOW);
  digitalWrite(PIN_L1_EN2, LOW);
}

void caseForward(){
  digitalWrite(PIN_L3_EN1, HIGH);
  digitalWrite(PIN_L3_EN2, HIGH);

  unsigned long startMillis = millis(); // Capture the start time

  while (millis() - startMillis < CASE_DELAY) { 
    stepCase.step(-2 * STEPS_PER_REV); // Execute step
  }

  digitalWrite(PIN_L3_EN1, LOW);
  digitalWrite(PIN_L3_EN2, LOW);
}

void caseBackward(){
  digitalWrite(PIN_L3_EN1, HIGH);
  digitalWrite(PIN_L3_EN2, HIGH);

  unsigned long startMillis = millis(); // Capture the start time

  while (millis() - startMillis < CASE_DELAY) { 
    stepCase.step(2 * STEPS_PER_REV); // Execute step
  }

  digitalWrite(PIN_L3_EN1, LOW);
  digitalWrite(PIN_L3_EN2, LOW);
}

void clawOpen(){
  servo1.writeMicroseconds(600);
  servo2.writeMicroseconds(1900);
}
void clawSemiCloseLoad(){
  servo1.writeMicroseconds(1200); 
  servo2.writeMicroseconds(1265); 
}
void clawSemiCloseCase(){
  servo1.writeMicroseconds(1200); 
  servo2.writeMicroseconds(1255); 
}
void clawClose(){
  servo1.writeMicroseconds(1300); 
  servo2.writeMicroseconds(1200); 
}
