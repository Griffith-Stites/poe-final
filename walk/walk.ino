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
  lift1.attach(0);
  rotate1.attach(1);

  lift1.attach(2);
  rotate1.attach(3);

  lift1.attach(4);
  rotate1.attach(5);

  lift1.attach(6);
  rotate1.attach(7);
}

void loop() {
  Serial.println("start");
  // 1 and 4 down
  lift1.write(10);
  lift4.write(10);
  // 2 and 3 up
  lift2.write(10);
  lift3.write(10);
  // 1 and 4 backward
  rotate1.write(10);
  rotate4.write(10);
  // 2 and 3 forward
  rotate1.write(10);
  rotate4.write(10);
  // 2 and 3 down
  lift2.write(10);
  lift3.write(10);
  // 1 and 4 up
  lift1.write(10);
  lift4.write(10);
  // 2 and 3 backward
  rotate1.write(10);
  rotate4.write(10);
  
  delay(3000);
}

// void printStatus(int sensor, int pan, int tilt) {
//   // print the results to the Serial Monitor:
//   Serial.print(sensorValue);
//   Serial.print(',');
//   Serial.print(pan);
//   Serial.print(',');
//   Serial.print(tilt);
//   Serial.println();
// }
