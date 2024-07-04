#include <WiFi.h>
#include <WebServer.h>

const char *ssid = "DREM"; // Enter your WiFi SSID here
const char *password = "44571948"; // Enter your WiFi password here

WebServer server(80);

String inputText = "";

void handleRoot() {
  server.send(200, "text/html", "<form action='/submit' method='post'><input type='text' name='inputText' /><input type='submit' value='Submit' /></form>");
}

void handleSubmit() {
  if (server.hasArg("inputText")) {
    inputText = server.arg("inputText");
    server.send(200, "text/html", "Input received: " + inputText);
  } else {
    server.send(400, "text/plain", "Error: No inputText parameter provided");
  }
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }

  Serial.println("Connected to WiFi");

  server.on("/", handleRoot);
  server.on("/submit", HTTP_POST, handleSubmit);

  server.begin();
  Serial.println("HTTP server started");
  Serial.println(WiFi.localIP());
  
}

void loop() {
  server.handleClient();
}
