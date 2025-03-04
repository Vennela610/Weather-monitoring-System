#include <ESP8266WiFi.h>

const int MQ7Pin = A0;  // Pin where the MQ-7 sensor is connected
int mq7Value = 0;        // Variable to store sensor value

// WiFi credentials
const char* ssid = "123456789";
const char* password = "Vinni@218";

void setup() {
  Serial.begin(115200);      // Initialize serial communication
  pinMode(MQ7Pin, INPUT);    // Set MQ-7 pin as input
  connectToWiFi();           // Connect to Wi-Fi
}

void loop() {
  mq7Value = analogRead(MQ7Pin);  // Read the analog value from MQ-7
  Serial.print("MQ-7 Sensor Value: ");
  Serial.println(mq7Value);       // Output the sensor value to Serial Monitor
  
  delay(2000);  // 2-second delay
}

// Function to connect to WiFi
void connectToWiFi() {
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println();
  Serial.print("Connected to WiFi. IP address: ");
  Serial.println(WiFi.localIP());
}
