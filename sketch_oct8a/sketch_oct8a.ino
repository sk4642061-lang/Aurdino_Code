int ledPin = 8;     // LED connected to pin 13
int buttonPin = 10;   // Button connected to pin 2
int buttonState = 0; // Variable to store button state

void setup() {
  pinMode(ledPin, OUTPUT);      // Set LED as output
  pinMode(buttonPin, INPUT);    // Set button as input
}

void loop() {
  buttonState = digitalRead(buttonPin); // Read button

  if (buttonState == HIGH) {   // If button is pressed
    digitalWrite(ledPin, HIGH); // Turn LED ON
  } else {
    digitalWrite(ledPin, LOW);  // Turn LED OFF
  }
}
