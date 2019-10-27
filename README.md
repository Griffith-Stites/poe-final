# poe-final
Repo for the code for our climby boiiii

## To Do
* Calibration script (press a button when the sweeping leg is perp to the robot - then we can specify how much we want toe leg to move on either side of that) - zero should be at 90

* Create legServo object? Then just pass both of those to leg???? Then that library can just tell the legServo to do that?

* Do not need separate up down, backward forward, functions. Just have tilt and rotate.

* New library for just managing a servo. Such that sending 10 degrees to all motors will send all of them forward to the same point (should have zero and direction knowledge)

* Instead of library just have an angle calc function in the file

## Adding Library
1. Compile Leg library into Zip: "zip -r Leg.zip ./Leg/"
2. Import into arduino: Sketch -> Include Library -> Add Zip Library

Alternatively, one can manually move the library cpp and h file into the arduino library folder (root-> arduino -> libraries)
