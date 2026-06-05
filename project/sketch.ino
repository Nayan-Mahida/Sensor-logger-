#include <Wire.h>

// Simulated DHT22 sensor values (no real sensor needed)
float readTemperature() { return 22.5 + (millis() / 10000.0); }
float readHumidity()    { return 55.0 - (millis() / 20000.0); }

#define TEMP_THRESHOLD 25.0
#define LED_PIN 13

void setup() {
  Serial.begin(9600);         // UART communication
  Wire.begin();               // I2C bus init
  pinMode(LED_PIN, OUTPUT);
  Serial.println("=== Sensor Logger Started ===");
}

void loop() {
  float temp = readTemperature();
  float hum  = readHumidity();

  // Transmit data over UART (Serial)
  Serial.print("[LOG] Temp: ");
  Serial.print(temp);
  Serial.print(" C  |  Humidity: ");
  Serial.print(hum);
  Serial.println(" %");

  // Threshold alert
  if (temp > TEMP_THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("[ALERT] Temperature exceeded threshold!");
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(2000); // Poll every 2 seconds
}