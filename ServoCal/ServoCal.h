/*
  Leg.h - Library for controlling a leg with two servo actuators
  Created by Maeve Stites, October 21, 2019.
*/

#ifndef ServoCal_h
#define ServoCal_h

#include "Arduino.h"

class Leg
{
  public: // can be accessed by code calling the class
    ServoCal(int pin, int zero, int dir);
    void write(int angle);
  private: // only within the class
    int _pin;
    int _zero;
    int _dir;
    Servo motor;
    int _angleCalc(int _zero, int _desired, int _d);
};

#endif
