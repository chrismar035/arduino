int data = 2;
int clock = 3;
int latch = 4;

int ledState = 0;
const int ON = HIGH;
const int OFF = LOW;

int delayTime = 200;

void setup() {
  pinMode(data, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(latch, OUTPUT);
}

void loop() {
  allOff();

  oneAfterAnotherLoop();
  oneAfterAnotherLoop();

  oneOnAtATime();
  oneOnAtATime();

  inAndOut();
  inAndOut();

  redsAndGreensAlt();
  redsAndGreensAlt();
  redsAndGreensAlt();
}

void allOff() {
  for(int i = 0; i < 8; i++) {
    changeLED(i, OFF);
  }
}

void oneAfterAnotherLoop() {
  for(int i = 0; i < 8; i++) {
    changeLED(i, ON);
    delay(delayTime);
  }
  for(int i = 7; i > -1; i--) {
    changeLED(i, OFF);
    delay(delayTime);
  }
}

void oneOnAtATime() {
  for(int i = 0; i < 8; i++) {
    int offLed = (i - 1 + 8) % 8;
    changeLED(i, ON);
    changeLED(offLed, OFF);
    delay(delayTime);
  }
  changeLED(7, OFF);
}

void inAndOut() {
  for(int i = 0; i < 4; i++) {
    changeLED(i, ON);
    changeLED(7 - i, ON);
    delay(delayTime);
  }
  delay(delayTime);
  for(int i = 3; i >= 0; i--) {
    changeLED(i, OFF);
    changeLED(7 - i, OFF);
    delay(delayTime);
  }
  delay(delayTime);
}

void redsAndGreensAlt() {
  greens(ON);
  reds(OFF);
  delay(delayTime);
  greens(OFF);
  reds(ON);
  delay(delayTime);
}

void greens(int state) {
  for(int i = 0; i < 4; i ++) {
    changeLED(i, state);
  }
}

void reds(int state) {
  for(int i = 4; i < 8; i ++) {
    changeLED(i, state);
  }
}

void updateLEDs(int value) {
  digitalWrite(latch, LOW);
  shiftOut(data, clock, MSBFIRST, value);
  digitalWrite(latch, HIGH);
}

int bits[] = {B00000001, B00000010, B00000100, B00001000,
              B00010000, B00100000, B01000000, B10000000};
int masks[] = {B11111110, B11111101, B11111011, B11110111,
               B11101111, B11011111, B10111111, B01111111};

void changeLED(int led, int state) {
  ledState = ledState & masks[led];
  if(state == ON) { ledState = ledState | bits[led]; }
  updateLEDs(ledState);
}
