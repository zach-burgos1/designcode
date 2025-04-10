#include "init_functions.h"

void initL298NS(){
  pinMode(PIN_L1_EN1, OUTPUT);
  pinMode(PIN_L1_EN2, OUTPUT);
  pinMode(PIN_L1_IN1, OUTPUT);
  pinMode(PIN_L1_IN2, OUTPUT);
  pinMode(PIN_L1_IN3, OUTPUT);
  pinMode(PIN_L1_IN4, OUTPUT);

  pinMode(PIN_L2_EN1, OUTPUT);
  pinMode(PIN_L2_EN2, OUTPUT);
  pinMode(PIN_L2_IN1, OUTPUT);
  pinMode(PIN_L2_IN2, OUTPUT);
  pinMode(PIN_L2_IN3, OUTPUT);
  pinMode(PIN_L2_IN4, OUTPUT);

  pinMode(PIN_L3_EN1, OUTPUT);
  pinMode(PIN_L3_EN2, OUTPUT);
  pinMode(PIN_L3_IN1, OUTPUT);
  pinMode(PIN_L3_IN2, OUTPUT);
  pinMode(PIN_L3_IN3, OUTPUT);
  pinMode(PIN_L3_IN4, OUTPUT);

  pinMode(PIN_L4_EN1, OUTPUT);
  pinMode(PIN_L4_IN1, OUTPUT);
  pinMode(PIN_L4_IN2, OUTPUT);  
}

void retractLinAct(){

}
void extendLinAct(){
  
}