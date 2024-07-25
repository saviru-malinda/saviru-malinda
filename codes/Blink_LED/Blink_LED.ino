// Pin definitions
const int conductivitySensorPin = A0;  // Analog pin for conductivity sensor
const int relayPin1 = 2;               // Digital pin for Relay 1 (Motor 1)
const int relayPin2 = 3;               // Digital pin for Relay 2 (Motor 2)
const int pwmPin = 5;                  // PWM pin for controlling Circulation Motor speed

// Threshold for conductivity sensor
const int threshold = 500;

// PWM speed for the circulation motor
int motorSpeed = 128; // Value between 0 (off) and 255 (full speed)

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize pin modes
  pinMode(conductivitySensorPin, INPUT);
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  pinMode(pwmPin, OUTPUT);

  // Initially turn off all relays
  digitalWrite(relayPin1, LOW);
  digitalWrite(relayPin2, LOW);
  analogWrite(pwmPin, 0); // Turn off Circulation Motor
}

void loop() {
  // Read conductivity sensor value
  int sensorValue = analogRead(conductivitySensorPin);
  Serial.print("Conductivity Sensor Value: ");
  Serial.println(sensorValue);

  // Control relays and PWM based on sensor value
  if (sensorValue > threshold) {
    digitalWrite(relayPin1, HIGH); // Turn on Motor 1
    digitalWrite(relayPin2, HIGH); // Turn on Motor 2
    analogWrite(pwmPin, motorSpeed); // Set speed of Circulation Motor
  } else {
    digitalWrite(relayPin1, LOW);  // Turn off Motor 1
    digitalWrite(relayPin2, LOW);  // Turn off Motor 2
    analogWrite(pwmPin, 0); // Turn off Circulation Motor
  }

  // Add a delay to avoid rapid switching
  delay(1000);
}
