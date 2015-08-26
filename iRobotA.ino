/* ==================================================================================
 *  iRobot - simple robot module
 *
 *  Simple program that measures voice level and temperature and sends data to a dedicated server
 *
 *  August 2015
 *  By Pavol Cesek
 *  ================================================================================== */

#include <Time.h>
#include <EtherCard.h>
#include <TimeAlarms.h>

#define DEFAUL_LOOP_DEALY 1000
#define DEFAUL_USER_INPUT_TIMEOUT 1000
#define R_PIN 6
#define G_PIN 5
#define B_PIN 4
#define debug 1


/* ========================================================== Global variables ========================================================== */
static byte mymac[] = { 0x70,0x5A,0xB6,0xEE,0x00,0xBD };  //{ 0x2C,0x41,0x38,0x02,0x64,0x70 };
byte Ethernet::buffer[700];
const char PROGMEM website[]  = "isarfia.cloudapp.net";
static uint32_t timer;
int soundLevel;
byte temperature;


/* ========================================================== Program setup ========================================================== */
void setup () {
  Serial.begin(9600);
  Serial.println(F("Startup sequence started..."));
  
  initTimer();
  initDiode();
  initTemp();
  initMic();
  initNet();
  timer = millis(); 

//  Alarm.alarmRepeat(0, 0, 0, regularJob);  
  Alarm.timerRepeat(15, regularJob);
  
  Serial.println(F("Startup sequence finished!"));
}


/* ========================================================== Program main loop ========================================================== */
void loop () {
  
  
  listenForData();
  
  if (millis() > timer) {
    timer = millis() + 1000;
    soundLevel = collectSoundData();
    temperature = readTherm();
    
    shiftColor(timer % 3);
    digitalClockDisplay();
  }

  Alarm.delay(1);
}


/* ========================================================== Functions ========================================================== */
void regularJob() {
  Serial.println(F("regularJob invoked"));
}

