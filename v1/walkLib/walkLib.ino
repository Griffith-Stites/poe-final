#include <Servo.h> // Include the servo library
#include <Leg.h> // include the leg library

// initialize all the legs
// Leg(int liftPin, int liftZero, int liftDirection,
// int rotatePin, int rotateZero, int rotateDirection)
Leg leg1(2, 105, -1, 3, 110, 1);
Leg leg2(4, 80, 1, 5, 90, 1);
Leg leg3(6, 90, 1, 7, 90, -1);
Leg leg4(7, 95, -1, 8, 90, 1);

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
  leg2.forward(0);
  leg3.forward(0);
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
  leg1.forward(0);
  leg4.forward(0);
  delay(1000);
}
