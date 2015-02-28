#include<stdlib.h>
#include <SoftwareSerial.h>

#define SSID ""
#define PASS ""
#define IP "192.168.1.75"
SoftwareSerial espy(10, 11); // RX, TX

String COMMAND_ON = "ON";
String COMMAND_OFF= "OFF";

int ledPin = 13;
int indicatorPin = 5;
bool connected = false;

void setup() {
  pinMode(ledPin, OUTPUT);

  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Starting");
  espy.begin(9600);
  espy.println("AT");
  delay(1000);

  int maxTries = 5;
  if(espy.find("OK")) {
    while(!connected && maxTries > 0) {
      Serial.println("Attempting to connect. Try " + String(maxTries));
      connected = connectWiFi();
      maxTries--;
    }
    if(connected) {
      espy.println("AT+CWMODE=1");
      delay(1000);
      espy.println("AT+CIPMUX=1");
      delay(1000);
      espy.println("AT+CIPSERVER=1");
      delay(1000);
      Serial.println("Server started");
    } else {
      Serial.println("Unable to connect");
    }
  } else {
    Serial.println("ESP not ready");
  }
  Serial.println("Getting IP");
  espy.println("AT+CIFSR");
  delay(2000);
  Serial.println(espy.readString());
}

void loop() {
  if (connected) {
    digitalWrite(indicatorPin, HIGH);

    if (espy.find("led-on")) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }
  }
  delay(50);
}

boolean connectWiFi(){
  Serial.println("Connecting to access point");
  espy.println("AT+CWMODE=1");
  delay(2000);
  String cmd="AT+CWJAP=\"";
  cmd+=SSID;
  cmd+="\",\"";
  cmd+=PASS;
  cmd+="\"";
  espy.println(cmd);
  Serial.println("Waiting for connection");
  delay(5000);
  if(espy.find("OK")){
    Serial.println("Connected!");
    return true;
  }else{
    Serial.println("Unable to connect");
    espy.println("AT+RST");
    delay(1000);
    return false;
  }
}

/* void sendCommand(String command){ */
/*   Serial.println("Sending command: " + command); */
/*   String cmd = "AT+CIPSTART=\"TCP\",\""; */
/*   cmd += IP; */
/*   cmd += "\",3000"; */
/*   espy.println(cmd); */
/*   Serial.println("Waiting for command connection to server"); */
/*   delay(2000); */
/*   if(espy.find("Error")){ */
/*     return; */
/*   } */
/*   cmd = command; */
/*   cmd += "\r\n"; */
/*   espy.print("AT+CIPSEND="); */
/*   espy.println(cmd.length()); */
/*   if(espy.find(">")){ */
/*     espy.print(cmd); */
/*     Serial.println("Command sent"); */
/*   }else{ */
/*     Serial.println("Command error; closing connection"); */
/*     espy.println("AT+CIPCLOSE"); */
/*   } */
/* } */
