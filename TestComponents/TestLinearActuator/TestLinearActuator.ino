/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-actuator
 */

// constants won't change
// const int ENA_PIN = 9; // the Arduino pin connected to the EN1 pin L298N
const int IN1_PIN = 8; // the Arduino pin connected to the IN1 pin L298N
const int IN2_PIN = 9; // the Arduino pin connected to the IN2 pin L298N

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pins as outputs.
  // pinMode(ENA_PIN, OUTPUT);
  pinMode(3, OUTPUT); 
  digitalWrite(3, 0); 

  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);

  // digitalWrite(ENA_PIN, HIGH);
}

// the loop function runs over and over again forever
void loop() {
  // extend the actuator


  // retracts the actuator
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, HIGH);

  delay(5000); // actuator will stop retracting automatically when reaching the limit

  digitalWrite(IN1_PIN, HIGH);
  digitalWrite(IN2_PIN, LOW);

  delay(5000); // actuator will stop extending automatically when reaching the limit
  delay(5000); 

}
