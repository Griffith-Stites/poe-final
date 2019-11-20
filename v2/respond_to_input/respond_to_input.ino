#include <Servo.h>
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

int bAngle = -30; // backward angle for walking
int fAngle = 30; // forward angle for walking

int magOn = 180; // mag on angle
int magOff = 0; // mag off angle

int userInput = 0;
int prevUserInput = 0;
int setAngle = -45; // starting angle for rotation

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

int getUserInput() {
  Serial.println("in getUserInput");
  userInput = 0;
  int input = 0;
  while (true) {
    // read the incoming byte:
    int incomingByte = Serial.read();
    Serial.print("incomingByte is "); Serial.println(incomingByte);
    // leave the loop if return character is received
    if (incomingByte == 10){
      break;
    }
   
    int byteInInt = incomingByte -48;  //-48 converts between ASCII and integers
    Serial.print("byteInInt is "); Serial.println(byteInInt);
   
    // put previous byte in the 10s place
    userInput = 10*userInput + byteInInt;
    Serial.print("userInput is "); Serial.println(userInput);
  }
  Serial.print("Final userInput is "); Serial.println(userInput);
  return userInput;
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

void setToWalk() {
  mag1.write(magOff);
  mag4.write(magOff);
  delay(1000);
  
  rotate1.write(to13w(bAngle));
  rotate4.write(to24w(bAngle));
  delay(1000);

  mag1.write(magOn);
  mag4.write(magOn);
  delay(1000);
  
  mag2.write(magOff);
  mag3.write(magOff);
  delay(1000);
  
  rotate2.write(to24w(fAngle));
  rotate3.write(to13w(fAngle));
  delay(1000);

  mag2.write(magOn);
  mag3.write(magOn);
  delay(1000);
  mag1.write(magOff);
  mag4.write(magOff);
  delay(1000);
}

void walkStraight(int prevUserInput) {
  //check for entering walking mode
  if (prevUserInput != 100) {
    setToWalk();
  }
  
  rotate1.write(to13w(fAngle));
  rotate2.write(to24w(bAngle));
  rotate3.write(to13w(bAngle));
  rotate4.write(to24w(fAngle));
  
  delay(1000);
  mag1.write(magOn);
  mag4.write(magOn);
  delay(1000);
  mag2.write(magOff);
  mag3.write(magOff);
  delay(1000);
  
  rotate1.write(to13w(bAngle));
  rotate2.write(to24w(fAngle));
  rotate3.write(to13w(fAngle));
  rotate4.write(to24w(bAngle));
  delay(1000);
  
  mag2.write(magOn);
  mag3.write(magOn);
  delay(1000);
  mag1.write(magOff);
  mag4.write(magOff);
  delay(1000);
}

void setToRotate(int desired_angle) {
  Serial.println("Attempting to enter starting position");
  int robot_angle = getRobotAngle();
  Serial.print("robot_angle (in setToRotate) is "); Serial.println(robot_angle);
  Serial.print("desired_angle is "); Serial.println(desired_angle);
  if (robot_angle < desired_angle) { 
    setAngle = -setAngle; 
  }
  Serial.print("setAngle is "); Serial.println(setAngle);
  
  mag1.write(magOff);
  delay(500);
  rotate1.write(to14r(setAngle));
  delay(1000);
  mag1.write(magOn);
  delay(500);
  
  mag2.write(magOff);
  delay(500);
  rotate2.write(to23r(setAngle));
  delay(1000);
  mag2.write(magOn);
  delay(500);

  mag3.write(magOff);
  delay(500);
  rotate3.write(to23r(setAngle));
  delay(1000);
  mag3.write(magOn);
  delay(500);

  mag4.write(magOff);
  delay(500);
  rotate4.write(to14r(setAngle));
  delay(1000);
  mag4.write(magOn);
  delay(500);
  
  Serial.println("Starting position reached");
}

void rotate(int desired_angle) {
  setToRotate(desired_angle);
  
  Serial.println("Starting rotation");

  int robot_angle = getRobotAngle();
  Serial.print("robot_angle (in rotate) is "); Serial.println(robot_angle);
  int servo_angle = setAngle;

  if (robot_angle < desired_angle) {
    while (robot_angle <= desired_angle) {
      rotate1.write(to14r(servo_angle));
      rotate2.write(to23r(servo_angle));
      rotate3.write(to23r(servo_angle));
      rotate4.write(to14r(servo_angle)); 
      servo_angle -= 3;
      delay(200);
      robot_angle = getRobotAngle();
    }
  } else {
    while (robot_angle >= desired_angle) {
      Serial.print("Servo angle = "); Serial.println(servo_angle);
      rotate1.write(to14r(servo_angle));
      rotate2.write(to23r(servo_angle));
      rotate3.write(to23r(servo_angle));
      rotate4.write(to14r(servo_angle)); 
      servo_angle += 3;
      delay(200);
      robot_angle = getRobotAngle();
    }
  }
  Serial.println("MADE IT!");
  Serial.print("Desired angle = "); Serial.println(desired_angle);
  Serial.print("Current angle = "); Serial.println(robot_angle);
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

  Serial.println("Initializing legs...");

  mag1.write(magOff);
  mag2.write(magOff);
  mag3.write(magOff);
  mag4.write(magOff);
  delay(1000);

  rotate1.write(to14r(0));
  rotate2.write(to23r(0));
  rotate3.write(to23r(0));
  rotate4.write(to14r(0));
  Serial.println("PUT ON WALL");
  delay(3000);

  mag1.write(magOn);
  mag2.write(magOn);
  mag3.write(magOn);
  mag4.write(magOn);
  delay(1000);
}

void loop() {
  //check for user input
  if (Serial.available() > 0) {
     userInput = getUserInput();
  }

  switch(userInput) {
    case 0:
      break;
    case 100:
      Serial.println("Walking straight");
      walkStraight(prevUserInput);
      break;
    case 50:
      Serial.println("Turning to 20 degrees");
      rotate(20);
      userInput = 0;
    default:
      break;
  }

  prevUserInput = userInput;
}
