#include <Servo.h> // Include the servo library

// create servo objects to control lift and rotation for each leg
// front left
Servo motor;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  motor.attach(5);
}

void loop() {
  Serial.println("start");
  // down
  motor.write(10);
  delay(1000);
  // up
  motor.write(20);
  delay(1000);
}
