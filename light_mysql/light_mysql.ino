#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Redmi";
const char* password = "12345678";
int a = 26;
int b = 13;
void setup() {
  Serial.begin(115200);
pinMode(a,OUTPUT);
pinMode(b,OUTPUT);
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

  // Replace "your_php_script_url" with the actual URL of your PHP script
  String url = "http://192.168.43.235/dht11_project/getState.php";
  http.begin(url);

  int httpCode = http.GET();
  if (httpCode > 0) {
    if (httpCode == HTTP_CODE_OK) {
      String payload = http.getString();

      // Extract values from JSON manually
      String lightNo = getValueByKey(payload, "lightNo");
      String state = getValueByKey(payload, "state");
      if(lightNo == "1" && state == "ON"){
        digitalWrite(a,LOW);
      }
      if(lightNo == "1" && state == "OFF"){
        digitalWrite(a,HIGH);
      }
      if(lightNo == "2" && state == "ON"){
        digitalWrite(b,LOW);
      }
      if(lightNo == "2" && state == "OFF"){
        digitalWrite(b,HIGH);
      }

      // Process the values as needed
      Serial.println("Light Number: " + lightNo);
      Serial.println("State: " + state);
    } else {
      Serial.println("HTTP request failed with error code: " + String(httpCode));
    }
  } else {
    Serial.println("HTTP request failed");
  }

  http.end();

  // Delay before making the next request
  delay(10);
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
