int ledPin = 9;

int onPin = 2;
int offPin = 3;
int value = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(onPin, INPUT);
  pinMode(offPin, INPUT);
}

void loop() {
  if (digitalRead(onPin) == LOW) {
    value++;
  }
  else if(digitalRead(offPin) == LOW) {
    value--;
  }
  value = constrain(value, 0, 255);
  analogWrite(ledPin, value);
  delay(10);
}
