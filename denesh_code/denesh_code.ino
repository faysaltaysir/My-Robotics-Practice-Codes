#include <QTRSensors.h>

#define Kp 0.004 // find the best value speed controll
#define Ki 0.01
#define Kd 0.001  // experiment to determine this, slowly increase the speeds and adjust this value. ( Note: Kp < Kd) 

int MaxSpeed = 250;// max speed of the robot
int BaseSpeed = 125; // this is the speed at which the motors should spin when the robot is perfectly on the line
int lastError = 0;

//define motor pin

#define rightMotor1 5
#define rightMotor2 6
#define rightMotorPWM 9


#define leftMotor1 8
#define leftMotor2 7
#define leftMotorPWM 10

// setting PWM properties
//const int freq = 5000;
//const int ledChannel = 1;
//const int resolution = 8;

QTRSensors qtr;
const uint8_t SensorCount = 10;
uint16_t sensorValues[SensorCount];

void setup()
{
  Serial.begin(115200);
  
  qtr.setTypeRC();
  qtr.setSensorPins((const uint8_t[]){3,2,A0,A1,A2,A3,A4,A5,A6,A7}, SensorCount);  //Declare the sensor pin with arduino
  qtr.setEmitterPin(4);//LEDON PIN
  
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
  
  int i =0 ;
  for (int i = 0; i < 100; i++) // calibrate for sometime by sliding the sensors across the line, or you may use auto-calibration instead
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



void loop(){  
  
  uint16_t Position = qtr.readLineBlack(sensorValues); //read the current position  
  Serial.print(Position);Serial.print("\t");//delay(1000);
 /* if(Position>8950){
    
    left_90();  // turn 90 degree
    
  }
  if(Position<50){ 
    
    right_90();  // turn 90 degree
   
  }*/
for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.println();
 /*if(sensorValues[0]>900 && sensorValues[1]>900){
   if(sensorValues[8]<200 && sensorValues[9]<200){
     left_90();
   }
 }*/
/* if(sensorValues[6]+sensorValues[7]+sensorValues[8]+sensorValues[9])>3000){
   if(sensorValues[0]+sensorValues[1]+sensorValues[2]+sensorValues[3])<200){
     right_90();
   }
 }*/
 
 
 
 
 
  int error = Position - 4500;
  
  float P = error;
  float I = I + error;
  float D = error - lastError;
  lastError = error;

  
  int motorSpeed = Kp * error + Ki * I + Kd * D;
  

  int rightMotorSpeed = BaseSpeed - motorSpeed;
  int leftMotorSpeed = BaseSpeed + motorSpeed;
  
  if (rightMotorSpeed > MaxSpeed )  rightMotorSpeed = MaxSpeed; // prevent the motor from going beyond max speed
  if (leftMotorSpeed > MaxSpeed ) leftMotorSpeed = MaxSpeed; // prevent the motor from going beyond max speed
  if (rightMotorSpeed < 0)rightMotorSpeed = 0;    
  if (leftMotorSpeed < 0)leftMotorSpeed = 0;
 //   Serial.println(leftMotorSpeed);
   // Serial.println(rightMotorSpeed);delay(1000);
  RUN(1, rightMotorSpeed, 1);  //forward
  RUN(2, leftMotorSpeed, 1);  //forward
}
void wait(){
  analogWrite(leftMotorPWM, 0);
  analogWrite(rightMotorPWM, 0);
}

void RUN(int motor, int speed, int direction){
  
  boolean inPin1=HIGH;
  boolean inPin2=LOW;
  
  if(direction == 1){
    inPin1 = HIGH;
    inPin2 = LOW;
    //1=FORWARD
  }  
  if(direction == 0){
    inPin1 = LOW;
    inPin2 = HIGH;
    //0=BACKWARD
  }

  if(motor == 1){
    digitalWrite(leftMotor1, inPin1);
    digitalWrite(leftMotor2, inPin2);
    analogWrite(leftMotorPWM, speed);
    // 1=A
  }
  if(motor == 2){
    digitalWrite(rightMotor1, inPin1);
    digitalWrite(rightMotor2, inPin2);
    analogWrite(rightMotorPWM, speed-6);
    // 2=B
  }  
}

void left_90(){
  int i;
  for(i=1; i<100; i++){
     RUN( 1 , 70 , 1);
     RUN( 2 , 70 , 0);
     delay(20);
  }
}

void right_90(){
  int i;
  for(i=1; i<100; i++){
     RUN( 1 , 70 , 0);
     RUN( 2 , 70 , 1);
     delay(20);
  }
}

void u_turn(){
  int i;
  for(i=1; i<60; i++){
     RUN( 1 , 70 , 0);
     RUN( 2 , 70 , 1);
     delay(20);
  }
}