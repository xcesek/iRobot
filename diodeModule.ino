/* ==================================================================================
 *  iRobot - simple robot module
 *
 *  Diode helper funcions
 *
 *  ================================================================================== */
 

void initDiode() {
  pinMode(R_PIN, OUTPUT);
  pinMode(G_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);
  
  Serial.println(F("Diode initialized!"));
}

void setColor(byte r, byte g, byte b) { 
  analogWrite(R_PIN, r);
  analogWrite(G_PIN, g);
  analogWrite(B_PIN, b);
}

void shiftColor(byte shift) {
  if (shift == 0) {
    setColor(1, 0, 0);
  } else if (shift == 1) {
    setColor(0, 1, 0);
  } else if (shift == 2) {
    setColor(0, 0, 1);
  }    
}

