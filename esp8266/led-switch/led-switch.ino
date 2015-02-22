#include<stdlib.h>
#include <SoftwareSerial.h>

#define SSID ""
#define PASS ""
#define IP "192.168.1.75"
SoftwareSerial monitor(0, 1); // RX, TX

void setup() {
  // put your setup code here, to run once:
  monitor.begin(9600);
  Serial.begin(9600);
  sendDebug("AT");
  delay(5000);
  if(Serial.find("OK")){
    monitor.println("RECEIVED: OK");
    // connectWiFi();
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}

void sendDebug(String cmd){
  monitor.print("SEND: ");
  monitor.println(cmd);
  Serial.println(cmd);
}
