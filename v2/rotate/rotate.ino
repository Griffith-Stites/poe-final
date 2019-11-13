#include <Servo.h> // Include the servo library
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LSM9DS1.h>
#include <Adafruit_Sensor.h>

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

//set up sensor
Adafruit_LSM9DS1 lsm = Adafruit_LSM9DS1();
#define LSM9DS1_SCK A5
#define LSM9DS1_MISO 12
#define LSM9DS1_MOSI A4
#define LSM9DS1_XGCS 6
#define LSM9DS1_MCS 5

int bAngle = -45; // backward angle
int desired_angle = -20; // forward angle
int robot_angle = 0;

int magOn = 180; // mag on angle
int magOff = 0; // mag off angle

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
  return angle + 45;
}

int to4(int angle) {
  return angle + 135;
}

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);

  // Try to initialise and warn if we couldn't detect the chip
  if (!lsm.begin())
  {
    Serial.println("Unable to initialize the LSM9DS1. Check your wiring!");
    while (1);
  }
  Serial.println("Found LSM9DS1 9DOF");
  setupSensor();
  
  rotate1.attach(2);
  rotate2.attach(3);
  rotate3.attach(4);
  rotate4.attach(5);

  mag1.attach(10);
  mag2.attach(11);
  mag3.attach(12);
  mag4.attach(13);

  mag1.write(magOn);
  mag2.write(magOn);
  mag3.write(magOn);
  mag4.write(magOn);

//  robot_angle = getRobotAngle();
  robot_angle = 0;

  Serial.println("Initializing legs...");
  rotate1.write(to1(0));
  rotate2.write(to2(0));
  rotate3.write(to3(0));
  rotate4.write(to4(0));
  Serial.println("PUT ON WALL");
  Serial.println("");
  delay(3000);
}

float getRobotAngle() {
  //get a new sensor event
  sensors_event_t a, m, g, temp;
  lsm.getEvent(&a, &m, &g, &temp); 

  float x_accel = a.acceleration.x;

  Serial.print("x_accel = "); Serial.println(x_accel);
  float x_amt = x_accel/(10);
  Serial.print("x_amt = "); Serial.println(x_amt);
  if (x_amt < -1) {
    x_amt = -1;
  }
  if (x_amt > 1) {
    x_amt = 1;
  }
  float current_angle = asin(x_amt)*-180/M_PI;
  Serial.print("current angle = "); Serial.println(current_angle);
  Serial.println("");

  return current_angle;
}

void enterStartingPosition() {
  Serial.println("Attempting to enter starting position");
  if (robot_angle < desired_angle) { 
    bAngle = -bAngle; 
  }
  
  mag1.write(magOff);
  delay(500);
  rotate1.write(to1(bAngle));
  delay(1000);
  mag1.write(magOn);
  delay(500);
  
  mag2.write(magOff);
  delay(500);
  rotate2.write(to2(bAngle));
  delay(1000);
  mag2.write(magOn);
  delay(500);

  mag3.write(magOff);
  delay(500);
  rotate3.write(to3(bAngle));
  delay(1000);
  mag3.write(magOn);
  delay(500);

  mag4.write(magOff);
  delay(500);
  rotate4.write(to4(bAngle));
  delay(1000);
  mag4.write(magOn);
  delay(500);
  
  Serial.println("Starting position reached");
  Serial.println("");
}

void loop() {
  enterStartingPosition();
  
  Serial.println("Starting rotation");

//  robot_angle = getRobotAngle();
  int servo_angle = bAngle;
  robot_angle = 0;

  if (robot_angle < desired_angle) {
    while (robot_angle <= desired_angle) {
      Serial.print("Servo angle = "); Serial.println(servo_angle);
      Serial.println(to1(servo_angle));
      rotate1.write(to1(servo_angle));
      rotate2.write(to2(servo_angle));
      rotate3.write(to3(servo_angle));
      rotate4.write(to4(servo_angle)); 
      servo_angle -= 3;
      delay(200);
      robot_angle = getRobotAngle();
    }
  } else {
    while (robot_angle >= desired_angle) {
      Serial.print("Servo angle = "); Serial.println(servo_angle);
      rotate1.write(to1(servo_angle));
      rotate2.write(to2(servo_angle));
      rotate3.write(to3(servo_angle));
      rotate4.write(to4(servo_angle)); 
      servo_angle += 3;
      delay(200);
      robot_angle = getRobotAngle();
    }
  }
  
  Serial.println("MADE IT!");
  Serial.print("Desired angle = "); Serial.println(desired_angle);
  Serial.print("Current angle = "); Serial.println(robot_angle);
  while (1) {}
}
