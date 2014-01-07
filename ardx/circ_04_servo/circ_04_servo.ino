#include <Servo.h>

Servo myservo;

int pos = 0;
int servoPin = 9;

void setup() {
  /* myservo.attach(9); */
  pinMode(servoPin, OUTPUT);
}

void loop() {
  for(pos = 0; pos < 180; pos++) {
    moveServo(servoPin, pos);
    delay(15);
  }

  for(pos = 180; pos > -1; pos--) {
    moveServo(servoPin, pos);
    delay(15);
  }
}

void moveServo(int pin, int angle) {
  if(angle > 180 || angle < 0) return;
  int pulseTime = angle * (20/3.0) + 900;

  digitalWrite(pin, HIGH);
  delayMicroseconds(pulseTime);
  digitalWrite(pin, LOW);
}
