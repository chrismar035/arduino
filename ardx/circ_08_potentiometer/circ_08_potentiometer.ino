#include <Servo.h>

int sensorPin = 0;
int servoPin = 9;
int val;

Servo servo;


void setup() {
  servo.attach(servoPin);
}

void loop() {
  val = analogRead(sensorPin);
  val = map(val, 0, 1023, 0, 179);
  servo.write(val);
  delay(10);
}
