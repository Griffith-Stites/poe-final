/*
  Leg.cpp - Library for controlling a leg with two servo actuators
  Created by Maeve Stites, October 21, 2019.
*/

#include "WProgram.h"
#include "Leg.h"
#include "Servo.h"

Leg::Leg(int liftPin, int rotatePin,
  int liftDirection, int rotateDirection,
  int liftZero, int rotateZero)
{
  /*
  liftPin: pin for the servo that lifts the leg
  rotatePin: pin for the servo that rotates the leg
  liftDirection: -1 or 1 to flip the direction of the servo
  rotateDirection: -1 or 1 to flip the direction of the servo
  liftZero: the zero angle of the lift servo
  rotateZero: the zero angle of the rotate servo
  */
  Servo lift;
  Servo rotate;
  lift.attach(liftPin);
  rotate.attach(rotatePin);
  _liftZero = liftZero;
  _rotateZero = rotateZero;
  // need direction indicator for lift and rotate
}

void Leg::forward()
{
  rotate.write(rotateZero + 10);
}

void Leg::backward()
{
  rotate.write(rotateZero + 10);
}

void Leg::up()
{
  lift.write(liftZero + 10);
}

void Leg::down()
{
  lift.write(rotateZero + 10);
}
