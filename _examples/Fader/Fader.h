/*
 * Fader
 * Version 0.1 October, 2015
 * Copyright 2015 Alan Zucconi
 * wwww.alanzucconi.com
 *
 */

#ifndef Fader_h
#define Fader_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#include "WConstants.h"
#endif

// Results returned from the decoder
class Fader {
  public:
    Fader(float initial);
    
    void fadeTo(float value, unsigned long duration);
    float getFade();

  private:
    unsigned long _startTime;
    float _startValue; // Start from this value

    unsigned long _stopTime;
    float _stopValue;   // Stop at this value

    float lerp(float m1, float M1, float m2, float M2, float v1);
};

#endif