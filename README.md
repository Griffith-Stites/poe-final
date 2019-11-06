# poe-final
Repo for the code for our climby boiiii

## To Do
* Calibration script (press a button when the sweeping leg is perp to the robot - then we can specify how much we want toe leg to move on either side of that) - zero should be at 90

* Way to track zeros, direction, etc

* Library for new robot. Should be able to take an accelerometer input and turn to an angle.

Turning: Release them, slide them, attach them, move

## Adding Library
1. Compile Leg library into Zip: "zip -r Leg.zip ./Leg/"
2. Import into arduino: Sketch -> Include Library -> Add Zip Library

Alternatively, one can manually move the library cpp and h file into the arduino library folder (root-> arduino -> libraries)
