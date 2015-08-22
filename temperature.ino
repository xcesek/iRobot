/* ==================================================================================
 *  Robot
 *  Only a very first working version
 *
 *  By Pavol Cesek
 *  ================================================================================== */


int readTherm() {
  return thermistor(analogRead(0)); 
}

double thermistor(int RawADC) {
double Temp;
 Temp = log(10000.0*((1024.0/RawADC-1))); 
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15;            // Convert Kelvin to Celcius
 //Temp = (Temp * 9.0)/ 4.89 + 32.0; // Convert Celcius to Fahrenheit

 
 if (debug) {  
    Serial.print("Measured temperature "); Serial.println(Temp);      
  }     
  
 return Temp;
}
