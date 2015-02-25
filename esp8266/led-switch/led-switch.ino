#include<stdlib.h>
#include <SoftwareSerial.h>

#define SSID ""
#define PASS ""
#define IP "192.168.1.75"
SoftwareSerial monitor(10, 11); // RX, TX

String GET = "GET /test";


int redPin = 13;
int greenPin = 12;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  // put your setup code here, to run once:
  monitor.begin(115200);
  monitor.println("AT");
  delay(1000);
  if(monitor.find("OK")){
    digitalWrite(greenPin, HIGH);
    connectWiFi();
  } else {
    digitalWrite(redPin, HIGH);
  }

}

void loop() {
  sendTest();
  startBlink();
  delay(3000);
  // put your main code here, to run repeatedly:
  /* digitalWrite(redPin, LOW); */
  /* digitalWrite(greenPin, HIGH); */
  /* delay(50); */
  /* digitalWrite(redPin, HIGH); */
  /* digitalWrite(greenPin, LOW); */
  /* delay(50); */
  /* digitalWrite(redPin, LOW); */
  /* delay(100); */
}

void sendTest(){
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += IP;
  cmd += "\",3000";
  monitor.println(cmd);
  delay(2000);
  if(monitor.find("Error")){
    blinkRed();
    return;
  }
  cmd = GET;
  cmd += "\r\n";
  monitor.print("AT+CIPSEND=");
  monitor.println(cmd.length());
  if(monitor.find(">")){
    digitalWrite(greenPin, HIGH);
    monitor.print(cmd);
  }else{
    digitalWrite(redPin, HIGH);
    monitor.println("AT+CIPCLOSE");
  }
}

boolean connectWiFi(){
  startBlink();
  monitor.println("AT+CWMODE=1");
  delay(2000);
  String cmd="AT+CWJAP=\"";
  cmd+=SSID;
  cmd+="\",\"";
  cmd+=PASS;
  cmd+="\"";
  monitor.println(cmd);
  startBlink();
  delay(5000);
  if(monitor.find("OK")){
    digitalWrite(greenPin, HIGH);
    return true;
  }else{
    digitalWrite(redPin, HIGH);
    return false;
  }
}

void startBlink() {
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, HIGH);
  delay(50);
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, LOW);
  delay(50);
  digitalWrite(redPin, LOW);
}

void blinkRed() {
  digitalWrite(greenPin, LOW);
  digitalWrite(redPin, HIGH);
  delay(50);
  digitalWrite(redPin, LOW);
  delay(50);
  digitalWrite(redPin, HIGH);
  delay(50);
  digitalWrite(redPin, LOW);
  delay(50);
  digitalWrite(redPin, HIGH);
  delay(50);
  digitalWrite(redPin, LOW);
}
