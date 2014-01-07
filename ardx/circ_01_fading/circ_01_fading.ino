int ledPin = 9;
int fadeDelay = 3;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  fadeIn(ledPin);
  sleep(1);
  fadeOut(ledPin);
  sleep(1);
}

void sleep(int seconds) {
  delay(seconds * 1000);
}

void fadeIn(int ledPin) {
  for(int i = 0; i < 256; i++) {
    analogWrite(ledPin, i);
    delay(fadeDelay);
  }
}

void fadeOut(int ledPin) {
  for(int i = 255; i > 0; i--) {
    analogWrite(ledPin, i);
    delay(fadeDelay);
  }
}


