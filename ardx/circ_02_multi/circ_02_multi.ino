
int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
int ledCount = 8;
int reds[] = {0, 2, 4, 6};
int redCount = 4;
int greens[] = {1, 3, 5, 7};
int greenCount = 4;
int delayTime = 100;

void setup() {
  for(int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  allOff();

  oneAfterAnotherLoop();

  oneOnAtATime();

  inAndOut();
  inAndOut();
  inAndOut();

  redsAndGreensAlt();
  redsAndGreensAlt();
  redsAndGreensAlt();

  //blink(ledCount - 1, 2);
}

void on(int i) {
  digitalWrite(ledPins[i], HIGH);
}

void off(int i) {
  digitalWrite(ledPins[i], LOW);
}

void multiOn(int leds[], int count) {
  for(int i = 0; i < count; i++) {
    on(leds[i]);
  }
}

void multiOff(int leds[], int count) {
  for(int i = 0; i < count; i++) {
    off(leds[i]);
  }
}

void blink(int index, int times) {
  for(int i = 0; i < times; i++) {
    on(index);
    delay(1000);
    off(index);
    delay(1000);
  }
}

void allOff() {
  multiOff(ledPins, ledCount);
}

void oneAfterAnotherLoop() {
  for(int i = 0; i < ledCount; i++) {
      on(i);
      delay(delayTime);
  }
    for(int i = 0; i < ledCount; i++) {
      off(i);
      delay(delayTime);
  }
}

void oneOnAtATime() {
  for(int i = 0; i < ledCount; i++) {
    int offLed = (i - 1 + ledCount) % ledCount;

    on(i);
    off(offLed);
    delay(delayTime);
  }
}

void inAndOut() {
  for(int i = 0; i <= 3; i++) {
    int offLed = i - 1;
    if(i == 0) { offLed = 3; }

    int onLed1 = 3 - i;
    int onLed2 = 4 + i;

    int offLed1 = 3 - offLed;
    int offLed2 = 4 + offLed;

    on(onLed1);
    on(onLed2);
    off(offLed1);
    off(offLed2);
    delay(delayTime);
  }
}

void redsAndGreensAlt() {
  multiOn(reds, redCount);
  multiOff(greens, greenCount);
  delay(delayTime * 2);
  multiOn(greens, greenCount);
  multiOff(reds, redCount);
  delay(delayTime * 2);
}
