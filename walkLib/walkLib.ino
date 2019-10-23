#include <Servo.h> // Include the servo library
#include <Leg.h> // include the leg library

// initialize all the legs
// Leg(int liftPin, int rotatePin, int liftDirection,
// int rotateDirection, int liftZero, int rotateZero)
Leg leg1(2, 3, 1, 1, 90, 90);
Leg leg2(4, 5, 1, 1, 90, 90);
Leg leg3(6, 7, 1, 1, 90, 90);
Leg leg4(8, 9, 1, 1, 90, 90);


void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  Serial.println("start");
  // 1 and 4 down
  leg1.down(0);
  leg4.down(0);
  // 2 and 3 up
  leg2.up(10);
  leg3.up(10);
  delay(1000);
  // 1 and 4 backward
  leg1.backward(-30);
  leg4.backward(-30);
  // 2 and 3 forward
  leg2.forward(30);
  leg3.forward(30);
  delay(1000);
  // 2 and 3 down
  leg2.down(0);
  leg3.down(0);
  // 1 and 4 up
  leg1.up(10);
  leg4.up(10);
  delay(1000);
  // 2 and 3 backward
  leg2.backward(-30);
  leg3.backward(-30);
  // 1 and 4 forward
  leg1.forward(30);
  leg4.forward(30);
  delay(1000);
}
