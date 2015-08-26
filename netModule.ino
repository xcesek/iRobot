/* ==================================================================================
 *  iRobot - simple robot module
 *
 *  Simple program that changes moods and shows it via led state
 * for more info, see http://jeelabs.net/pub/docs/ethercard/
 *
 *  August 2015
 *  By Pavol Cesek
 *  ================================================================================== */
 
 /* ==================================================================================
 *  iRobot - simple robot module
 *
 *  Simple program that measures voice level and temperature and sends data to a dedicated server
 *
 *  August 2015
 *  By Pavol Cesek
 *  ================================================================================== */

#include <EtherCard.h>


void initNet() {
  Serial.println(F("Initializing ethernet interface..."));
  
  if (ether.begin(sizeof Ethernet::buffer, mymac) == 0) {
    Serial.println(F("Failed to access Ethernet controller"));
  }
  
  if (!ether.dhcpSetup()) {
    Serial.println(F("DHCP failed"));
  }
  
  if (!ether.dnsLookup(website)) {
    Serial.println(F("DNS failed"));
  }

  ether.printIp("IP:  ", ether.myip);
  ether.printIp("GW:  ", ether.gwip);  
  ether.printIp("DNS: ", ether.dnsip);  
  ether.printIp("SRV: ", ether.hisip);
  
   Serial.println(F("Net module initialized!"));
  
}

void listenForData() {
  ether.packetLoop(ether.packetReceive());
}

void sendData () {
   if (debug) {
    Serial.println(F("Sending data to server..... "));
  }
  ether.browseUrl(PSTR("/weather-station/index.jsp?d=7&t=5&r=78"), "", website, my_callback);
}

// called when the client request is complete
static void my_callback (byte status, word off, word len) {
  Serial.println(F(" == Server respond START == "));
  Ethernet::buffer[off+len] = 0;
  Serial.print((const char*) Ethernet::buffer + off);
  Serial.println(F(" == Server respond END == "));
}

