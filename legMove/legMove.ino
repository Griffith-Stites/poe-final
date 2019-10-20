#include <Servo.h> // Include the servo library

// These constants won't change. They're used to give names to the pins used:
const int liftPin = 6; // Digital output pin for the servo angle signal
const int rotatePin = 5; // Digital output pin for the servo angle signal

// int lift = 0; // variable to store the lift angle
// int rotate = 0; // variable to store the rotation angle

int liftStatus = 0; // variable to store lift status (0: ground, 1: air)
int rotateStatus = 0; // variable to store rotate status

Servo servoLift;  // create servo object to control pan servo
Servo servoRotate; // create servo object to control tilt servo

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  servoLift.attach(liftPin);
  servoRotate.attach(rotatePin);
}

void loop() {
  Serial.println("start");
  walk();
  delay(3000);
}

void liftLeg(){
  if (liftStatus == 0){ // lift up
    servoLift.write(10);
    liftStatus = 1;
  }
  else { // put down
    servoLift.write(0);
    liftStatus = 0;
  }
}

void rotateLeg(){

}

void walk(){
  lift = 10;
  servoLift.write(lift); // lift leg
  rotate = 10;
  servoRotate.write(rotate); // move leg forward
  lift = 0;
  servoLift.write(lift); // put down leg
}

void printStatus(int sensor, int pan, int tilt) {
  // print the results to the Serial Monitor:
  Serial.print(sensorValue);
  Serial.print(',');
  Serial.print(pan);
  Serial.print(',');
  Serial.print(tilt);
  Serial.println();
}
