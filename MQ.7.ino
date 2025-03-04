// Define the analog input pin for the MQ-5 sensor
const int mq5Pin = A0;  // ESP8266 has only one ADC pin, which is A0

void setup() {
  // Start the serial communication
  Serial.begin(115200);  // Set the baud rate to 115200 for serial communication

  // Give the sensor time to warm up
 delay(2000);  // Wait for 2 seconds before starting measurements
}

void loop() {
  // Read the analog value from the MQ-5 sensor
  int sensorValue = analogRead(mq5Pin);  // Read the voltage level from A0 pin

  // Print the sensor value to the Serial Monitor
  Serial.print("MQ-5 Sensor Value: ");
  Serial.println(sensorValue);  // Print the value (0 to 1023) that corresponds to gas concentration

  // Wait for 2 seconds before taking another reading
  delay(2000);
}
