#include <Servo.h> // Include the servo library
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LSM9DS1.h>
#include <Adafruit_Sensor.h>

//set up sensor
Adafruit_LSM9DS1 lsm = Adafruit_LSM9DS1();
#define LSM9DS1_SCK A5
#define LSM9DS1_MISO 12
#define LSM9DS1_MOSI A4
#define LSM9DS1_XGCS 6
#define LSM9DS1_MCS 5

// create servo objects to control rotation and magnet for each leg
// front left
Servo rotate1;
Servo mag1;
// front right
Servo rotate2;
Servo mag2;
// back left
Servo rotate3;
Servo mag3;
// back right
Servo rotate4;
Servo mag4;

int max_angle = 25;
int dt = 1;

int flAngle = max_angle;
int frAngle = max_angle;
int blAngle = -max_angle;
int brAngle = -max_angle;

int desiredHeading = 0;
char userInput = ' ';

int magOn = 180; // mag on angle
int magOff = 0; // mag off angle

int to1(int angle) {
  return 45 -7 + angle;
}
int to2(int angle) {
  return 135 + 2 - angle;
}
int to3(int angle) {
  return 135 + 2 + angle;
}
int to4(int angle) {
  return 45 + 2 - angle;
}

void setupSensor() {
  // Try to initialise and warn if we couldn't detect the chip
  if (!lsm.begin())
  {
    Serial.println("Unable to initialize the LSM9DS1. Check your wiring!");
    while (1);
  }
  Serial.println("Found LSM9DS1 9DOF");
  lsm.setupAccel(lsm.LSM9DS1_ACCELRANGE_2G);
  lsm.setupMag(lsm.LSM9DS1_MAGGAIN_4GAUSS);
  lsm.setupGyro(lsm.LSM9DS1_GYROSCALE_245DPS);
}

float getRobotAngle() {
  //get a new sensor event
  sensors_event_t a, m, g, temp;
  lsm.getEvent(&a, &m, &g, &temp); 

  float y_accel = a.acceleration.y;

  float y_amt = y_accel/(9.6);
  if (y_amt < -1) {
    y_amt = -1;
  }
  if (y_amt > 1) {
    y_amt = 1;
  }
  float current_angle = asin(y_amt)*-180/M_PI;
  Serial.print("current angle = "); Serial.println(current_angle);

  return current_angle;
}

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);

  setupSensor();
  
  rotate1.attach(2);
  rotate2.attach(3);
  rotate3.attach(4);
  rotate4.attach(5);

  mag1.attach(10);
  mag2.attach(11);
  mag3.attach(12);
  mag4.attach(13);

  mag1.write(magOff);
  mag2.write(magOff);
  mag3.write(magOff);
  mag4.write(magOff);
}

void setWalkingAngles() {
  float robotAngle = getRobotAngle();
  Serial.print("robotAngle is "); Serial.println(robotAngle);
  Serial.print("desiredHeading is "); Serial.println(desiredHeading);
  float d = robotAngle - desiredHeading;
  Serial.print("d is "); Serial.println(d);
  
  brAngle = -(max_angle + d*dt);
  frAngle = max_angle + d*dt;
  blAngle = -(max_angle-d*dt);
  flAngle = max_angle - d*dt;
  if (brAngle > max_angle) {
    brAngle = max_angle;
  }
  if (frAngle > max_angle) {
    frAngle = max_angle;
  }
  if (blAngle > max_angle) {
    blAngle = max_angle;
  }
  if (flAngle > max_angle) {
    flAngle = max_angle;
  }

  if (brAngle < -max_angle) {
    brAngle = -max_angle;
  }
  if (frAngle < -max_angle) {
    brAngle = -max_angle;
  }
  if (blAngle < -max_angle) {
    blAngle = -max_angle;
  }
  if (flAngle < -max_angle) {
    flAngle = -max_angle;
  }
  Serial.print("brAngle = "); Serial.println(brAngle);
  Serial.print("frAngle = "); Serial.println(frAngle);
  Serial.print("blAngle = "); Serial.println(blAngle);
  Serial.print("flAngle = "); Serial.println(flAngle);
}

void getUserInput() {
  if (Serial.available() > 0) {
     // read the incoming byte:
     int incomingByte = Serial.read();
     if (incomingByte == 119) {
       userInput = 'w';
     }
     if (incomingByte == 97) {
       userInput = 'a';
     }
     if (incomingByte == 115) {
       userInput = 's';
     }
     if (incomingByte == 100) {
       userInput = 'd';
     }
     if (incomingByte == 32) {
       userInput = ' ';
     }
  }
  Serial.print("userInput = "); Serial.println(userInput);
}

void loop() {

  getUserInput();

  setWalkingAngles();
  
  rotate1.write(to1(flAngle));
  rotate2.write(to2(brAngle));
  rotate3.write(to3(blAngle));
  rotate4.write(to4(frAngle));
  
  delay(1000);
  mag1.write(magOn);
  mag4.write(magOn);
  delay(1000);
  mag2.write(magOff);
  mag3.write(magOff);
  delay(1000);

  setWalkingAngles();
  
  rotate1.write(to1(blAngle));
  rotate2.write(to2(frAngle));
  rotate3.write(to3(flAngle));
  rotate4.write(to4(brAngle));
  
  delay(1000);
  mag2.write(magOn);
  mag3.write(magOn);
  delay(1000);
  mag1.write(magOff);
  mag4.write(magOff);
  delay(1000);
}
