//Funtion
void Calibration(){
    qtr.setTypeRC();
  qtr.setSensorPins((const uint8_t[]){31, 29, 27, 25, 23, 21, 19, 17, 15,11}, SensorCount);
int LED_BUILTIN = 2;
  delay(500);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  for (uint16_t i = 1; i <= 300; i++)
  { 
    qtr.calibrate();
  }
  digitalWrite(LED_BUILTIN, LOW);
  calibrate();
/*
  Serial.begin(9600);Serial.println();
  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(qtr.calibrationOn.minimum[i]);
    Serial.print(' ');//x=qtr.calibrationOn.minimum[i];
  }
  Serial.println();
  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(qtr.calibrationOn.maximum[i]);
    Serial.print(' ');//y=qtr.calibrationOn.maximum[i];
  }Serial.println();
  for(int i=0;i<SensorCount;i++)
  {
    threshold_value[i]=(qtr.calibrationOn.minimum[i]+qtr.calibrationOn.maximum[i])/2;
    Serial.print(threshold_value[i]);Serial.print("  ");
  }
  
  Serial.println();
  Serial.println();
  delay(1000);*/
}

//Funtion

int Read_Values(){
  int position_black = qtr.readLineBlack(sensorValues);  Serial.print(position_black);Serial.println('\t');
  int position_white = qtr.readLineWhite(sensorValues);

  for (int i = 0; i < SensorCount; i++)
  {
    if (sensorValues[i] > threshold_value[i])
      a[i] = '1';
    else a[i] = '0';
    Serial.print(sensorValues[i]);Serial.print("  ");
    //
  }Serial.println(a);
Serial.print("  ");
  //Serial.print(position_white);
 
}
