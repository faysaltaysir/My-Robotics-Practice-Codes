#include <QTRSensors.h>

#define Kp 0.004  // find the best value speed controll
#define Ki 0.01
#define Kd 0.001  // experiment to determine this, slowly increase the speeds and adjust this value. ( Note: Kp < Kd)
#define thres 800

int MaxSpeed = 150;  // max speed of the robot
int BaseSpeed = 75;  // this is the speed at which the motors should spin when the robot is perfectly on the line
int lastError = 0;
char a[11];
//define motor pin

#define rightMotor1 A1
#define rightMotor2 A0
#define rightMotorPWM 6

#define leftMotor1 A3
#define leftMotor2 A2
#define leftMotorPWM 5

// setting PWM properties
//const int freq = 5000;
//const int ledChannel = 1;
//const int resolution = 8;

QTRSensors qtr;
const uint8_t SensorCount = 10;
uint16_t sensorValues[SensorCount];
void setup() {
  Serial.begin(115200);

  qtr.setTypeRC();
  qtr.setSensorPins((const uint8_t[]){ 13, 11, 10, 9, 8, 7, 4, 3, A4, A5 }, SensorCount);  //Declare the sensor pin with arduino
  qtr.setEmitterPin(2);                                                                    //LEDON PIN

  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(rightMotorPWM, OUTPUT);
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(leftMotorPWM, OUTPUT);

  // configure LED PWM functionalitites

  //ledcSetup(ledChannel, freq, resolution);

  // attach the channel to the GPIO to be controlled
  //ledcAttachPin(rightMotorPWM, ledChannel);
  //ledcAttachPin(leftMotorPWM, ledChannel);

  int i = 0;
  for (int i = 0; i < 100; i++)  // calibrate for sometime by sliding the sensors across the line, or you may use auto-calibration instead
  {
    //comment this part out for automatic calibration
    /* if ( i  < 25 || i >= 75 ) // turn to the left and right to expose the sensors to the brightest and darkest readings that may be encountered
    {
      RUN(1, 170, 1);   // ( left motor , speed , high or low )
      RUN(2, 170, 0);   // ( right motor , speed , high or low )
      Serial.println("BBBBBBBBBB");
    }
    else
    {
      RUN(1, 170, 0);   // ( left motor , speed , high or low )
      RUN(2, 170, 1);   // ( right motor , speed , high or low )
      Serial.println("vVvvvvvv");
    }*/
    qtr.calibrate();
    delay(20);
  }
  wait();
  /* int touch =touchRead(33);
  Serial.println(touch);
  int t = 0;
  while(t==0){
    int touch =touchRead(33);
    if(touch<10)break;
  }
  Serial.println("OKK");
  */
}



void loop() {
  String a="00000000";
  // print the sensor values as numbers from 0 to 2500, where 0 means maximum
  // reflectance and 2500 means minimum reflectance
  qtr.read(sensorValues);
  
  for (uint8_t i = 0; i < SensorCount; i++)
  {
    if(sensorValues[i]>thres)
      a[i]='1';
    else a[i]='0';
     //Serial.print(sensorValues[i]);
   // Serial.print('\t');
  }
  


Serial.println(a);
  uint16_t Position = qtr.readLineBlack(sensorValues);  //read the current position
  

  //left 90 degree turn
  if ((sensorValues[0] > thres && sensorValues[1] > thres && sensorValues[2] > thres && sensorValues[3] > thres)||(sensorValues[0] > thres && sensorValues[1] > thres && sensorValues[2] > thres)  && sensorValues[9] < thres) {
    left_90();
  }
  //right 90 degree turn
  else if (sensorValues[6] > thres && sensorValues[7] > thres && sensorValues[8] > thres && sensorValues[9] > thres && sensorValues[0] < thres) {
    right_90();
  }

  else if ((sensorValues[0] > thres || (sensorValues[0] > thres && sensorValues[1] > thres)) && sensorValues[2] < thres && sensorValues[6] > thres && sensorValues[7] > thres && sensorValues[8] > thres && sensorValues[9] > thres ) {
    for(int i=1;i<=30;i++){
      left_30();
    }
    
  }
  // T
  else if (sensorValues[0] > thres && sensorValues[1] > thres && sensorValues[2] > thres && sensorValues[3] > thres && sensorValues[5] > thres && sensorValues[7] > thres&& sensorValues[8] > thres&& sensorValues[9] > thres) {
    wait();delay(20);
    uint16_t Position = qtr.readLineBlack(sensorValues);
    if (Position > 8000) left_90();
    else pid();

  }
  
  else{
    pid();
  }
  // cross or "T" degree turn
  // if(sensorValues[0]>800 && sensorValues[1]>800&& sensorValues[4]>800&& sensorValues[5]>800&& sensorValues[8]>800&& sensorValues[9]>800){
  //      uint16_t Position = qtr.readLineBlack(sensorValues);
  //    if(Position>8000)
  //    left_90(); // or right 90 degree
  //}







}
void wait() {
  analogWrite(leftMotorPWM, 0);
  analogWrite(rightMotorPWM, 0);
}

void RUN(int motor, int speed, int direction) {

  boolean inPin1 = HIGH;
  boolean inPin2 = LOW;

  if (direction == 1) {
    inPin1 = HIGH;
    inPin2 = LOW;
    //1=FORWARD
  }
  if (direction == 0) {
    inPin1 = LOW;
    inPin2 = HIGH;
    //0=BACKWARD
  }

  if (motor == 1) {
    digitalWrite(leftMotor1, inPin1);
    digitalWrite(leftMotor2, inPin2);
    analogWrite(leftMotorPWM, speed);
    // 1=A
  }
  if (motor == 2) {
    digitalWrite(rightMotor1, inPin1);
    digitalWrite(rightMotor2, inPin2);
    analogWrite(rightMotorPWM, speed - 6);
    // 2=B
  }
}
void left_30() {
  int i;
  for (i = 1; i < 50; i++) {
    RUN(1, 70, 1);
    RUN(2, 70, 0);
    
  }uint16_t Position = qtr.readLineBlack(sensorValues);
    if (Position > 4000 && Position < 5000) pid();
}
void left_90() {
  int i;
  for (i = 1; i < 500; i++) {
    RUN(1, 70, 1);
    RUN(2, 70, 0);
    uint16_t Position = qtr.readLineBlack(sensorValues);
    if (Position > 4000 && Position < 5000) break;
  }
}

void right_90() {
  int i;
  for (i = 1; i < 500; i++) {
    RUN(1, 70, 0);
    RUN(2, 70, 1);
    uint16_t Position = qtr.readLineBlack(sensorValues);
    if (Position > 4000 && Position < 5000)break;
  }
}

void u_turn() {
  int i;
  for (i = 1; i < 60; i++) {
    RUN(1, 70, 0);
    RUN(2, 70, 1);
    delay(20);
  }
}

void pid(){
  uint16_t Position = qtr.readLineBlack(sensorValues);  //read the current position
  
  int error = Position - 4500;

  float P = error;
  float I = I + error;
  float D = error - lastError;
  lastError = error;


  int motorSpeed = Kp * error + Ki * I + Kd * D;


  int rightMotorSpeed = BaseSpeed - motorSpeed;
  int leftMotorSpeed = BaseSpeed + motorSpeed;

  if (rightMotorSpeed > MaxSpeed) rightMotorSpeed = MaxSpeed;  // prevent the motor from going beyond max speed
  if (leftMotorSpeed > MaxSpeed) leftMotorSpeed = MaxSpeed;    // prevent the motor from going beyond max speed
  if (rightMotorSpeed < 0) rightMotorSpeed = 0;
  if (leftMotorSpeed < 0) leftMotorSpeed = 0;
  //Serial.println(leftMotorSpeed);
  //Serial.println(rightMotorSpeed);  //delay(1000);
  RUN(1, rightMotorSpeed, 1);       //forward
  RUN(2, leftMotorSpeed, 1);        //forward
}