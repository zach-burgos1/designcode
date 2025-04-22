#include "init_functions.h"
#include <Stepper.h>

void initL298NS(){
  pinMode(PIN_L1_EN1, OUTPUT);
  pinMode(PIN_L1_EN2, OUTPUT);
  Stepper stepGantryH(STEPS_PER_REV, PIN_L1_IN1, PIN_L1_IN2, PIN_L1_IN3, PIN_L1_IN4); 
  stepGantryH.setSpeed(SPEED_HOR); 

  pinMode(PIN_L2_EN1, OUTPUT);
  pinMode(PIN_L2_EN2, OUTPUT);
  Stepper stepGantryV(STEPS_PER_REV, PIN_L2_IN1, PIN_L2_IN2, PIN_L2_IN3, PIN_L2_IN4);
  stepGantryV.setSpeed(SPEED_VERT);

  pinMode(PIN_L3_EN1, OUTPUT);
  pinMode(PIN_L3_EN2, OUTPUT);
  Stepper stepCase(STEPS_PER_REV, PIN_L3_EN1, PIN_L3_EN2, PIN_L3_EN3, PIN_L3_EN4); 
  stepCase.setSpeed(SPEED_CASE); 

  pinMode(PIN_L4_EN1, OUTPUT);
  pinMode(PIN_L4_IN1, OUTPUT);
  pinMode(PIN_L4_IN2, OUTPUT);  
}

void retractLinAct(){
  digitalWrite(PIN_L4_EN1, HIGH); 

  digitalWrite(PIN_L4_IN1, LOW); 
  digitalWrite(PIN_L4_IN2, HIGH); 
  delay(5000); 

  digitalWrite(PIN_L4_EN1, LOW); 
}
void extendLinAct(){
  digitalWrite(PIN_L4_EN1, HIGH); 

  digitalWrite(PIN_L4_IN1, HIGH); 
  digitalWrite(PIN_L4_IN2, LOW); 
  delay(5000); 

  digitalWrite(PIN_L4_EN1, LOW); 
  
}