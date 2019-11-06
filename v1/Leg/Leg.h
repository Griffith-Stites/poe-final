/*
  Leg.h - Library for controlling a leg with two servo actuators
  Created by Maeve Stites, October 21, 2019.
*/

#ifndef Leg_h
#define Leg_h

#include "Arduino.h"
#include "Servo.h" // do I need to include servo in my header file?

class Leg
{
  public: // can be accessed by code calling the class
    Leg(int liftPin, int liftZero, int liftDirection, int rotatePin, int rotateZero, int rotateDirection);
    void forward(int angle);
    void backward(int angle);
    void up(int angle);
    void down(int angle);
  private: // only within the class
    int _liftDirection;
    int _rotateDirection;
    int _liftZero;
    int _rotateZero;
    Servo _lift;
    Servo _rotate;
    int _angleCalc(int _zero, int _desired, int _d);
};

#endif
