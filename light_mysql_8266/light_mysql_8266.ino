#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

const char* ssid = "Redmi";
const char* password = "12345678";
int a = 25;
int b = 13; // Change this to a GPIO pin available on your ESP8266

void setup() {
  Serial.begin(115200);
  pinMode(b, OUTPUT);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  // Make an HTTP GET request
  HTTPClient http;
  WiFiClient client;

  // Replace "your_php_script_url" with the actual URL of your PHP script
  String url = "http://192.168.43.235/dht11_project/getState.php";
  http.begin(client, url);

  int httpCode = http.GET();
  if (httpCode > 0) {
    if (httpCode == HTTP_CODE_OK) {
      String payload = http.getString();

      // Extract values from JSON manually
      String lightNo = getValueByKey(payload, "lightNo");
      String state = getValueByKey(payload, "state");
      String room = getValueByKey(payload, "room");
      
      // Process the values as needed
      Serial.println("Light Number: " + lightNo);
      Serial.println("State: " + state);

      // Control GPIO pins based on received values
      if (lightNo == "1" && state == "ON") {
        digitalWrite(b, HIGH);
      } else if (lightNo == "1" && state == "OFF") {
        digitalWrite(b, LOW);
      }
    } else {
      Serial.println("HTTP request failed with error code: " + String(httpCode));
    }
  } else {
    Serial.println("HTTP request failed");
  }

  http.end();

  // Delay before making the next request
  delay(1000);
}

String getValueByKey(String jsonString, String key) {
  int keyIndex = jsonString.indexOf("\"" + key + "\":");
  if (keyIndex != -1) {
    int startIndex = jsonString.indexOf("\"", keyIndex + key.length() + 3) + 1;
    int endIndex = jsonString.indexOf("\"", startIndex);
    return jsonString.substring(startIndex, endIndex);
  }
  return "";
}
