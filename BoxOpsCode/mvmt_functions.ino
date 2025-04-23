#include "mvmt_functions.h"

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

void vertBackwards(){
  digitalWrite(PIN_L2_IN1, HIGH);
  digitalWrite(PIN_L2_IN2, LOW);
  digitalWrite(PIN_L2_IN3, LOW);
  digitalWrite(PIN_L2_IN4, HIGH);
  delay(5);

  digitalWrite(PIN_L2_IN1, LOW);
  digitalWrite(PIN_L2_IN2, HIGH);
  digitalWrite(PIN_L2_IN3, LOW);
  digitalWrite(PIN_L2_IN4, HIGH);
  delay(5);

  digitalWrite(PIN_L2_IN1, LOW);
  digitalWrite(PIN_L2_IN2, HIGH);
  digitalWrite(PIN_L2_IN3, HIGH);
  digitalWrite(PIN_L2_IN4, LOW);
  delay(5);

  digitalWrite(PIN_L2_IN1, HIGH);
  digitalWrite(PIN_L2_IN2, LOW);
  digitalWrite(PIN_L2_IN3, HIGH);
  digitalWrite(PIN_L2_IN4, LOW);
  delay(5);
}

void caseBackwards(){
  digitalWrite(PIN_L3_IN1, HIGH);
  digitalWrite(PIN_L3_IN2, LOW);
  digitalWrite(PIN_L3_IN3, HIGH);
  digitalWrite(PIN_L3_IN4, LOW);
  delay(5);

  digitalWrite(PIN_L3_IN1, LOW);
  digitalWrite(PIN_L3_IN2, HIGH);
  digitalWrite(PIN_L3_IN3, HIGH);
  digitalWrite(PIN_L3_IN4, LOW);
  delay(5);

  digitalWrite(PIN_L3_IN1, LOW);
  digitalWrite(PIN_L3_IN2, HIGH);
  digitalWrite(PIN_L3_IN3, LOW);
  digitalWrite(PIN_L3_IN4, HIGH);
  delay(5);

  digitalWrite(PIN_L3_IN1, HIGH);
  digitalWrite(PIN_L3_IN2, LOW);
  digitalWrite(PIN_L3_IN3, LOW);
  digitalWrite(PIN_L3_IN4, HIGH);
  delay(5);
}