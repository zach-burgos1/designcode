#define BB_PIN 30
#define DC_PIN 11

#define LIN_PIN1 25
#define LIN_PIN2 27

#define CONV_RUNTIME 300

/*
  ERROR LOG: 
  04/03/25
    - breakbeam sometimes reads that a product has gone by, but sometimes does not
    - relay isn't actually turning it off, idk what's happening there
      instead of always closed, it's always open? Idk probably just need to look
      at the wiring
    - 




*/

enum BB_STATE {BROKEN, UNBROKEN}; 
// BB_STATE sensorState = UNBROKEN, lastState=UNBROKEN; 
int sensorState = 0, lastState = 0; 
int numProducts = 0; 
int countProducts = 0; 
// bool linearExt = false; 
int numLoops = CONV_RUNTIME; 

void setup() {    
  delay(5000); 
  // initialize the sensor pin as an input:
  pinMode(BB_PIN, INPUT);     
  digitalWrite(BB_PIN, HIGH); // turn on the pullup
  pinMode(DC_PIN, OUTPUT); 
  digitalWrite(DC_PIN, 0); 

  pinMode(LIN_PIN1, OUTPUT);
  pinMode(LIN_PIN2, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  /*
  while(sensorState == 0){
    sensorState = digitalRead(BB_PIN); 
    Serial.println("Unbroken");
  }
  while(sensorState == 1){
    sensorState = digitalRead(BB_PIN); 
    Serial.println("broken"); 
  }
  numProducts++; 
  
  if(numProducts % 2 == 0){
    // extend the actuator
    digitalWrite(LIN_PIN1, HIGH);
    digitalWrite(LIN_PIN2, LOW);

    delay(5000); // actuator will stop extending automatically when reaching the limit

    // retracts the actuator
    digitalWrite(LIN_PIN1, LOW);
    digitalWrite(LIN_PIN2, HIGH);

    delay(5000); // actuator will stop retracting automatically when reaching the limit
  }
  // continue; 
  */


  
  numLoops++; 
  delay(10); 
  if (numLoops >= CONV_RUNTIME) {
    digitalWrite(DC_PIN, 0); 
    delay(3000); 
    digitalWrite(DC_PIN, 1); 
    numLoops = 0; 
  }

  sensorState = (digitalRead(BB_PIN));

  if (sensorState && !lastState) {
    Serial.println("Unbroken");
  } 
  if (!sensorState && lastState) {
    Serial.println("Broken");
    numProducts++; 
    countProducts++; 
  }
  lastState = sensorState;
  Serial.println(numProducts);

  // linearExt = (numProducts % 2 == 0) && (numProducts > 0); 

  if(countProducts == 2){
    // extend the actuator
    digitalWrite(LIN_PIN1, HIGH);
    digitalWrite(LIN_PIN2, LOW);

    delay(2000); // actuator will stop extending automatically when reaching the limit

    // retracts the actuator
    digitalWrite(LIN_PIN1, LOW);
    digitalWrite(LIN_PIN2, HIGH);

    delay(1000); // actuator will stop retracting automatically when reaching the limit
    countProducts = 0; 
  }
  
  
}
