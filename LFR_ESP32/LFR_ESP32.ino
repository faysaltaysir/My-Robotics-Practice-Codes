#include <QTRSensors.h>
#define kp 0.0067  // find the best value speed controll
#define ki 0
#define kd 0.067

//int in1 = 30, in2 = 28, in3 = 26, in4 = 24, pwm1 = 46, pwm2 = 44;
int leftMotorH =21; 
int leftMotorL =19; 
int enable1Pin =18; 
int rightMotorH =17; 
int rightMotorL = 16; 
int enable2Pin = 5;
float thres=500;

const int freq = 30000;
const int pwmChannel = 0;
const int pwmChannel2 = 1;
const int resolution = 8;
//int dutyCycle =0;

String a;
int threshold_value[12];
int min_value[12];
int max_value[12];

QTRSensors qtr;

const uint8_t SensorCount = 10;
uint16_t sensorValues[SensorCount];

void setup()
{
  Serial.begin(115200);
  Calibration();
  motor_setup();
  
}
int i=0; char s[100];
//String s = " ";
void motor(){
  Serial.println("Moving Forward");
  /*digitalWrite(leftMotorH, LOW);
  digitalWrite(leftMotorL, HIGH); 
  digitalWrite(rightMotorH, 0);
  digitalWrite(rightMotorL, 1); 
  dutyCycle+=10;
  Serial.println(dutyCycle);
  ledcWrite(pwmChannel, dutyCycle); 
  ledcWrite(pwmChannel2, dutyCycle); 
  */
  Run(1,250,1);
  Run(2,250,1);delay(2000);
}
void loop()
{
 //  0 1 2 3 4 5 6 7 8 9 
 //  0 0 0 0 0 0 0 0 0 0 
 //motor();
  //Read_Values();
  uint16_t Position = qtr.readLineBlack(sensorValues); 
   Serial.print(Position);Serial.println('\t');
   qtr.read(sensorValues);
   if (sensorValues[9] > threshold_value[9] && sensorValues[8] > threshold_value[8] &&sensorValues[7] > threshold_value[7]&&sensorValues[6] > threshold_value[6]&&sensorValues[5] > threshold_value[5] ){
      //Serial.print("right_90   ");Serial.print(Position);Serial.println('\t');
//      s[i]="R";i++;
      wait();
      right_90();
      //Serial.print("Right");
   }
   else if (sensorValues[0] > threshold_value[0] && sensorValues[1] > threshold_value[1] &&sensorValues[2] > threshold_value[2]&&sensorValues[3] > threshold_value[3]&&sensorValues[4] > threshold_value[4]){
      //Serial.print("left_90   ");Serial.print(Position);Serial.println('\t');
     // s[i]="L";i++;Serial.println(i);
      wait();
      left_90();
   }
  /* else if (Position == 9000){
      s[i]="B";i++;Serial.println(i);Serial.println(s);
      wait();
      left_90();
      s[i]=0;
      // for(int j=0;j<=i;j++){
      //   x[i]=s[i];
      // }
      Serial.println(s);
      //left_90();
   }*/
  else 
  pid();
 
 //pid();
}

void wait(){
  delay(50);
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
  
  ledcSetup(pwmChannel, freq, resolution);
  ledcSetup(pwmChannel2, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(enable1Pin, pwmChannel);
  ledcAttachPin(enable2Pin, pwmChannel2);

 // Serial.begin(115200);
 
}
