#include <QTRSensors.h>
#define kp 0.0067  // find the best value speed controll
#define ki 0
#define kd 0.009

int in1 = 30, in2 = 28, in3 = 26, in4 = 24, pwm1 = 46, pwm2 = 44;
int leftMotorH =36;  //pin2
int leftMotorL =38;  //pin1 
int enable1Pin =44;  
int rightMotorH =42; //pin3
int rightMotorL = 40; // pin4
int enable2Pin = 46;
float thres=500;

String path;
int threshold_value[12];
int min_value[12];
int max_value[12];

int arr[] = {A0,A2,A4,A6,A8,A10,A12,A14,32,34};

QTRSensors qtr;

const uint8_t SensorCount = 10;
uint16_t sensorValues[SensorCount];

void setup()
{
  Serial.begin(9600);
  for(int i=0;i<10;i++){
    pinMode(arr[i],OUTPUT);
  }
  Calibration();
  motor_setup();
  
  
}
int i=0; //char s[100];
String s ;
void loop()
{qtr.readCalibrated(sensorValues);

//Run(1,70,1);
  //Run(2,70,1);
  Read_Values();
  if(sensorValues[9] > threshold_value[9] && sensorValues[7] > threshold_value[7] && sensorValues[5] > threshold_value[5]){
    wait();
    right_90();
  }/*
  if(s[0] == '1' && s[2] == '1' &&s[4]== '1'){
    wait();
    left_90();
  }
  else*/
  pid();
}

void wait(){
  Run(1,50,1);
  Run(2,50,1);delay(200);
  Run(1,50,0);
  Run(2,50,0);delay(100);
  Run(1,0,0);
  Run(2,0,0);delay(1500);
}




void motor_setup(){
  pinMode(leftMotorH, OUTPUT);
  pinMode(leftMotorL, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  pinMode(rightMotorH, OUTPUT);
  pinMode(rightMotorL, OUTPUT);
  pinMode(enable2Pin, OUTPUT);
 
}
