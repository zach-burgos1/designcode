/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

Servo servo1;  // create Servo object to control a servo
Servo servo2; 
// twelve Servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  servo1.attach(8);  // attaches the servo on pin 9 to the Servo object
  servo2.attach(9);

}

void loop() {
  // for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
  //   // in steps of 1 degree
  //   myservo.write(pos);              // tell servo to go to position in variable 'pos'
  //   delay(15);                       // waits 15 ms for the servo to reach the position
  // }
  // for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
  //   myservo.write(pos);              // tell servo to go to position in variable 'pos'
  //   delay(15);                       // waits 15 ms for the servo to reach the position
  // }
  // servo1.write(127); 
  // servo2.write(42);

  servo1.writeMicroseconds(1850); 
  servo2.writeMicroseconds(475); 

  // servo1.write(128); //131
  // servo2.write(22); // 18

  delay(1000); 
}