#include <QTRSensors.h>


String path;
int threshold_value[12];
int min_value[12];
int max_value[12];

int arr[] = {A2,A4,A6,A8,A10,A12,A14,32,34,36};
int arr2[] = {5, 7, 9, 11,3, 15, 17, 19,21,23};
QTRSensors qtr;

const uint8_t SensorCount = 10;
uint16_t sensorValues[SensorCount];

void setup()
{
  Serial.begin(9600);
  Calibration();
  for(int i=0;i<10;i++){
    pinMode(arr[i],OUTPUT);
  }
  /*for(int i=0;i<10;i++){
    pinMode(arr2[i],INPUT);
  }
  */
}
int i=0; char s[100];
//String Str;
void loop()
{

//value();
  Read_Values();
  
  
   
}/*
void value(){
  for(int i=0;i<10;i++){
    int x = analogRead(arr2[i]);
    Serial.print(x);Serial.print(" ");
  }Serial.println("");
}*/
