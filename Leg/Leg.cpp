/*
  Leg.cpp - Library for controlling a leg with two servo actuators
  Created by Maeve Stites, October 21, 2019.
*/

#include "WProgram.h"
#include "Leg.h"
#include "Servo.h"

Leg::Leg(int liftPin, int rotatePin, int liftZero, int rotateZero)
{
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
  rotate.write(10);
}

void Leg::backward()
{
  rotate.write(10);
}

void Leg::up()
{
  lift.write(10);
}

void Leg::down()
{
  lift.write(10);
}
