/*
  ServoCal.cpp - Library for controlling a servo in a standardized and uniform way,
  with a zero and noted spin direction.
  Created by Maeve Stites, October 27, 2019.
*/

#include "Arduino.h"
#include "Servo.h"
#include "ServoCal.h"

Servo _motor;

ServoCal::ServoCal(int pin, int zero, int dir)
{
  /*
  pin: pin for the servo
  zero: the zero angle of the servo
  dir: -1 or 1 to flip the direction of the servo
  */
  _motor.attach(liftPin);
  _zero = zero;
  _dir = dir;
}

void ServoCal::write(int angle)
{
  _motor.write(ServoCal::_angleCalc(_zero, angle, _dir));
}

int ServoCal::_angleCalc(int _zero, int _desired, int _d)
{
/*
calculates angle
_zero: zero angle
_desired: desired angle
_d: turning direction of the Servo
*/
int _angle = _zero + (_d*_desired);
// move math inside other stuff
return _angle;
}
