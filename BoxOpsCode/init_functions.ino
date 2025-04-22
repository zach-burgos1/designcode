#include "init_functions.h"
#include <Stepper.h>

void initL298NS(){
  pinMode(PIN_L1_EN1, OUTPUT);
  pinMode(PIN_L1_EN2, OUTPUT);
  stepGantryH.setSpeed(SPEED_HOR); 

  pinMode(PIN_L2_EN1, OUTPUT);
  pinMode(PIN_L2_EN2, OUTPUT);
  stepGantryV.setSpeed(SPEED_VERT);

  pinMode(PIN_L3_EN1, OUTPUT);
  pinMode(PIN_L3_EN2, OUTPUT);
  stepCase.setSpeed(SPEED_CASE); 

  pinMode(PIN_L4_EN2, OUTPUT);
  pinMode(PIN_L4_IN3, OUTPUT);
  pinMode(PIN_L4_IN4, OUTPUT);  
}
void initRelay(){
  pinMode(PIN_RELAY, OUTPUT); 
}
void initBB(){
  pinMode(PIN_BB, INPUT); 
}