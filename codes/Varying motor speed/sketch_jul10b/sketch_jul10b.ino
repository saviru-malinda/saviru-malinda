const int tdsPin = A0;          // Pin connected to the TDS sensor
const int pumpOutPin = 8;       // Pin connected to the removal pump relay
const int pumpInPin = 9;        // Pin connected to the refill pump relay

const int minTDS = 300;         // Minimum TDS value for the desired range
const int maxTDS = 500;         // Maximum TDS value for the desired range

void setup() {
  pinMode(pumpOutPin, OUTPUT);
  pinMode(pumpInPin, OUTPUT);
  digitalWrite(pumpOutPin, LOW); // Make sure the pumps are off initially
  digitalWrite(pumpInPin, LOW);
  Serial.begin(9600);
}

void loop() {
  int tdsValue = analogRead(tdsPin);  // Read the TDS sensor value

  Serial.print("TDS Value: ");
  Serial.println(tdsValue);

  if (tdsValue > maxTDS) {
    Serial.println("TDS too high! Removing water...");
    digitalWrite(pumpOutPin, HIGH);   // Turn on the removal pump
    delay(5000);                      // Run the pump for 5 seconds (adjust as needed)
    digitalWrite(pumpOutPin, LOW);    // Turn off the removal pump

    Serial.println("Refilling water...");
    digitalWrite(pumpInPin, HIGH);    // Turn on the refill pump
    delay(5000);                      // Run the pump for 5 seconds (adjust as needed)
    digitalWrite(pumpInPin, LOW);     // Turn off the refill pump

    delay(2000);                      // Wait for 2 seconds before rechecking (adjust as needed)
  } else if (tdsValue < minTDS) {
    Serial.println("TDS too low! Refilling water...");
    digitalWrite(pumpInPin, HIGH);    // Turn on the refill pump
    delay(5000);                      // Run the pump for 5 seconds (adjust as needed)
    digitalWrite(pumpInPin, LOW);     // Turn off the refill pump

    delay(2000);                      // Wait for 2 seconds before rechecking (adjust as needed)
  } else {
    Serial.println("TDS within range. No action required.");
  }

  delay(1000);  // Delay between checks (adjust as needed)
}