#include <Servo.h> // Include the servo library

// Code to just rotate the wheels

// create servo objects to control rotation for each leg
// front left
Servo rotate1;
// front right
Servo rotate2;
// back left
Servo rotate3;
// back right
Servo rotate4;

int bAngle = 45 // backward angle
int fAngle = 0 // forward angle

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  rotate1.attach(2);
  rotate2.attach(3);
  rotate3.attach(4);
  rotate4.attach(5);
}

void loop() {
  Serial.println("start");
  // Slide all back
  rotate1.write(bAngle);
  rotate2.write(bAngle);
  rotate3.write(bAngle);
  rotate4.write(bAngle);
  delay(1000);
  // Slide all forward
  rotate1.write(fAngle);
  rotate2.write(fAngle);
  rotate3.write(fAngle);
  rotate4.write(fAngle);
  delay(1000);
}
