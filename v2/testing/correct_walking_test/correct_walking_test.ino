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

int lAngle = 30; // left angle
int rAngle = 30; // forward angle (right)

int flAngle = lAngle;
int frAngle = rAngle;
int blAngle = -lAngle;
int brAngle = -rAngle;

int walkingAngle = 0;

int magOn = 180; // mag on angle
int magOff = 0; // mag off angle

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

  float x_accel = a.acceleration.x;

  float x_amt = x_accel/(10);
  if (x_amt < -1) {
    x_amt = -1;
  }
  if (x_amt > 1) {
    x_amt = 1;
  }
  float current_angle = asin(x_amt)*-180/M_PI;
  Serial.print("current angle = "); Serial.println(current_angle);

  return current_angle;
}

//funcs to convert intuitive angles to servo angles
int to13w(int angle) {
  return 90 + angle;
}
int to24w(int angle) {
  return 90 - angle;
}
int to14r(int angle) {
  return angle + 135;
}
int to23r(int angle) {
  return angle + 45;
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

  rotate1.write(to13w(blAngle));
  rotate2.write(to24w(frAngle));
  rotate3.write(to13w(flAngle));
  rotate4.write(to24w(brAngle));

  Serial.println("PUT ON WALL");
  delay(3000);

  mag2.write(magOn);
  mag3.write(magOn);
  delay(1000);
  Serial.println("Start");
}

void loop() {
  float robotAngle = getRobotAngle();
  Serial.print("robotAngle is "); Serial.println(robotAngle);
  float angleDifference = robotAngle - walkingAngle;
  Serial.print("angleDifference is "); Serial.println(angleDifference);
  if (angleDifference > 30) {
    angleDifference = 30;
  }
  if (angleDifference < -30) {
    angleDifference = -30;
  }
  if (angleDifference > 0) {
    Serial.println("Angle difference is greater than 0");
    Serial.println("Turning left");
    Serial.println("");
    frAngle = 30;
    brAngle = -30;
    flAngle = 30 - .5*angleDifference;
    blAngle = .5*angleDifference - 30;
  }
  if (angleDifference < 0) {
    Serial.println("Angle difference is less than 0");
    Serial.println("Turning right");
    Serial.println("");
    frAngle = 30 + .5*angleDifference;
    brAngle = -(30+.5*angleDifference);
    flAngle = 30;
    blAngle = -30;
  }
  
  rotate1.write(to13w(flAngle));
  rotate2.write(to24w(brAngle));
  rotate3.write(to13w(blAngle));
  rotate4.write(to24w(frAngle));
  
  delay(1000);
  mag1.write(magOn);
  mag4.write(magOn);
  delay(1000);
  mag2.write(magOff);
  mag3.write(magOff);
  delay(1000);
  
  rotate1.write(to13w(blAngle));
  rotate2.write(to24w(frAngle));
  rotate3.write(to13w(flAngle));
  rotate4.write(to24w(brAngle));
  
  delay(1000);
  mag2.write(magOn);
  mag3.write(magOn);
  delay(1000);
  mag1.write(magOff);
  mag4.write(magOff);
  delay(1000);
}
