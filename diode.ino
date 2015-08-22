/* ==================================================================================
 *  Robot
 *  Only a very first working version
 *
 *  By Pavol Cesek
 *  ================================================================================== */

void turnOnRedLed() {
  digitalWrite(ledPinG, LOW);
  digitalWrite(ledPinB, LOW);
  digitalWrite(ledPinR, HIGH);
}

void turnOfRedLed() {
  digitalWrite(ledPinR, LOW);
}

void turnOnGreenLed() {
  digitalWrite(ledPinR, LOW);
  digitalWrite(ledPinB, LOW);
  digitalWrite(ledPinG, HIGH);
}

void turnOfGreenLed() {
  digitalWrite(ledPinG, LOW);
}

void turnOnBlueLed() {
  digitalWrite(ledPinR, LOW);
  digitalWrite(ledPinG, LOW);
  digitalWrite(ledPinB, HIGH);
}

void turnOfBlueLed() {
  digitalWrite(ledPinB, LOW);
}

void   turnOfAllLeds() {
  turnOfRedLed();
  turnOfGreenLed();
  turnOfBlueLed();
}


void initDiode() {
  pinMode(ledPinR, OUTPUT);
  pinMode(ledPinG, OUTPUT);
  pinMode(ledPinB, OUTPUT);
  turnOnRedLed();
  delay(300);
  turnOfAllLeds();
  turnOnGreenLed();
  delay(300);
  turnOfAllLeds();
  turnOnBlueLed();
  delay(500);
  turnOfAllLeds();
  Serial.println(" - Led diode initialized");
}
