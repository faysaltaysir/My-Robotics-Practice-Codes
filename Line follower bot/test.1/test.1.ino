#include <QTRSensors.h>
#include <SoftwareSerial.h>

SoftwareSerial BTserial(15, 14); // RX | TX
#define Kp 0.0099//  .00594 // find the best value speed controll
#define Ki 0
#define Kd 0  // experiment to determine this, slowly increase the speeds and adjust this value. ( Note: Kp < Kd)
#define thres 500
int x=60;//turn
int MaxSpeed = 100;  // max speed of the robot
int BaseSpeed = 50;  // this is the speed at which the motors should spin when the robot is perfectly on the line
int lastError = 0;
char a[11];
//define motor pin
int Ls;
int Rs;
#define rightMotor1 25
#define rightMotor2 24
#define rightMotorPWM 8

#define leftMotor1 23
#define leftMotor2 22
#define leftMotorPWM 9



QTRSensors qtr;
const uint8_t SensorCount = 10;
uint16_t sensorValues[SensorCount];
void setup() {
  Serial.begin(9600);
BTserial.begin(9600);
  qtr.setTypeRC();
  qtr.setSensorPins((const uint8_t[]){ 7,6,5,4,3,2,A0,A1,A2,A3,A4}, SensorCount);  //Declare the sensor pin with arduino
  qtr.setEmitterPin(10);                                                                    //LEDON PIN

  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(rightMotorPWM, OUTPUT);
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(leftMotorPWM, OUTPUT);

  // configure LED PWM functionalitites

 
  int i = 0;digitalWrite(13,HIGH);
  for (int i = 0; i < 100; i++)  // calibrate for sometime by sliding the sensors across the line, or you may use auto-calibration instead
  {
    //comment this part out for automatic calibration
   
    qtr.calibrate();
    delay(20);
  }digitalWrite(13,LOW);
  wait();
 
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
    analogWrite(leftMotorPWM, speed);Serial.print(speed);Serial.print(" ");
    // 1=A
  }
  if (motor == 2) {
    digitalWrite(rightMotor1, inPin1);
    digitalWrite(rightMotor2, inPin2);
    analogWrite(rightMotorPWM, speed);Serial.print(speed);
    // 2=B
  }
}













void wait() {
  analogWrite(leftMotorPWM, 0);
  analogWrite(rightMotorPWM, 0);
}


void loop() {
  String a = "0000000000";
  // print the sensor values as numbers from 0 to 2500, where 0 means maximum
  // reflectance and 2500 means minimum reflectance
  qtr.read(sensorValues);

  for (uint8_t i = 0; i < SensorCount; i++) {
    if (sensorValues[i] > thres)
      a[i] = '1';
    else a[i] = '0';
   // Serial.print(sensorValues[i]);
    //Serial.print('\t');
    
  }



 // Serial.print(a);Serial.print("   ");
  uint16_t Position = qtr.readLineBlack(sensorValues);  //read the current position
                                                      // Serial.println(Position);//delay(1000);
if(Position<50 or Position>8950){
  wait();
}
if(Position>6000){
RUN(1,70,1);
RUN(2,30,1);}
if(Position<3000){
  RUN(1,30,1);
  RUN(2,70,1);
}
else {
RUN(1,50,1);
RUN(2,50,1);
    
  }
}
