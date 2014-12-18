// This sketch will send out a Nikon D50 trigger signal (probably works with most Nikons)
// See the full tutorial at http://www.ladyada.net/learn/sensors/ir.html
// this code is public domain, please enjoy!

int IRledPin =  13;    // LED connected to digital pin 13

// The setup() method runs once, when the sketch starts

void setup()   {
  // initialize the IR digital pin as an output:
  pinMode(IRledPin, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  Serial.println("Sending IR signal");

  sendCode();

  delay(6*1000);  // wait one minute (60 seconds * 1000 milliseconds)
}

// This procedure sends a 38KHz pulse to the IRledPin
// for a certain # of microseconds. We'll use this whenever we need to send codes
void pulseIR(long microsecs) {
  // we'll count down from the number of microseconds we are told to wait

  cli();  // this turns off any background interrupts

  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
   digitalWrite(IRledPin, HIGH);  // this takes about 3 microseconds to happen
   delayMicroseconds(9);         // hang out for 10 microseconds, you can also change this to 9 if its not working
   digitalWrite(IRledPin, LOW);   // this also takes about 3 microseconds
   delayMicroseconds(9);         // hang out for 10 microseconds, you can also change this to 9 if its not working

   // so 26 microseconds altogether
   microsecs -= 24;
  }

  sei();  // this turns them back on
}

void sendCode(void) {
  pulseIR(2380);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(580);
pulseIR(1160);
delayMicroseconds(600);
pulseIR(580);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(580);
pulseIR(1180);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(580);
pulseIR(600);
delayMicroseconds(580);
pulseIR(1160);
delayMicroseconds(580);
pulseIR(1160);
delayMicroseconds(600);
pulseIR(1160);
delayMicroseconds(600);
pulseIR(1160);
delayMicroseconds(580);
pulseIR(1180);
delayMicroseconds(580);
pulseIR(1160);
delayMicroseconds(600);
pulseIR(1160);
delayMicroseconds(580);
pulseIR(1180);
delayMicroseconds(18160);
pulseIR(2360);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(600);
pulseIR(1160);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(600);
pulseIR(580);
delayMicroseconds(580);
pulseIR(1160);
delayMicroseconds(600);
pulseIR(580);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(580);
pulseIR(1180);
delayMicroseconds(580);
pulseIR(1180);
delayMicroseconds(580);
pulseIR(1180);
delayMicroseconds(560);
pulseIR(1180);
delayMicroseconds(580);
pulseIR(1160);
delayMicroseconds(600);
pulseIR(1160);
delayMicroseconds(580);
pulseIR(1180);
delayMicroseconds(580);
pulseIR(1180);
delayMicroseconds(18160);
pulseIR(2360);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(600);
pulseIR(1160);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(600);
pulseIR(580);
delayMicroseconds(580);
pulseIR(1180);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(580);
pulseIR(1160);
delayMicroseconds(600);
pulseIR(1160);
delayMicroseconds(600);
pulseIR(1160);
delayMicroseconds(580);
pulseIR(1180);
delayMicroseconds(580);
pulseIR(1160);
delayMicroseconds(600);
pulseIR(1160);
delayMicroseconds(580);
pulseIR(1180);
delayMicroseconds(580);
pulseIR(1160);
delayMicroseconds(18160);
pulseIR(2380);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(580);
pulseIR(1180);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(600);
pulseIR(1160);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(600);
pulseIR(580);
delayMicroseconds(580);
pulseIR(1180);
delayMicroseconds(580);
pulseIR(1160);
delayMicroseconds(580);
pulseIR(1180);
delayMicroseconds(580);
pulseIR(1160);
delayMicroseconds(600);
pulseIR(1160);
delayMicroseconds(580);
pulseIR(1180);
delayMicroseconds(580);
pulseIR(1180);
delayMicroseconds(580);
pulseIR(1160);
}