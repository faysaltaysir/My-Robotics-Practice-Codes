/*********
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*********/

// Import required libraries
#include <SPIFFS.h>

#include <Arduino.h>
#ifdef ESP32
#include <WiFi.h>
#include <AsyncTCP.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#endif
#include <ESPAsyncWebSrv.h>

AsyncWebServer server(80);
#include <Wire.h>
//#include <Adafruit_Sensor.h>
//#include <Adafruit_BME280.h>

/*#include <SPI.h>
#define BME_SCK 18
#define BME_MISO 19
#define BME_MOSI 23
#define BME_CS 5*/

//Adafruit_BME280 bme; // I2C
//Adafruit_BME280 bme(BME_CS); // hardware SPI
//Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK); // software SPI

// Replace with your network credentials
const char* ssid = "Redmi";
const char* password = "12345678";

// Create AsyncWebServer object on port 80
//AsyncWebServer server(80);

String readBME280Temperature() {
  // Read temperature as Celsius (the default)
  float t = 10;
  // Convert temperature to Fahrenheit
  //t = 1.8 * t + 32;
  
    Serial.println(t);
    return String(t);
  
}

String readBME280Humidity() {
  float h = 12;
  
    Serial.println(h);
    return String(h);
  
}

String readBME280Pressure() {
  float p = 16;
 
    Serial.println(p);
    return String(p);
 
}

void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);
  


  // Initialize SPIFFS
if(!SPIFFS.begin()){
  Serial.println("An Error has occurred while mounting SPIFFS");
  Serial.println("Formatting SPIFFS. This may take a while...");
  SPIFFS.format();
  if(!SPIFFS.begin()){
    Serial.println("Failed to format SPIFFS");
    return;
  }
}


  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP32 Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html");
  });
  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readBME280Temperature().c_str());
  });
  server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readBME280Humidity().c_str());
  });
  server.on("/pressure", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readBME280Pressure().c_str());
  });

  // Start server
  server.begin();

}
 
void loop(){
  
}
