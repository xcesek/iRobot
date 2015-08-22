/* ==================================================================================
 *  Robot
 *  Only a very first working version
 *
 *  By Pavol Cesek
 *  ================================================================================== */
 
 #define rotationMillis 2000
 
void  initMotors() {
  pinMode(dir1PinA, OUTPUT);
  pinMode(dir2PinA, OUTPUT);
  pinMode(speedPinA, OUTPUT);
  pinMode(dir1PinB, OUTPUT);
  pinMode(dir2PinB, OUTPUT);
  pinMode(speedPinB, OUTPUT);
  speed = 255;
  Serial.println(" - motor pins initialized");
}
 
 void goStraight() {
  analogWrite(speedPinA, speed);
  analogWrite(speedPinB, speed);

  digitalWrite(dir1PinA, HIGH);
  digitalWrite(dir2PinA, LOW);

  digitalWrite(dir1PinB, HIGH);
  digitalWrite(dir2PinB, LOW);
  
  if (debug) {
    Serial.println("Motors moving straight");
  }
}

void goBack() {
  analogWrite(speedPinA, speed);
  analogWrite(speedPinB, speed);

  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir2PinA, HIGH);

  digitalWrite(dir1PinB, LOW);
  digitalWrite(dir2PinB, HIGH);
  
  if (debug) {
    Serial.println("Motors moving back");
  }
}

void turnLeft() {
  analogWrite(speedPinA, speed);
  analogWrite(speedPinB, speed);

  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir2PinA, HIGH);

  digitalWrite(dir1PinB, HIGH);
  digitalWrite(dir2PinB, LOW);
  
  delay(rotationMillis);
  
  if (debug) {
    Serial.println("Motors moving left");
  }
}

void turnRight() {
  analogWrite(speedPinA, speed);
  analogWrite(speedPinB, speed);

  digitalWrite(dir1PinA, HIGH);
  digitalWrite(dir2PinA, LOW);

  digitalWrite(dir1PinB, LOW);
  digitalWrite(dir2PinB, HIGH);
  
  delay(rotationMillis);
  
  if (debug) {
    Serial.println("Motors moving right");
  }
}

void stopMoving() {
  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir2PinA, LOW);

  digitalWrite(dir1PinB, LOW);
  digitalWrite(dir2PinB, LOW);
  
  if (debug) {
    Serial.println("Motors stopped");
  }
}

