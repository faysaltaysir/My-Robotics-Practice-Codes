#include <QTRSensors.h>  
  
QTRSensors qtr;  
  
const uint8_t SensorCount = 10;  
uint16_t sensorValues[SensorCount];  
// uint16_t threshold[SensorCount];  
// uint16_t max_value[SensorCount]={0,0,0,0,0,0,0,0,0,0};  
// uint16_t min_value[SensorCount]={1000,1000,1000,1000,1000,1000,1000,1000,1000,1000};  
// String s="0000000000";  
// PID Properties  
const double KP = 0.016; //0.02 original    
const double KD = 0.07;  
double lastError = 0;  
const int GOAL = 4500;  
const unsigned char MAX_SPEED = 80;  
  
#define AIN1 10  
#define BIN1 13  
#define AIN2 8  
#define BIN2 12  
#define PWMA 9  
#define PWMB 11  
  
  
void setup()  
{  
  
  pinMode(AIN1,OUTPUT);          
  pinMode(AIN2,OUTPUT);  
  pinMode(PWMA,OUTPUT);  
    
  pinMode(BIN1,OUTPUT);          
  pinMode(BIN2,OUTPUT);  
  pinMode(PWMB,OUTPUT);  
  
  // configure the sensors  
  qtr.setTypeRC();  
  qtr.setSensorPins((const uint8_t[]){A5,A4,A3,A2,A1,A0,4,5,6,7}, SensorCount);  
  
  delay(500);  
  pinMode(LED_BUILTIN, OUTPUT);  
  digitalWrite(LED_BUILTIN, HIGH); // turn on Arduino's LED to indicate we are in calibration mode  
  
  for (uint16_t i = 0; i < 200; i++)  
  {  
    qtr.calibrate();  
  }  
  digitalWrite(LED_BUILTIN, LOW);   
  Serial.begin(9600);  
  for (uint8_t i = 0; i < SensorCount; i++)  
  {  
    Serial.print(qtr.calibrationOn.minimum[i]);  
    Serial.print(' ');  
  }  
  Serial.println();  
  
  // print the calibration maximum values measured when emitters were on  
  for (uint8_t i = 0; i < SensorCount; i++)  
  {  
    Serial.print(qtr.calibrationOn.maximum[i]);  
    Serial.print(' ');  
  }  
 
  Serial.println();  
  Serial.println();  
  delay(1000);  
}  
void loop() {  
  
  // Get line position  
  uint16_t position = qtr.readLineBlack(sensorValues);  
  uint16_t position2 = qtr.readLineWhite(sensorValues);
  int black=0; 
  for (uint8_t i = 0; i < SensorCount; i++)  
    {  
      if(sensorValues[i]==2500) black++; 
    } 
    if(black==10) { setMotorA(50);setMotorB(50); delay(200); Break();}
  if(sensorValues[0]>500 && sensorValues[9]>500){
      position=position2;
    }
  

  int error = GOAL - position;  
        for (uint8_t i = 0; i < SensorCount; i++)  
        {  
          // if(sensorValues[i]>threshold[i]) s[i]='1';  
          // else s[i]='0';  
          // Serial.print(sensorValues[i]);  
          // Serial.print('\t');  
        }  
        // Serial.print(lastError);  
        // Serial.print("\t\t");  
        Serial.print(position2);  
        Serial.println();  
        
     
 
    if(abs(lastError)<500 && (position==0 || position==9000 ) ) u_turn();  
    else if(abs(lastError)<500  && error<2000 && sensorValues[9]<200 && (sensorValues[0]>500) ) {  
        turn_30_left();  
    }  
    else if(abs(lastError)<500 && error<2000  && sensorValues[0]<200 && (sensorValues[9]>500) ) {  
        turn_30_right();  
    } 
    else if(sensorValues[0]>500 && sensorValues[1]>500 && sensorValues[2]>500 && sensorValues[3]>500 && sensorValues[4]>500) {
      turn_30_left();
    }
    else if(sensorValues[9]>500 && sensorValues[8]>500 && sensorValues[7]>500 && sensorValues[6]>500 && sensorValues[5]>500) {
      turn_30_right();
    }  
  // if( s=="1111000001"  s=="0001110001"  s=="0000110001"  s=="0000110011"  s=="0000111001"|| s=="0000111011"|| s=="0001110011"|| s=="0001110001"){  
  //   turn_30_right();  
  // }  
  // if( s=="1000001111"  s=="1000111000"  s=="1110111111"  s=="1000110000"  s=="1100110000"  s=="1001110000" s=="1101110000"|| s=="1100111000" || s=="1000111000" ){  
  //   turn_30_left();  
  // }  
  // Compute error from line  
   
  
  
  // Compute motor adjustment  
  int adjustment = KP*error + KD*(error - lastError);  
  
  // Store error for next increment  
  lastError = error;  
  
  // Adjust motors   
  setMotorA(MAX_SPEED - adjustment);  
  setMotorB(MAX_SPEED + adjustment);  
  
}  
  
void setMotorA (int adjust) {  
  if(adjust>0){  
    digitalWrite(AIN1,HIGH);  
    digitalWrite(AIN2,LOW);  
    if(abs(adjust)>MAX_SPEED) adjust=MAX_SPEED;  
    analogWrite(PWMA,abs(adjust));  
  }  
  if(adjust<0){  
    digitalWrite(AIN1,LOW);  
    digitalWrite(AIN2,HIGH);  
    if(abs(adjust)<MAX_SPEED) adjust=MAX_SPEED;  
    analogWrite(PWMA,abs(adjust)); 
}  
}  
void setMotorB(int adjust) {  
  if(adjust>0){  
    digitalWrite(BIN1,HIGH);  
    digitalWrite(BIN2,LOW);  
    if(abs(adjust)>MAX_SPEED) adjust=MAX_SPEED;  
    analogWrite(PWMB,abs(adjust));  
  }  
  if(adjust<0) {   
    digitalWrite(BIN1,LOW);  
    digitalWrite(BIN2,HIGH);  
    if(abs(adjust)<MAX_SPEED)
    adjust=MAX_SPEED;  
    analogWrite(PWMB,abs(adjust));  
  }  
}  
  
void turn_30_left(){  
  Serial.print("30 left0\t\t");  
  uint16_t positions = qtr.readLineBlack(sensorValues);  
  setMotorA(50);  
  setMotorB(50);  
  delay(250);  
  Break();  
  delay(10);  
  setMotorB(10);  
  setMotorA(-10);  
  positions = qtr.readLineBlack(sensorValues);  
  while(positions==0 || positions==9000){  
    Serial.print("30 left\t\t");  
    positions = qtr.readLineBlack(sensorValues);  
  }  
}  
  
void turn_30_right(){  
  
  uint16_t positions = qtr.readLineBlack(sensorValues);  
  Serial.print("30 right");  
  setMotorA(50);  
  setMotorB(50);  
  delay(250);  
  Break();  
  setMotorB(-10);  
  setMotorA(10);  
  positions = qtr.readLineBlack(sensorValues);  
  while(positions==0 || positions==9000){  
    Serial.print("30 right");  
    positions = qtr.readLineBlack(sensorValues);  
  }  
}  
void u_turn(){  
  
  uint16_t positions = qtr.readLineBlack(sensorValues);  
  Serial.print("30 right");  
  setMotorA(50);  
  setMotorB(50);  
  delay(250);  
  
    
  positions = qtr.readLineBlack(sensorValues);  
  while(positions==0 || positions==9000){  
    setMotorB(50);  
  setMotorA(-50); 
    Serial.print("30 right");  
    positions = qtr.readLineBlack(sensorValues);  
  }  
}  
void Break(){  
  digitalWrite(AIN1,LOW);  
    digitalWrite(AIN2,LOW);  
    digitalWrite(BIN1,LOW);  
    digitalWrite(BIN2,LOW);  
}
