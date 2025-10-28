int a = 8;
int b = 3;
int c = 2;

unsigned long previousMillis = 0;  // store last time LED state was updated
const unsigned long interval = 1000; // 1 second

int stepIndex = 0;  // to track which LED to toggle

void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  // Check if 1 second has passed
  if (currentMillis - previousMillis >= interval)
   {
    previousMillis = currentMillis;  // reset timer

    // Run LED sequence
    switch (stepIndex) {
      case 0:
        digitalWrite(a, HIGH);
        break;
      case 1:
        digitalWrite(b, HIGH);
        break;
      case 2:
        digitalWrite(c, HIGH);
        break;
      case 3:
        digitalWrite(a, LOW);
        break;
      case 4:
        digitalWrite(b, LOW);
        break;
      case 5:
        digitalWrite(c, LOW);
        break;
    }

    // Go to next step (wrap around to 0 after 6)
    stepIndex++;
    if (stepIndex > 5) {
      stepIndex = 0;
    }
  }
}
