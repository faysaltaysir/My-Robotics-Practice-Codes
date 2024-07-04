#include <QTRSensors.h>
#define kp 0.0067  // find the best value speed controll
#define ki 0
#define kd 0

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
  Calibration();
  motor_setup();
  for(int i=0;i<10;i++){
    pinMode(arr[i],OUTPUT);
  }
  
}
int i=0; char s[100];
//String s = " ";
void loop()
{
 //  0 1 2 3 4 5 6 7 8 9 
 //  0 0 0 0 0 0 0 0 0 0 
 Run(1,150,0);
 Run(2,100,0);delay(1400);
  Read_Values();
  uint16_t Position = qtr.readLineBlack(sensorValues); 
   Serial.print(Position);Serial.println('\t');
   qtr.readCalibrated(sensorValues);
   
   if (sensorValues[0] > threshold_value[0] && sensorValues[2] > threshold_value[2] &&sensorValues[4] > threshold_value[4]){
      //Serial.print("left_90   ");Serial.print(Position);Serial.println('\t');
      //s[i]="L";i++;Serial.println(i);
      path += 'L';
      wait();
      left_90();
   }

 /* else if (sensorValues[0] > 500 && sensorValues[2] > 500 &&sensorValues[4] > 500&&sensorValues[7] > 500&&sensorValues[9] > 500){
      //Serial.print("left_90   ");Serial.print(Position);Serial.println('\t');
      //s[i]="L";i++;Serial.println(i);
      wait();
      qtr.read(sensorValues);
      if(sensorValues[2] < 500 && sensorValues[4] < 500 &&sensorValues[6] < 500){
        left_90();
      }
      
   }   */
   else if (sensorValues[9] > threshold_value[9] && sensorValues[7] > threshold_value[7] &&sensorValues[5] > threshold_value[5]){
      //Serial.print("right_90   ");Serial.print(Position);Serial.println('\t');
     
      wait();
      qtr.read(sensorValues);
      if(sensorValues[2] < 500 && sensorValues[4] < 500 &&sensorValues[6] < 500){  // if White
        right_90(); path += 'R';
      }
      else{
        path += 'S';return;
      }
        
      //Serial.print("Right");
   }
   
   else if (Position == 9000){
     // s[i]="B";i++;Serial.println(i);Serial.println(s);
     path += 'B';//Serial.println(path);
      wait();delay(1000);
      left_90();
      //s[i]=0;
      // for(int j=0;j<=i;j++){
      //   x[i]=s[i];
      // }
      //Serial.println(s);
      //left_90();
   }
  else 
  pid();
 
 //pid();
}

void wait(){
  delay(100);
  Run(1,70,0);
  Run(2,70,0);delay(100);
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
