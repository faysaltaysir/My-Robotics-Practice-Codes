#include <QTRSensors.h>
#include <QTRSensors.h>
#define kp 0.0067  // find the best value speed controll
#define ki 0
#define kd 0
// This example is designed for use with six analog QTR sensors. These
// reflectance sensors should be connected to analog pins A0 to A5. The
// sensors' emitter control pin (CTRL or LEDON) can optionally be connected to
// digital pin 2, or you can leave it disconnected and remove the call to
// setEmitterPin().
//
// The main loop of the example reads the raw sensor values (uncalibrated). You
// can test this by taping a piece of 3/4" black electrical tape to a piece of
// white paper and sliding the sensor across it. It prints the sensor values to
// the serial monitor as numbers from 0 (maximum reflectance) to 1023 (minimum
// reflectance).

QTRSensors qtr;

const uint8_t SensorCount = 10;
uint16_t sensorValues[SensorCount];

int in1 = 30, in2 = 28, in3 = 26, in4 = 24, pwm1 = 46, pwm2 = 44;
int leftMotorH =30; 
int leftMotorL =28; 
int enable1Pin =46; 
int rightMotorH =24; 
int rightMotorL = 26; 
int enable2Pin = 44;
float thres=500;

int max_value[12],min_value[12];
  int sensor_pins=10;
  int threshold_value[12];

void setup()
{
  // configure the sensors
    qtr.setTypeRC();//
  qtr.setSensorPins((const uint8_t[]){31, 29, 27, 25, 23, 21, 19, 17, 15,11}, SensorCount);
 // qtr.setEmitterPin(2);
qtr.read(sensorValues);
motor_setup();
callibrate();
  Serial.begin(115200);callibrate();
}

void motor_setup(){
  pinMode(leftMotorH, OUTPUT);
  pinMode(leftMotorL, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  pinMode(rightMotorH, OUTPUT);
  pinMode(rightMotorL, OUTPUT);
  pinMode(enable2Pin, OUTPUT);
 
}

void  callibrate()
{
  
  for(int i=0;i<sensor_pins;i++)
  {
     min_value[i]=2500;
     max_value[i]=0;
     Serial.print(min_value[i]);
     Serial.println(max_value[i]);
  }
  for( int i=0;i<3000;i++)
  {
    /*digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    analogWrite(enA,50);
    digitalWrite(in1,LOW);
    digitalWrite(in1,HIGH);
    analogWrite(enB,50);*/
  qtr.read(sensorValues);
  for(int i=0;i<sensor_pins;i++){
    if(sensorValues[i]<min_value[i]){
        min_value[i]=sensorValues[i];//Serial.print(sensorValues[i]);Serial.print("    ");
       // Serial.print(min_value[i]);Serial.print(" MIN ");
       // Serial.println(max_value[i]);
      }
    if(sensorValues[i]>max_value[i])
      {
        max_value[i]=sensorValues[i];//Serial.print(sensorValues[i]);Serial.print("    ");
        //Serial.print(min_value[i]);
        //Serial.print(" MAX ");
        //Serial.println(max_value[i]);
      }
    }
  }
  for(int i=0;i<sensor_pins;i++)
  {
    Serial.print(min_value[i]);Serial.print("         ");
    Serial.println(max_value[i]);
    threshold_value[i]=(min_value[i]+max_value[i])/2;
    Serial.print(threshold_value[i]);Serial.print("  ");
  }Serial.println("");
}

void loop()
{
  qtr.read(sensorValues);
  for(int i=0;i<sensor_pins;i++){
    // if(sensorValues[i]<threshold_value[i]){
    //   Serial.print('0');
    // }
    // else Serial.print('1');
    Serial.print(sensorValues[i]);Serial.print(" ");
    
  }Serial.println("");
  // read raw sensor values
  //uint16_t Position = qtr.readLineBlack(sensorValues);
  //Serial.println(Position);
  
  // print the sensor values as numbers from 0 to 1023, where 0 means maximum
  // reflectance and 1023 means minimum reflectance
 /* for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.println();
*/
pid();
  //delay(250);
}
