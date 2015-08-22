/* ==================================================================================
 *  Robot
 *  Only a very first working version
 *
 *  By Pavol Cesek
 *  ================================================================================== */
 
 void initServo() {
    myservo.attach(servoPin);
  Serial.println(" - servo pin initialized");
  calibrateServo();
  Serial.println(" - servo initialized");
 }
 
int lookRight(int step) {
   lookToPos(pos - step);          
}

int lookLeft(int step) {
  lookToPos(pos + step);    
}

int lookRight() {
   lookToPos(180);          
}

int lookLeft() {
  lookToPos(0);    
}

void lookAhead() {
  lookToPos(90);            
}

int lookToPos(int newPos) {
  pos = (newPos > 180) ? 180 : newPos;
  pos = (newPos < 0  ) ?   0 : newPos;  
  myservo.write(pos);
  if (debug) {  
    Serial.print("moving servo to position ");
    Serial.println(pos);      
  }     
  delay(100);           
}

void calibrateServo() {
  lookToPos(0);
  delay(800);
  lookToPos(180);
  delay(800);
  lookAhead();
  delay(800);
}


