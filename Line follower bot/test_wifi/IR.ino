//Funtion
void Calibration(){
    qtr.setTypeRC();
  qtr.setSensorPins((const uint8_t[]){13,12,14,27,26,25,33,32,22,23}, SensorCount);
  qtr.setEmitterPin(15);

  delay(500);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  for (uint16_t i = 0; i < 400; i++)
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
  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(qtr.calibrationOn.maximum[i]);
    Serial.print(' ');
  }
  Serial.println();
  Serial.println();
  delay(1000);
}

//Funtion

int Read_Values(){
  uint16_t position_black = qtr.readLineBlack(sensorValues);
  uint16_t position_white = qtr.readLineWhite(sensorValues);

  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.print(position_black);Serial.print("  ");
  Serial.print(position_white);
 
}
