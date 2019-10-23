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
  lift1.attach(5);
  // rotate1.attach(1);

  lift2.attach(6);
  // rotate2.attach(3);

  lift3.attach(10);
  // rotate3.attach(5);

  lift4.attach(11);
  // rotate4.attach(7);
}

void loop() {
  Serial.println("start");
  // 1 and 4 down
  lift1.write(10);
  lift4.write(130);
  // 2 and 3 up
  lift2.write(80);
  lift3.write(60);
  delay(1000);
  // 2 and 3 down
  lift2.write(20);
  lift3.write(10);
  // 1 and 4 up
  lift1.write(50);
  lift4.write(110);

  delay(3000);
}
