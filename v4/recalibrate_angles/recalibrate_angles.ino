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

int magOn = 180; // mag on angle
int magOff = 0; // mag off angle

//funcs to convert intuitive angles to servo angles

int to1(int angle) {
  return 45 -7 + angle;
}
int to2(int angle) {
  return 135 - 2 - angle;
}
int to3(int angle) {
  return 135 + 4 + angle;
}
int to4(int angle) {
  return 45 + 4 - angle;
}

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

  rotate1.write(to1(0));
  rotate2.write(to2(0));
  rotate3.write(to3(0));
  rotate4.write(to4(0));

  delay(2000);

//  Serial.println("Turning all magnets on");
//  mag1.write(magOff);
//  mag2.write(magOff);
//  mag3.write(magOff);
//  mag4.write(magOff);
}

void loop() {
  while (1) {}
}
