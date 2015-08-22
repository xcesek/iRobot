/* ==================================================================================
 *  Robot
 *  Only a very first working version
 *
 *  By Pavol Cesek
 *  ================================================================================== */
 
 void initUltrasonic() {
   pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.println(" - Ultrasonic pins initialized");
 }
 
 int readDistacne() {
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  //Calculate the distance (in cm) based on the speed of sound.
  distance = duration / 58.2;
  distance = (distance > infSensorMaxDist) ? infSensorMaxDist : distance;
  if (debug) {
    Serial.print("Measured ditance: ");
    Serial.print(distance);
    Serial.print(" -- ");
    Serial.println(duration / 58.2);
  }

  return distance;
}
