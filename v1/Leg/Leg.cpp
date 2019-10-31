/*
  Leg.cpp - Library for controlling a leg with two servo actuators
  Created by Maeve Stites, October 21, 2019.
*/

#include "Arduino.h"
#include "Servo.h"
#include "Leg.h"

Servo _lift;
Servo _rotate;

Leg::Leg(int liftPin, int liftZero, int liftDirection,
  int rotatePin, int rotateZero, int rotateDirection)
{
  /*
  liftPin: pin for the servo that lifts the leg
  rotatePin: pin for the servo that rotates the leg
  liftDirection: -1 or 1 to flip the direction of the servo
  rotateDirection: -1 or 1 to flip the direction of the servo
  liftZero: the zero angle of the lift servo
  rotateZero: the zero angle of the rotate servo
  */
  _lift.attach(liftPin);
  _rotate.attach(rotatePin);
  _liftDirection = liftDirection;
  _rotateDirection = rotateDirection;
  _liftZero = liftZero;
  _rotateZero = rotateZero;
  Serial.println("initializing");
}

void Leg::forward(int angle)
{
  _rotate.write(Leg::_angleCalc(_rotateZero, angle, _rotateDirection));
  Serial.println("forward");
}

void Leg::backward(int angle)
{
  _rotate.write(Leg::_angleCalc(_rotateZero, angle, _rotateDirection));
  Serial.println("backward");
}

void Leg::up(int angle)
{
  _lift.write(Leg::_angleCalc(_liftZero, angle, _liftDirection));
  Serial.println("up");
}

void Leg::down(int angle)
{
  _lift.write(Leg::_angleCalc(_liftZero, angle, _liftDirection));
  Serial.println("down");
}

int Leg::_angleCalc(int _zero, int _desired, int _d)
{
/*
calculates angle
_zero: zero angle
_desired: desired angle
_d: turning direction of the Servo
*/
int _angle = _zero + (_d*_desired);
Serial.println("angleCalc");
Serial.println(_angle);
// move math inside other stuff
return _angle;
}
