#include <Servo.h> // Include the servo library

// Code to just rotate the wheels

// create servo objects to control rotation and magnet for each leg
// front left
Servo rotate1;
Servo mag1;
// front right
Servo rotate2;
Servo mag2;
// back left
Servo rotate3;
Servo mag3;
// back right
Servo rotate4;
Servo mag4;

int bAngle = 45 // backward angle
int fAngle = 0 // forward angle

int magOn = 0 // mag on angle
int magOff = 90 // mag off angle

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  rotate1.attach(2);
  rotate2.attach(3);
  rotate3.attach(4);
  rotate4.attach(5);

  mag1.attach(10);
  mag2.attach(11);
  mag3.attach(12);
  mag4.attach(13);
}

void loop() {
  Serial.println("start");
  // release 1 and 2 magnets
  mag1.write(magOff);
  mag2.write(magOff);
  delay(500);
  // slide 1 and 2 forward
  rotate1.write(fAngle);
  rotate2.write(fAngle);
  delay(500);
  // attach 1 and 2 magnets
  mag1.write(magOn);
  mag2.write(magOn);
  delay(500);
  // release 3 and 4 magnets
  mag3.write(magOff);
  mag4.write(magOff);
  delay(500);
  // slide 3 and 4 forward
  rotate3.write(fAngle);
  rotate4.write(fAngle);
  delay(500);
  // attach 3 and 4 magnets
  mag3.write(magOn);
  mag4.write(magOn);
  delay(500);
  // Slide all back
  rotate1.write(bAngle);
  rotate2.write(bAngle);
  rotate3.write(bAngle);
  rotate4.write(bAngle);
  delay(500);
}
