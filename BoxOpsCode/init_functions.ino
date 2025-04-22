#include "init_functions.h"

void initL298NS(){
  pinMode(PIN_L1_EN1, OUTPUT);
  pinMode(PIN_L1_EN2, OUTPUT);
  stepGantryH.setSpeed(SPEED_HOR); 
  digitalWrite(PIN_L1_EN1, LOW);
  digitalWrite(PIN_L1_EN2, LOW);

  pinMode(PIN_L2_EN1, OUTPUT);
  pinMode(PIN_L2_EN2, OUTPUT);
  stepGantryV.setSpeed(SPEED_VERT);
  digitalWrite(PIN_L2_EN1, LOW);
  digitalWrite(PIN_L2_EN2, LOW);

  pinMode(PIN_L3_EN1, OUTPUT);
  pinMode(PIN_L3_EN2, OUTPUT);
  stepCase.setSpeed(SPEED_CASE); 
  digitalWrite(PIN_L3_EN1, LOW);
  digitalWrite(PIN_L3_EN2, LOW);

  pinMode(PIN_L4_EN2, OUTPUT);
  pinMode(PIN_L4_IN3, OUTPUT);
  pinMode(PIN_L4_IN4, OUTPUT); 
  digitalWrite(PIN_L4_EN2, LOW); 
}
void initRelay(){
  pinMode(PIN_RELAY, OUTPUT); 
}
void initBB(){
  pinMode(PIN_BB, INPUT); 
  digitalWrite(PIN_BB, HIGH); 
}
void initServos(){
  servo1.attach(PIN_SERVO_1); 
  servo2.attach(PIN_SERVO_2); 
}