#include <QTRSensors.h>

#define Kp 0.4 // find the best value speed controll
#define Ki 0.01
#define Kd 0.1  // experiment to determine this, slowly increase the speeds and adjust this value. ( Note: Kp < Kd) 

int MaxSpeed = 255;// max speed of the robot
int BaseSpeed = 180; // this is the speed at which the motors should spin when the robot is perfectly on the line
int lastError = 0;

//define motor pin

#define rightMotor1 14
#define rightMotor2 12
#define rightMotorPWM 13


#define leftMotor1 26
#define leftMotor2 27
#define leftMotorPWM 25

// setting PWM properties
const int freq = 5000;
const int ledChannel = 1;
const int resolution = 8;

QTRSensors qtr;
const uint8_t SensorCount = 10;
uint16_t sensorValues[SensorCount];



