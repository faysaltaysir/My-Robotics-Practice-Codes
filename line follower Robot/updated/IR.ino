//Funtion
void Calibration(){
    qtr.setTypeRC();
  qtr.setSensorPins((const uint8_t[]){5, 7, 9, 11,3, 15, 17, 19,21,23}, SensorCount);

  delay(500);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  for (uint16_t i = 1; i <= 300; i++)
  { 
    qtr.calibrate();
  }
  digitalWrite(LED_BUILTIN, LOW);
  
  calibrate();
}

//Funtion

int Read_Values(){
  String str;qtr.readCalibrated(sensorValues);
  uint16_t Position = qtr.readLineBlack(sensorValues); 
  Serial.print(Position);Serial.println('\t');
  for (int i = 0; i < SensorCount; i++)
  {
    if (sensorValues[i] > threshold_value[i]){
       str += '1';
       digitalWrite(arr[i],1);
    }
    else {
      digitalWrite(arr[i],0);
      str += '0';
    } 
    Serial.print(sensorValues[i]);Serial.print("  ");
  }s = str;
  //Serial.print(str);
  Serial.println("");
  
}
