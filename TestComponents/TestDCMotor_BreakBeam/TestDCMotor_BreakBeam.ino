#define BB_PIN 30
#define DC_PIN 3
int sensorState = 0, lastState=0; 

void setup() {    
  // initialize the sensor pin as an input:
  pinMode(BB_PIN, INPUT);     
  digitalWrite(BB_PIN, HIGH); // turn on the pullup
  pinMode(DC_PIN, OUTPUT); 
  digitalWrite(DC_PIN, 1); 

  Serial.begin(9600);

}

void loop() {
  sensorState = digitalRead(BB_PIN);
  if (sensorState && !lastState) {
    Serial.println("Unbroken");
  } 
  if (!sensorState && lastState) {
    Serial.println("Broken");
  }
  lastState = sensorState;

}
