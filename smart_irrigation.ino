// Pin configuration
const int soilMoisturePin = A0;   // Soil moisture sensor connected to A0
const int airTempSensorPin = A1;  // Air temperature sensor connected to A1
const int pHSensorPin = A2;       // pH sensor (potentiometer) connected to A2
const int tdsSensorPin = A3;      // TDS sensor (potentiometer) connected to A3
const int waterTempSensorPin = A4; // Water temperature sensor connected to A4
const int ledPin = 2;             // LED connected to digital pin 2 (moisture indicator)
const int moistureBuzzerPin = 4;  // Buzzer for soil moisture connected to digital pin 4
const int tempBuzzerPin = 7;      // Buzzer for temperature warning connected to digital pin 7
const int motorPin = 13;          // Motor connected to digital pin 13

// Define thresholds
const int moistureThreshold = 400;        // Moisture threshold
const float airTemperatureThreshold = 30.0;  // Air temperature threshold in Celsius
const float waterTemperatureThreshold = 30.0; // Water temperature threshold in Celsius
const float pHMin = 5.5;                  // Minimum pH threshold
const float pHMax = 7.5;                  // Maximum pH threshold
const float tdsMin = 0.0;                 // Minimum TDS value
const float tdsMax = 1000.0;              // Maximum TDS value

void setup() {
  pinMode(ledPin, OUTPUT);           // Set LED pin as OUTPUT
  pinMode(motorPin, OUTPUT);         // Set motor pin as OUTPUT
  pinMode(moistureBuzzerPin, OUTPUT); // Set moisture buzzer pin as OUTPUT
  pinMode(tempBuzzerPin, OUTPUT);    // Set temperature buzzer pin as OUTPUT
  Serial.begin(9600);                // Initialize serial communication for monitoring
}

void loop() {
  // **Soil Moisture Sensor**
  int moistureValue = analogRead(soilMoisturePin);  // Read soil moisture value
  Serial.print("Soil Moisture Level: ");
  Serial.println(moistureValue);

  // Check if moisture is below the threshold
  if (moistureValue < moistureThreshold) {
    // Turn on motor, LED, and buzzer for moisture
    digitalWrite(motorPin, HIGH);
    digitalWrite(ledPin, HIGH);
    tone(moistureBuzzerPin, 1000); // Buzzer at 1000 Hz for soil moisture
    Serial.println("Moisture level low, motor ON, moisture buzzer ON.");
  } else {
    // Turn off motor, LED, and buzzer for moisture
    digitalWrite(motorPin, LOW);
    digitalWrite(ledPin, LOW);
    noTone(moistureBuzzerPin);
    Serial.println("Moisture level sufficient, motor OFF, moisture buzzer OFF.");
  }

  // **Air Temperature Sensor**
  int airTempValue = analogRead(airTempSensorPin);
  float airVoltage = airTempValue * (5.0 / 1023.0);  // Convert analog value to voltage
  float airTemperature = (airVoltage - 0.5) * 100.0; // Convert voltage to Celsius
  
  // Print the air temperature for monitoring
  Serial.print("Air Temperature: ");
  Serial.print(airTemperature);
  Serial.println(" °C");

  // Check if air temperature is above the threshold
  if (airTemperature > airTemperatureThreshold) {
    // Turn on buzzer for temperature warning
    tone(tempBuzzerPin, 2000);  // Buzzer at 2000 Hz for temperature warning
    Serial.println("Air temperature is high. Temperature buzzer ON.");
  } else {
    // Turn off buzzer for temperature warning
    noTone(tempBuzzerPin);
    Serial.println("Air temperature is normal. Temperature buzzer OFF.");
  }

  // **Water Temperature Sensor**
  int waterTempValue = analogRead(waterTempSensorPin);
  float waterVoltage = waterTempValue * (5.0 / 1023.0);  // Convert analog value to voltage
  float waterTemperature = (waterVoltage - 0.5) * 100.0; // Convert voltage to Celsius
  
  // Print the water temperature for monitoring
  Serial.print("Water Temperature: ");
  Serial.print(waterTemperature);
  Serial.println(" °C");

  // Check if water temperature is above the threshold
  if (waterTemperature > waterTemperatureThreshold) {
    Serial.println("Water temperature is high.");
  } else {
    Serial.println("Water temperature is normal.");
  }

  // **pH Sensor (using potentiometer)**
  int pHValue = analogRead(pHSensorPin);  // Read pH sensor (potentiometer)
  float pH = pHValue * (14.0 / 1023.0);  // Map the pH value to a 0-14 range
  Serial.print("pH Level: ");
  Serial.println(pH, 2);  // Print pH value with 2 decimal places

  // Check if pH is out of range
  if (pH < pHMin || pH > pHMax) {
    Serial.println("pH is out of range!");
  } else {
    Serial.println("pH is within the acceptable range.");
  }

  // **TDS Sensor (using potentiometer)**
  int tdsValue = analogRead(tdsSensorPin);  // Read TDS sensor (potentiometer)
  float tds = tdsValue * (tdsMax / 1023.0); // Map the TDS value to 0-1000 range
  Serial.print("TDS Level: ");
  Serial.print(tds);
  Serial.println(" ppm");

  // Small delay to prevent flooding the serial monitor
  delay(1000);  // 1-second delay before next reading
}
