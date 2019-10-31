#include <Servo.h> // Include the servo library

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
  lift1.attach(2);
  rotate1.attach(3);

  lift2.attach(4);
  rotate2.attach(5);

  lift3.attach(6);
  rotate3.attach(7);

  lift4.attach(8);
  rotate4.attach(9);
}

void loop() {
  Serial.println("start");
  // 1 and 4 down
  lift1.write(105);
  lift4.write(95);
  // 2 and 3 up
  lift2.write(100);
  lift3.write(110);
  delay(350);

  // 1 and 4 backward
  rotate1.write(110);
  rotate4.write(70);

  // 2 and 3 forward
  rotate2.write(90);
  rotate3.write(90);
  delay(350);

  // 2 and 3 down
  lift2.write(80); // rotates opposite of 1 and 4
  lift3.write(90); // rotates opposite of 1 and 4

  // 1 and 4 up
  lift1.write(85);
  lift4.write(75);

  delay(350);
  // 2 and 3 backward
  rotate2.write(70);
  rotate3.write(110);

  // 1 and 4 forward
  rotate1.write(80); // lower numbers rotate forward
  rotate4.write(90);
  delay(350);
}
