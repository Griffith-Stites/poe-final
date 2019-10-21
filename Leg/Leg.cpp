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
  _liftDirection = liftDirection;
  _rotateDirection = rotateDirection;
  _liftZero = liftZero;
  _rotateZero = rotateZero;
}

void Leg::forward()
{
  rotate.write(angleCalc(_rotateZero, 10, _rotateDirection));
}

void Leg::backward()
{
  rotate.write(angleCalc(_rotateZero, -10, _rotateDirection));
}

void Leg::up()
{
  lift.write(angleCalc(_liftZero, 10, _liftDirection));
}

void Leg::down()
{
  lift.write(angleCalc(_liftZero, 10, _liftDirection));
}

int Leg::angleCalc(int _zero, int _desired, int _d)
{
/*
calculates angle
_zero: zero angle
_desired: desired angle
_d: turning direction of the Servo
*/
int _angle = _zero + (_d*_desired);
return _angle;
}
