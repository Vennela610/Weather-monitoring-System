#include <ESP8266WiFi.h>
#include <DHT.h>

// Define sensor pins
#define MQ5_PIN A0    // MQ-5 sensor connected to A0
#define MQ7_PIN D1    // MQ-7 sensor connected to digital pin D1 (GPIO5)
#define DHT_PIN D2    // DHT11 sensor connected to D2 (GPIO4 on NodeMCU)
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);  // Initialize DHT sensor

// WiFi credentials
const char* ssid = "123456789";      // Replace with your Wi-Fi SSID
const char* password = "123456789";  // Replace with your Wi-Fi password

void setup() {
    Serial.begin(115200);  // Initialize serial communication
    dht.begin();           // Start DHT sensor
    pinMode(MQ7_PIN, INPUT); // Set MQ-7 sensor pin as input
    connectToWiFi();       // Connect to Wi-Fi
}

void loop() {
    // Read MQ-5 sensor value
    int mq5Value = analogRead(MQ5_PIN);
    Serial.print("MQ-5 Sensor Value: ");
    Serial.println(mq5Value);
    delay(2000);

    // Read MQ-7 sensor value from digital pin
    int mq7Value = digitalRead(MQ7_PIN);
    Serial.print("MQ-7 Sensor Value: ");
    Serial.println(mq7Value);
    delay(2000);

    // Read temperature and humidity from DHT11
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    // Check if the readings are valid
    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Failed to read from DHT sensor!");
    } else {
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.print("°C ");
        Serial.print("Humidity: ");
        Serial.print(humidity);
        Serial.println("%");
    }

    delay(2000);  // Delay before next reading
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
