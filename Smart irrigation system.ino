// Define the pin numbers for the moisture sensor, relay, and water pump
int moistureSensorPin = A0;
int relayPin = 2;
int waterPumpPin = 3;

// Define the moisture threshold level
int moistureThreshold = 500;

void setup() {
  // Set the relay and water pump pins as output
  pinMode(relayPin, OUTPUT);
  pinMode(waterPumpPin, OUTPUT);

  // Initialize the serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the moisture level from the sensor
  int moistureLevel = analogRead(moistureSensorPin);

  // Print the moisture level to the serial monitor
  Serial.print("Moisture Level: ");
  Serial.println(moistureLevel);

  // Check if the moisture level is below the threshold
  if (moistureLevel < moistureThreshold) {
    // Turn on the water pump by setting the relay pin high
    digitalWrite(relayPin, HIGH);
    delay(5000); // Wait for 5 seconds to allow the water to flow

    // Turn off the water pump by setting the relay pin low
    digitalWrite(relayPin, LOW);
  }

  // Wait for 1 second before taking another moisture reading
  delay(1000);
}
