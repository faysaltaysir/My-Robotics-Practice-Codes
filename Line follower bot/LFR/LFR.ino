#include <QTRSensors.h>
#define kp 0.01  // find the best value speed controll
#define ki 0
#define kd 0.001
//int kp,ki,kd; 
int in1 = 30, in2 = 28, in3 = 26, in4 = 24, pwm1 = 46, pwm2 = 44;
int leftMotorH =30; 
int leftMotorL =28; 
int enable1Pin =46; 
int rightMotorH =26; 
int rightMotorL = 24; 
int enable2Pin = 44;
float thres=230;
//int l= ,r= ;
// Setting PWM properties
// const int freq = 30000;
// const int pwmChannel = 0;
// const int pwmChannel2 = 1;
// const int resolution = 8;
// int dutyCycle = 200;
String a;
int threshold_value[12];
/* Fill in information from Blynk Device Info here */



// Your WiFi credentials.
// Set password to "" for open networks.






QTRSensors qtr;

const uint8_t SensorCount = 10;
uint16_t sensorValues[SensorCount];
int LED_BUILTIN=2;
void setup()
{
  Calibration();
  motor_setup();//digitalWrite(35,1);
}

void loop()
{
 // String s;Serial.print(Position);
  //Run(1,255,1);
  a = "0000000000";
  Read_Values();
  uint16_t Position = qtr.readLineBlack(sensorValues); 
  pid();
  /*
  if((a[9]=='1' || a[8]=='1'||a[7]=='1') && (a[0]=='0'||a[1]=='0') ){
   // wait();delay(50);
    right_90();Serial.println("  90 DR");//R
  }
  else if((a[0]=='1' || a[1]=='1'||a[2]=='1') && (a[9]=='0'||a[8]=='0') ){
   // wait();delay(50);
    left_90();Serial.println("  90 DL");//R
  }
  /*if((a[0]=='1' && a[1]=='1'||a[2]=='1') && (a[9]=='1' && a[8]=='1') && ){
   // wait();delay(50);
    left_90();Serial.println("  90 DL");//R
  }
 /* else if(a="0111000011"){
    
    right_30();Serial.println("  90 DR");
  }*/
  /*if(a[9]=='1' && a[8]=='1' && a[7]=='1'&& a[6]=='1'&&a[0]=='0'){
   // wait();delay(50);
    right_90();Serial.println("  90 DR");//R
  }
 /* else if(a[8]=='1' && a[7]=='1' && a[7]=='1'&& a[3]=='1'&&a[0]=='1'){
   // wait();delay(50);
    right_90();Serial.println("  90 DR");//R
  }
 /* else if(a[9]=='1' && a[8]=='1' && a[7]=='1'&& a[6]=='1'&& a[0]=='0'){
   // wait();delay(50);
    right_90();Serial.println("  90 DR");//R
  }*/
  /*else if(a[9]=='1' &&a[0]=='0'){
    Run(1,100,1);
    Run(2,100,1);delay(300);
    right_90();Serial.println("  30 DL");//R
  }*/
  /*
  else if(a[0]=='1' || a[1]=='1' || a[2]=='1'){
    left_90();Serial.println("  90 DL");//L
  }
 /* else if(a[0]=='1' && a[9]=='0'){
    Run(1,100,1);
    Run(2,100,1);delay(300);
    left_90();Serial.println("  30 DL");//L
  }*/
  /*else if(a=="0000000000"){
    Run(1,100,1);
    Run(2,100,1);delay(20);
    uint16_t Position = qtr.readLineBlack(sensorValues);
    //if(Position > 4000 && Position < 5000) break;
    //u_turn();
  }
  else{
    pid();  Serial.println(thres);
  }
 //pid();*/
 /*if((a[9] == '1' && a[8] == '1')||(a[9] == '1')){
  right_90();
}
else if((a[0] == '1' && a[1] == '1')||(a[0] == '1')){
  left_90();
}
  else {

    pid();
  }*/
  
}




void motor_setup(){
  pinMode(leftMotorH, OUTPUT);
  pinMode(leftMotorL, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  pinMode(rightMotorH, OUTPUT);
  pinMode(rightMotorL, OUTPUT);
  pinMode(enable2Pin, OUTPUT);
  // configure LED PWM functionalitites
  // ledcSetup(pwmChannel, freq, resolution);
  // ledcSetup(pwmChannel2, freq, resolution);
  // // attach the channel to the GPIO to be controlled
  // ledcAttachPin(enable1Pin, pwmChannel);
  // ledcAttachPin(enable2Pin, pwmChannel2);
}
