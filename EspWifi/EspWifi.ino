#include <WiFi.h>

const char* ssid = "ESP32-Access-Point";
const char* password = "123456789";

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Set the ESP32 to the Access Point mode
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  Serial.println("Access Point Started");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  // Your code here
}
