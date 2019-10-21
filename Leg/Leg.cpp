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
}

void Leg::forward()
{

}

void Leg::backward()
{

}

void Leg::up()
{

}

void Leg::down()
{

}
