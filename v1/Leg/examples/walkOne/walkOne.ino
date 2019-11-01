#include <Servo.h> // Include the servo library
#include <Leg.h> // include the leg library

// initialize all the legs
// Leg(int liftPin, int liftZero, int liftDirection,
// int rotatePin, int rotateZero, int rotateDirection)
Leg leg(2, 105, -1, 3, 110, 1);

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  Serial.println("start");
  leg.down(0);
  delay(1000);
  leg.backward(-30);
  delay(1000);
  leg.up(10);
  delay(1000);
  leg.forward(10);
  delay(1000);
}
