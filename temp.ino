#include <ESP8266WiFi.h>
#include <DHT.h>

// Define DHT sensor type and pin
#define DHTPIN D2           // Pin where the DHT11 data line is connected (D2 is GPIO4 on NodeMCU)
#define DHTTYPE DHT11       // DHT 11 sensor

DHT dht(DHTPIN, DHTTYPE);  // Initialize the DHT sensor

// WiFi credentials (Replace with your Wi-Fi network credentials)
const char* ssid = "your-SSID";      // Replace with your Wi-Fi SSID
const char* password = "your-PASSWORD";  // Replace with your Wi-Fi password

void setup() {
  // Start serial communication
  Serial.begin(115200);

  // Initialize the DHT sensor
  dht.begin();

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);

  // Wait for the Wi-Fi connection
  Serial.println("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }

  Serial.println("Connected to Wi-Fi!");
}

void loop() {
  // Wait a few seconds between readings
  delay(2000);  // DHT11 reads temperature and humidity once every 2 seconds

  // Read temperature and humidity from DHT11
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if the readings are valid
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print temperature and humidity to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("°C ");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("%");
}
