#include <WiFi.h>
#include <WiFiUdp.h>
#include <BlynkSimpleEsp32.h>
#include <NTPClient.h>

#define WIFISSID "Redmi"
#define PASSWORD "12345678"
#define BLYNK_AUTH "Your_Blynk_Auth_Token" // Replace with your Blynk authentication token
#define VARIABLE_LABEL "ECG_sensor_data"
#define DEVICE_LABEL "ECG_Monitoring_System"

#define SENSORPIN A0

char payload[10000];
char topic[150];
char str_sensor[10];
char str_millis[20];
double epochseconds = 0;
double epochmilliseconds = 0;
double current_millis = 0;
double current_millis_at_sensordata = 0;
double timestampp = 0;
int j = 0;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

void callback(char* topic, byte* payload, unsigned int length) {
  char p[length + 1];
  memcpy(p, payload, length);
  p[length] = NULL;
  Serial.write(payload, length);
  Serial.println(topic);
}

void reconnect() {
  while (!Blynk.connected()) {
    Serial.println("Attempting Blynk connection...");

    if (Blynk.connect()) {
      Serial.println("Connected to Blynk");
    } else {
      Serial.println("Failed to connect to Blynk, try again in 2 seconds");
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFISSID, PASSWORD);

  Serial.println();
  Serial.print("Waiting for WiFi...");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi Connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Blynk.begin(BLYNK_AUTH);
  timeClient.begin();
  client.setServer(mqttBroker, 1883);
  client.setCallback(callback);
  timeClient.update();
  epochseconds = timeClient.getEpochTime();
  epochmilliseconds = epochseconds * 1000;
  Serial.print("epochmilliseconds=");
  Serial.println(epochmilliseconds);
  current_millis = millis();
  Serial.print("current_millis=");
  Serial.println(current_millis);
}

void loop() {
  Blynk.run();

  if (!client.connected()) {
    reconnect();
    j = 0;
  }

  j = j + 1;
  Serial.print("j=");
  Serial.println(j);
  sprintf(topic, "%s%s", "/v1.6/devices/", DEVICE_LABEL);
  sprintf(payload, "%s", "");
  sprintf(payload, "{\"%s\": [", VARIABLE_LABEL);

  for (int i = 1; i <= 3; i++) {
    float sensor = 50;
    sensor++;
    dtostrf(sensor, 4, 2, str_sensor);
    sprintf(payload, "%s{\"value\":", payload);
    sprintf(payload, "%s %s,", payload, str_sensor);
    current_millis_at_sensordata = millis();
    timestampp = epochmilliseconds + (current_millis_at_sensordata - current_millis);
    dtostrf(timestampp, 10, 0, str_millis);
    sprintf(payload, "%s \"timestamp\": %s},", payload, str_millis);
    delay(150);
  }

  float sensor = 52;
  sensor++;
  dtostrf(sensor, 4, 2, str_sensor);
  current_millis_at_sensordata = millis();
  timestampp = epochmilliseconds + (current_millis_at_sensordata - current_millis);
  dtostrf(timestampp, 10, 0, str_millis);
  sprintf(payload, "%s{\"value\":%s, \"timestamp\": %s}]}", payload, str_sensor, str_millis);

  Serial.println("Publishing data to Blynk Cloud");
  Blynk.virtualWrite(V1, sensor); // Update with your Blynk virtual pin

  delay(1000); // Adjust delay as needed
}
