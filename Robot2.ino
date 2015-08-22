/* ==================================================================================
 *  Robot
 *  Only a very first working version
 *
 *  By Pavol Cesek
 *  ================================================================================== */

#include <Servo.h>
#include <math.h>
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif



#define infSensorMaxDist 200
#define dangerousDistance 20
#define goalDir 10.0
#define debug 1



/* ============== Global variables ============== */
// Pins
#define ledPinR 1
#define mpuIntPin 2
#define echoPin 3
#define trigPin 4
#define ledPinG 5
#define ledPinB 6
#define servoPin 7

#define dir2PinB 8
#define speedPinB 9
#define speedPinA 10
#define dir1PinB 11
#define dir2PinA 12
#define dir1PinA 13


// other global variables
Servo myservo;
MPU6050 mpu;

unsigned long time;
int speed = 0;
int pos = 0;
int sthIsNear = 0;

int distance = 0;
int temperature = 0;
double xDir;


/* =================================================================== Functions ================================================================================ */

void updateSensors() {
  distance = readDistacne();
  temperature = readTherm();
  xDir = readXDir();
}

void takeAction() {
  int dist1, dist2;
  
  turnOfAllLeds();
  turnOnBlueLed();
  
  
  
  if (distance < dangerousDistance) {
    turnOfAllLeds();
    turnOnGreenLed();
    
    stopMoving();
    
    lookRight();
    delay(300);
    dist1 = readDistacne();

    lookLeft();
    delay(300);
    dist2 = readDistacne();
    
    lookAhead();
    delay(300);
    
    if (dist1 < dist2) turnRight();
    else turnLeft();
  } else {
    goStraight();
  }

}

void rotateUntilRightDirection() {
  double dir;
  
  turnOfAllLeds();
  dir = readXDir();
  
  while (1) {
    turnRight();
    
    if ((abs(10.0 - dir) < 3.0)) {
      turnOnGreenLed();
      turnOnBlueLed();
      delay(2000);
      break;
    }
  }
  
}



/* =================================================================== Main Setup ================================================================================ */

void setup() {
  Serial.begin(9600);
  Serial.println(" === Startup sequence sequence ===");

  initDiode();
  initMotors();
  initServo();
  initUltrasonic();
  initMyMpu();

  time = millis();

  turnOfAllLeds();
  turnOnBlueLed();
  Serial.println(" === Startup sequence finished ===");
}



/* =================================================================== Main Loop ================================================================================ */

void loop() {
  updateSensors();
  takeAction();
}
