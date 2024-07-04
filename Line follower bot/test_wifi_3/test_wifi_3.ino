#include <QTRSensors.h>
double kp,ki,kd;
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPLb6vjujl7"
#define BLYNK_TEMPLATE_NAME "push data in ESP"
#define BLYNK_AUTH_TOKEN "8uTCd_w_SlIBpM4xRADZ4AKy1EaiFS5d"


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "CUET--Students";
char pass[] = "1020304050";


QTRSensors qtr;

const uint8_t SensorCount = 10;
uint16_t sensorValues[SensorCount];
void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  qtr.setTypeRC();
  qtr.setSensorPins((const uint8_t[]){10,11,12,13,14,15,16,17,18,20}, SensorCount);
}

void loop()
{
  Blynk.run();
  Read_Values();
}
void Read_Values(){
  uint16_t position_black = qtr.readLineBlack(sensorValues);
  uint16_t position_white = qtr.readLineWhite(sensorValues);

  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.print(position_black);Serial.print("  ");
  Serial.print(position_white);
 
}


BLYNK_WRITE(V0)
{
  kp = param.asDouble(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  Serial.print("KP Slider value is: ");
  Serial.println(kp,4);
}
BLYNK_WRITE(V1)
{
  ki = param.asDouble(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  ki=ki/100;
  Serial.print("KI Slider value is: ");
  Serial.println(ki,4);
}
BLYNK_WRITE(V2)
{
  kd = param.asDouble(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  Serial.print("KD Slider value is: ");
  Serial.println(kd,4);
}
