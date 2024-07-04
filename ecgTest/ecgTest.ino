#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Redmi";
char pass[] = "12345678";

#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPLuFaui7-F"
#define BLYNK_TEMPLATE_NAME "Heart Monitoring"
#define BLYNK_AUTH_TOKEN "qRktuDVZK0Ugw2mfTuPWsARuAZRC0bWg"

BlynkTimer timer;
int val = 0;

int input() {
  if (digitalRead(10) == HIGH) {  // Assuming pin 10 is the button
    Serial.println('!');
  } else {
    val = analogRead(12);  // Assuming analog sensor is connected to pin 12
    Serial.println(val);
  }
  return val;
}

void myTimerEvent() {
  int sensorValue = 0;
  Blynk.virtualWrite(V1, sensorValue);
}

void setup() {
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, myTimerEvent);
}

void loop() {
  Blynk.run();
  timer.run();
}
