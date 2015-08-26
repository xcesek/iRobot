const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)

void initMic() {
  Serial.println(F("Mic module initialized!"));
}


int collectSoundData() {
  unsigned int sample;
  unsigned long startMillis = millis(); // Start of sample window
  unsigned int peakToPeak = 0;   // peak-to-peak level

  unsigned int signalMax = 0;
  unsigned int signalMin = 1024;

  while (millis() - startMillis < sampleWindow) {
    sample = analogRead(0);
    if (sample < 1024) {  // toss out strange readings
      if (sample > signalMax) {
        signalMax = sample;  // save just the max levels
      } else if (sample < signalMin) {
        signalMin = sample;  // save just the min levels
      }
    }
  }
  peakToPeak = signalMax - signalMin;
  
  if (debug) {
    Serial.print(F("Microphone sound level: ")); Serial.println(peakToPeak);
  }

  return peakToPeak;
}
