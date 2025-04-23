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

void gantryUp(){
  digitalWrite(PIN_L2_EN1, HIGH);
  digitalWrite(PIN_L2_EN2, HIGH);

  int timeStart = millis(); 
  int timeNow = millis(); 

  while(timeNow - timeStart <= VERT_DELAY){
    stepGantryV.step(2*STEPS_PER_REV); 
    timeNow = millis(); 
  }

  digitalWrite(PIN_L2_EN1, LOW); 
  digitalWrite(PIN_L2_EN2, LOW); 
}
void gantryDown(){
  digitalWrite(PIN_L2_EN1, HIGH);
  digitalWrite(PIN_L2_EN2, HIGH);

  int timeStart = millis(); 
  int timeNow = millis(); 

  while(timeNow - timeStart <= VERT_DELAY){
    stepGantryV.step(-2*STEPS_PER_REV); 
    timeNow = millis(); 
  }

  digitalWrite(PIN_L2_EN1, LOW); 
  digitalWrite(PIN_L2_EN2, LOW); 
}

void clawOpen(){

}
void clawClose(){

}

void caseExport(){

}
void caseImport(){

}