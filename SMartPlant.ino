#include "arduino_secrets.h"
#include "thingProperties.h"
#include <DHT.h>

#define DHTPIN D4       // DHT11 signal pin
#define DHTTYPE DHT11
#define SOIL_PIN A0     // Soil sensor analog pin
#define PIR_PIN D5      // PIR motion sensor pin

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  delay(1500);

  // Initialize sensors
  dht.begin();
  pinMode(PIR_PIN, INPUT);

  // Connect to IoT Cloud
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  Serial.println("Setup complete. Waiting for connection...");
}

void loop() {
  ArduinoCloud.update();

  // -----------------
  // Read PIR sensor
  int pirState = digitalRead(PIR_PIN);
  motionDetected = (pirState == HIGH);

  // -----------------
  // Read DHT11
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Check if read failed
  if (!isnan(h)) {
    humidity = h;   // Update cloud variable
  }
  if (!isnan(t)) {
    temperature = t;  // Update cloud variable
  }

  // -----------------
  // Read soil moisture and map to percentage
  int rawSoil = analogRead(SOIL_PIN);
  soilMoisture = map(rawSoil, 1023, 300, 0, 100);
  soilMoisture = constrain(soilMoisture, 0, 100);

  // -----------------
  // Print to Serial for debugging
  Serial.print("Humidity: "); Serial.print(humidity); Serial.print("% | ");
  Serial.print("Temp: "); Serial.print(temperature); Serial.print("°C | ");
  Serial.print("Soil: "); Serial.print(soilMoisture); Serial.print("% | ");
  Serial.print("Motion: "); Serial.println(motionDetected ? "Detected" : "No");

  delay(3000);  // 3 sec delay between readings
}
