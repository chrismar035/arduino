int motorPin = 9;

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  //motorOnThenOff();
  //motorOnThenOffWithSpeed();
  motorOnnThenOffWithAccelleration();
}

void motorOnThenOff() {
  int onTime = 2500;
  int offTime = 1500;

  digitalWrite(motorPin, HIGH);
  delay(onTime);
  digitalWrite(motorPin, LOW);
  delay(offTime);
}

void motorOnThenOffWithSpeed() {
  int onTime = 2500;
  int offTime = 1500;

  int onSpeed = 200;
  int offSpeed = 50;

  analogWrite(motorPin, onSpeed);
  delay(onTime);
  analogWrite(motorPin, offSpeed);
  delay(offTime);
}

void motorOnnThenOffWithAccelleration() {
  int onTime = 2500;
  int offTime = 1500;

  int stepTimeUp = 50;
  int stepTimeDown = 20;

  for (int i = 0; i < 256; i++) {
    analogWrite(motorPin, i);
    delay(stepTimeUp);
  }

  for (int i = 255; i >= 0; i--) {
    analogWrite(motorPin, i);
    delay(stepTimeDown);
  }
}
