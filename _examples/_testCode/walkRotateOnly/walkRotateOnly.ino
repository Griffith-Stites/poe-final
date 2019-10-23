#include <Servo.h> // Include the servo library

int liftStatus = 0; // variable to store lift status (0: ground, 1: air)
int rotateStatus = 0; // variable to store rotate status

// create servo objects to control lift and rotation for each leg
// front left
Servo lift1;
Servo rotate1;
// front right
Servo lift2;
Servo rotate2;
// back left
Servo lift3;
Servo rotate3;
// back right
Servo lift4;
Servo rotate4;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  //  lift1.attach(0);
  rotate1.attach(10);

  //  lift2.attach(2);
  rotate2.attach(3);

  //  lift3.attach(4);
  rotate3.attach(5);

  //  lift4.attach(7);
  rotate4.attach(11);
}

void loop() {
  Serial.println("start");
  // 1 and 4 backward
  rotate1.write(130);
  rotate4.write(130);
  // 2 and 3 forward
  rotate2.write(55);
  rotate3.write(20);

  delay(1000);
  // 2 and 3 backward
  rotate2.write(5);
  rotate3.write(80);
  // 1 and 4 forward
  rotate1.write(80);
  rotate4.write(180);
  delay(1000);
}
