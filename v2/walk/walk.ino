#include <Servo.h> // Include the servo library

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

int bAngle = 120; // backward angle
int fAngle = 60; // forward angle

int magOn = 180; // mag on angle
int magOff = 0; // mag off angle

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

  mag1.write(magOff);
  mag2.write(magOff);
  mag3.write(magOff);
  mag4.write(magOff);

  rotate1.write(fAngle);
  rotate2.write(bAngle);
  rotate3.write(fAngle);
  rotate4.write(bAngle);

  delay(3000);
  Serial.println("PUT ON WALL");

  mag1.write(magOn);
  mag2.write(magOn);
  mag3.write(magOn);
  mag4.write(magOn);

  Serial.println("Start");
}

void loop() {
  mag1.write(magOff);
  delay(1000);
  rotate1.write(bAngle);
  delay(1000);
  mag1.write(magOn);
  delay(1000);

  mag2.write(magOff);
  delay(1000);
  rotate2.write(fAngle);
  delay(1000);
  mag2.write(magOn);
  delay(1000);
  
  mag3.write(magOff);
  delay(1000);
  rotate3.write(bAngle);
  delay(1000);
  mag3.write(magOn);
  delay(1000);

  mag4.write(magOff);
  delay(1000);
  rotate4.write(fAngle);
  delay(1000);
  mag4.write(magOn);
  delay(1000);

  Serial.println("SLIDE LEGS");
  delay(5000);
 
  // Slide all back
  rotate1.write(fAngle);
  rotate2.write(bAngle);
  rotate3.write(fAngle);
  rotate4.write(bAngle);
  delay(3000);
}
