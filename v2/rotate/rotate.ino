#include <Servo.h> // Include the servo library
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LSM9DS1.h>
#include <Adafruit_Sensor.h>

// create servo objects to control rotation for each leg
// front left
Servo rotate1;
// front right
Servo rotate2;
// back left
Servo rotate3;
// back right
Servo rotate4;

//set up sensor
Adafruit_LSM9DS1 lsm = Adafruit_LSM9DS1();
#define LSM9DS1_SCK A5
#define LSM9DS1_MISO 12
#define LSM9DS1_MOSI A4
#define LSM9DS1_XGCS 6
#define LSM9DS1_MCS 5

int bAngle = -45; // backward angle
int servo_angle = bAngle;
int desired_angle = 45; // forward angle
int robot_angle = 0;

void setupSensor()
{
  lsm.setupAccel(lsm.LSM9DS1_ACCELRANGE_2G);
  lsm.setupMag(lsm.LSM9DS1_MAGGAIN_4GAUSS);
  lsm.setupGyro(lsm.LSM9DS1_GYROSCALE_245DPS);
}

int to1(int angle) {
  return angle + 135;
}

int to2(int angle) {
  return angle + 45;
}

int to3(int angle) {
  return angle + 135;
}

int to4(int angle) {
  return angle + 45;
}

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);

  // Try to initialise and warn if we couldn't detect the chip
  if (!lsm.begin())
  {
    Serial.println("Oops ... unable to initialize the LSM9DS1. Check your wiring!");
    while (1);
  }
  Serial.println("Found LSM9DS1 9DOF");
  setupSensor();
  
  rotate1.attach(2);
  rotate2.attach(3);
  rotate3.attach(4);
  rotate4.attach(5);

  // Slide all back
  rotate1.write(to1(bAngle));
  rotate2.write(to2(bAngle));
  rotate3.write(to3(bAngle));
  rotate4.write(to4(bAngle));
}

float getRobotAngle() {
  //get a new sensor event
  sensors_event_t a, m, g, temp;
  lsm.getEvent(&a, &m, &g, &temp); 

  float x_accel = a.acceleration.x;
  float y_accel = a.acceleration.y;
  float z_accel = a.acceleration.z;

  float y_ratio = y_accel/(-9.8*1.04); 
  float current_angle = acos(y_ratio)*180/M_PI; 

  return current_angle;
}

void loop() {
  Serial.println("start");

  robot_angle = getRobotAngle();

  if (robot_angle < desired angle) {
    while (robot_angle <= desired_angle) {
      rotate1.write(to1(servo_angle));
      rotate2.write(to2(servo_angle));
      rotate3.write(to3(servo_angle));
      rotate4.write(to4(servo_angle)); 
      servo_angle += 3;
      robot_angle = getRobotAngle();
    }
  } else {
    while (robot_angle >= desired_angle) {
      rotate1.write(to1(servo_angle));
      rotate2.write(to2(servo_angle));
      rotate3.write(to3(servo_angle));
      rotate4.write(to4(servo_angle)); 
      servo_angle += 3;
      robot_angle = getRobotAngle();
    }
  }

  while (1) {}
}
