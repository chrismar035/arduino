int lightPin = 0;
int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightLevel = analogRead(lightPin);

  lightLevel = map(lightLevel, 0, 900, 0, 255);
  lightLevel = constrain(lightLevel, 0, 255);

  Serial.println(255 - lightLevel);
  analogWrite(ledPin, 255 - lightLevel);
}
