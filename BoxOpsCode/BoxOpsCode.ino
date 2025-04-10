#include "definitions.h"

void setup() {
  // Setup Steppers
  // Setup Linear Actuator
  // Setup Relay / Flip Relay
  // 

  // initialize digital pins as outputs.
  pinMode(ENA_PIN, OUTPUT);
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);

  digitalWrite(ENA_PIN, HIGH);
}

// the loop function runs over and over again forever
void loop() {
  // extend the actuator
  digitalWrite(IN1_PIN, HIGH);
  digitalWrite(IN2_PIN, LOW);

  delay(5000); // actuator will stop extending automatically when reaching the limit

  // retracts the actuator
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, HIGH);

  delay(5000); // actuator will stop retracting automatically when reaching the limit
}
