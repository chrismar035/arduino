int stereoVolDown[] = {2360, 580, 1180, 580, 1160, 600, 580, 580, 580, 580, 1180, 580, 580, 580, 580, 600, 1160, 580, 1180, 580, 1180, 580, 1160, 600, 1160, 580, 1180, 580, 1160, 580, 1180, 17580, 2360, 580, 1180, 580, 1160, 580, 600, 580, 580, 580, 1180, 580, 580, 580, 580, 600, 1160, 580, 1180, 580, 1160, 600, 1160, 580, 1180, 580, 1160, 580, 1180, 580, 1180, 17560, 2360, 600, 1160, 600, 1160, 580, 580, 600, 580, 580, 1180, 580, 580, 580, 580, 580, 1180, 580, 1160, 600, 1160, 580, 1180, 580, 1180, 580, 1160, 580, 1180, 580, 1160, 17580, 2380, 580, 1160, 580, 1180, 580, 580, 580, 580, 600, 1160, 580, 580, 600, 580, 580, 1160, 600, 1160, 580, 1180, 580, 1180, 580, 1160, 580, 1180, 580, 1180, 580, 1180, 17560, 2360, 580, 1180, 580, 1160, 600, 580, 580, 580, 580, 1180, 580, 580, 580, 600, 580, 1160, 580, 1180, 580, 1180, 580, 1160, 580, 1180, 580, 1160, 600, 1160, 600, 1160, 17560, 2380, 580, 1160, 600, 1160, 600, 580, 580, 580, 580, 1180, 580, 580, 580, 580, 580, 1180, 580, 1180, 580, 1180, 580, 1160, 580, 1180, 580, 1160, 600, 1160, 580, 1180};
int stereoVolDownN = 191;
int stereoVolUp[] = {2380, 580, 580, 580, 1160, 600, 580, 580, 580, 580, 1180, 580, 580, 580, 600, 580, 1160, 580, 1160, 600, 1160, 600, 1160, 580, 1180, 580, 1160, 600, 1160, 580, 1180, 18160, 2360, 580, 580, 600, 1160, 580, 580, 600, 580, 580, 1160, 600, 580, 580, 580, 580, 1180, 580, 1180, 580, 1180, 560, 1180, 580, 1160, 600, 1160, 580, 1180, 580, 1180, 18160, 2360, 580, 580, 600, 1160, 580, 580, 600, 580, 580, 1180, 580, 580, 580, 580, 580, 1160, 600, 1160, 600, 1160, 580, 1180, 580, 1160, 600, 1160, 580, 1180, 580, 1160, 18160, 2380, 580, 580, 580, 1180, 580, 580, 580, 580, 600, 1160, 580, 580, 600, 580, 580, 1180, 580, 1160, 580, 1180, 580, 1160, 600, 1160, 580, 1180, 580, 1180, 580, 1160, 18160};
int stereoVolUpN = 128;

int IRledPin = 13;

void setup()   {
  pinMode(IRledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println("Sending IR signal");

  sendCode(stereoVolDown, stereoVolDownN);
  sendCode(stereoVolUp, stereoVolUpN);
}

// This procedure sends a 38KHz pulse to the IRledPin
// for a certain # of microseconds. We'll use this whenever we need to send codes
void pulseIR(long microsecs) {
  // we'll count down from the number of microseconds we are told to wait

  while (microsecs > 0) {
   // 38 kHz is about 13 microseconds high and 13 microseconds low
   digitalWrite(IRledPin, HIGH);  // this takes about 3 microseconds to happen
   delayMicroseconds(10);         // hang out for 10 microseconds, you can also change this to 9 if its not working
   digitalWrite(IRledPin, LOW);   // this also takes about 3 microseconds
   delayMicroseconds(10);         // hang out for 10 microseconds, you can also change this to 9 if its not working

   // so 26 microseconds altogether
   microsecs -= 26;
  }
}

void sendCode(int codes[], int n) {
  for(int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      pulseIR(codes[i]);
    } else {
      delayMicroseconds(codes[i]);
    }
  }
}


