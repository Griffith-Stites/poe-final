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

int zero_angle = 0;
int magOn = 180; // mag on angle
int magOff = 0; // mag off angle

int to1(int angle) {
  return angle + 135;
}

int to2(int angle) {
  return angle + 45;
}

int to3(int angle) {
  return angle + 45;
}

int to4(int angle) {
  return angle + 135;
}

void setup() {
  Serial.begin(9600);

  rotate1.attach(2);
  rotate2.attach(3);
  rotate3.attach(4);
  rotate4.attach(5);

  mag1.attach(10);
  mag2.attach(11);
  mag3.attach(12);
  mag4.attach(13);
  
  rotate1.write(to1(zero_angle));
  rotate2.write(to2(zero_angle));
  rotate3.write(to3(zero_angle));
  rotate4.write(to4(zero_angle));

  mag1.write(magOn);
  mag2.write(magOn);
  mag3.write(magOn);
  mag4.write(magOn);

  delay(1000);
//
//  mag1.write(magOff);
//  mag2.write(magOff);
//  mag3.write(magOff);
//  mag4.write(magOff);  
}

void loop() {
  // put your main code here, to run repeatedly:

}
