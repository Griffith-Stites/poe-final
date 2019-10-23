/*
  Leg.h - Library for controlling a leg with two servo actuators
  Created by Maeve Stites, October 21, 2019.
*/

#ifndef Leg_h
#define Leg_h

#include "WProgram.h"

class Leg
{
  public: // can be accessed by code calling the class
    Leg(int liftPin, int rotatePin, int liftDirection, int rotateDirection, int liftZero, int rotateZero);
    void forward();
    void backward();
    void up();
    void down();
  private: // only within the class
    int _liftDirection;
    int _rotateDirection;
    int _liftZero;
    int _rotateZero;
};

#endif
