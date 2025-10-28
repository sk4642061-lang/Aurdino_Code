int led1 = 8;
int led2 = 10;
int sw1 = 2;

int ledState = LOW;            // 0 = OFF, 1 = ON
int lastReading = HIGH;        // last raw reading from the pin
int stableState = HIGH;        // debounced button state
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50; // ms

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  digitalWrite(led1, LOW);     // ensure LEDs start OFF
  digitalWrite(led2, LOW);

  pinMode(sw1, INPUT_PULLUP);  // button to GND when pressed

  Serial.begin(300);          // debug output
  Serial.println("Starting toggle button test");
}

void loop() {
  int reading = digitalRead(sw1);   // HIGH when not pressed (pull-up), LOW when pressed

  // If the input changed, reset the debounce timer
  if (reading != lastReading) {
    lastDebounceTime = millis();
  }

  // If the input has been stable longer than debounceDelay, take it as the actual state
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != stableState) {
      stableState = reading;
      Serial.println("inside if");
      // We only toggle on the falling edge (HIGH -> LOW) which is a press with INPUT_PULLUP wiring
      if (stableState == LOW) {       // button pressed
        ledState = (ledState == LOW) ? HIGH : LOW; // toggle
        digitalWrite(led1, ledState);
        digitalWrite(led2, ledState);
        Serial.println("led state");

        Serial.print("Button pressed — LEDs now: ");
        Serial.println(ledState == HIGH ? "ON" : "OFF");
      }
    }
  }

  lastReading = reading;
}
