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