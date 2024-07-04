#include <QTRSensors.h>
//#define kp 0.003  // find the best value speed controll
//#define ki 0.01
//#define kd 0.001
double kp,ki,kd; 
int leftMotor1 = 21; 
int leftMotor2 = 19; 
int enable1Pin = 4; 
int rightMotor1 = 18; 
int rightMotor2 = 5; 
int enable2Pin = 16;
// Setting PWM properties
const int freq = 30000;
const int pwmChannel = 0;
const int pwmChannel2 = 1;
const int resolution = 8;
int dutyCycle = 200;

/*************************************************************
  Blynk is a platform with iOS and Android apps to control
  ESP32, Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build mobile and web interfaces for any
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: https://www.blynk.io
    Sketch generator:           https://examples.blynk.cc
    Blynk community:            https://community.blynk.cc
    Follow us:                  https://www.fb.com/blynkapp
                                https://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP32 chip.

  NOTE: This requires ESP32 support package:
    https://github.com/espressif/arduino-esp32

  Please be sure to select the right ESP32 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
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
//Double ki,kp,kd;

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
QTRSensors qtr;

const uint8_t SensorCount = 10;
uint16_t sensorValues[SensorCount];
int LED_BUILTIN=2;
void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Calibration();
  motor_setup();
}

void loop()
{
  Blynk.run();
  //Read_Values();
}
void motor_setup(){
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(enable2Pin, OUTPUT);
  // configure LED PWM functionalitites
  ledcSetup(pwmChannel, freq, resolution);
  ledcSetup(pwmChannel2, freq, resolution);
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(enable1Pin, pwmChannel);
  ledcAttachPin(enable2Pin, pwmChannel2);
}
