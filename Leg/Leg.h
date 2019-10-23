/*
  Leg.h - Library for controlling a leg with two servo actuators
  Created by Maeve Stites, October 21, 2019.
*/

#ifndef Leg_h
#define Leg_h

#include "Arduino.h"

class Leg
{
  public: // can be accessed by code calling the class
    Leg(int liftPin, int rotatePin, int liftDirection, int rotateDirection, int liftZero, int rotateZero);
    void forward(int angle);
    void backward(int angle);
    void up(int angle);
    void down(int angle);
  private: // only within the class
    int _liftDirection;
    int _rotateDirection;
    int _liftZero;
    int _rotateZero;
    int _angleCalc(int _zero, int _desired, int _d);
};

#endif
