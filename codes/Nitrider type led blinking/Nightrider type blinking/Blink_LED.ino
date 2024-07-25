// Define the number of LEDs
const int numLEDs = 8;

// Define the pins for the LEDs
int ledPins[numLEDs] = {3, 5, 6, 7, 9, 10, 12};

void setup() {
  // Set all LED pins as outputs
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Loop to light up LEDs from left to right
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], HIGH); // Turn on the LED
    delay(1000);                     // Wait for 100 milliseconds
    digitalWrite(ledPins[i], LOW);  // Turn off the LED
  }
  
  // Loop to light up LEDs from right to left
  for (int i = numLEDs - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH); // Turn on the LED
    delay(100);                     // Wait for 100 milliseconds
    digitalWrite(ledPins[i], LOW);  // Turn off the LED
  }
}