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

  // initServos(); 

  digitalWrite(PIN_L3_EN1, HIGH); 
  digitalWrite(PIN_L3_EN2, HIGH); 

  pinMode(PIN_RELAY, OUTPUT);
  digitalWrite(PIN_RELAY, LOW);

  Serial.begin(9600);  
}

// the loop function runs over and over again forever
void loop() {

  
  // extendLinAct(); 
  // retractLinAct(); 

  // GANTRY HORIZONTAL
  // digitalWrite(PIN_L1_EN1, HIGH);
  // digitalWrite(PIN_L1_EN2, HIGH);
  // stepGantryH.step(2*STEPS_PER_REV); // towards product
  // delay(HOR_DELAY); 
  // stepGantryH.step(-2*STEPS_PER_REV); // towards case
  // delay(HOR_DELAY); 
  // digitalWrite(PIN_L1_EN1, LOW);
  // digitalWrite(PIN_L1_EN2, LOW);

  // GANTRY VERTICAL  
  // delay(1000); 
  // digitalWrite(PIN_L2_EN1, HIGH);
  // digitalWrite(PIN_L2_EN2, HIGH);
  // delay(1000); 
  // stepGantryV.step(-1*STEPS_PER_REV);
  // delay(VERT_DELAY); 
  // //digitalWrite(PIN_L2_EN1, LOW);
  // //digitalWrite(PIN_L2_EN2, LOW);
  // delay(1000);
  // //digitalWrite(PIN_L2_EN1, HIGH);
  // //digitalWrite(PIN_L2_EN2, HIGH);
  // stepGantryV.step(1*STEPS_PER_REV);
  // delay(VERT_DELAY); 
  // delay(1000); 
  // //digitalWrite(PIN_L2_EN1, LOW);
  // //digitalWrite(PIN_L2_EN2, LOW);
  // delay(1000); 

  // CASE RAIL
   digitalWrite(PIN_L3_EN1, HIGH); 
   digitalWrite(PIN_L3_EN2, HIGH); 
  //stepCase.step(2*STEPS_PER_REV);
  delay(1000);
  for (int i = 0; i < 200; i++){
    caseBackwards();
    delay(5);
  }
  digitalWrite(PIN_L3_EN1, LOW);
  digitalWrite(PIN_L3_EN2, LOW);
  // Serial.println("clockwise");
  //for(int i = 0; i < 100; i++){
  //  delay(i*2981); 
  //} 
  //delay(CASE_DELAY); 

  //stepCase.step(-2*STEPS_PER_REV);
  //Serial.println("counterclockwise");
  //delay(CASE_DELAY); 
  // digitalWrite(PIN_L3_EN1, LOW); 
  // digitalWrite(PIN_L3_EN2, LOW); 
/*
  // RELAY
   digitalWrite(PIN_RELAY, HIGH); 
   sensorState = digitalRead(PIN_BB);
   if (!sensorState && lastState){
    count++; //Counts Products
   }
  if (cart == 1){ //Grabs Products before the LA and resets basically every four.
    delay(1000);
    servo1.writeMicroseconds(1850);
    servo2.writeMicroseconds(475);
  //  Go Up
    cart = 0;
    count = 0;
  }
  if (count == 2) {
    delay(1000);
   digitalWrite(PIN_RELAY, LOW);
   delay(1000);
   extendLinAct();
   retractLinAct();
   cart++;
   count = 0;
  }
  // if (cart == 1){
  //  servo1.writeMicroseconds(1850);
  //  servo2.writeMicroseconds(475); 
  //}
  Serial.println(count);
  lastState = sensorState;
  */
  // // SERVO
  // servo1.writeMicroseconds(1850); 
  // servo2.writeMicroseconds(475);  
}
