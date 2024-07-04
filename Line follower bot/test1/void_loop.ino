void loop(){  
  String a = "0000000000";
  // print the sensor values as numbers from 0 to 2500, where 0 means maximum
  // reflectance and 2500 means minimum reflectance
  qtr.read(sensorValues);//uint8_t i = 0;
//int thres= 500;
  for (uint8_t i = 0; i < SensorCount; i++) {
   // if (sensorValues[i] > thres)
    //  a[i] = '1';
   // else a[i] = '0';
   Serial.print(sensorValues[i]);
  Serial.print('\t');
  }
  uint16_t Position = qtr.readLineBlack(sensorValues); //read the current position  
  Serial.println(Position);
  if(Position>8000){
    
    right_90();  // turn 90 degree
    
  }
  if(Position<1000){ 
    
    left_90();  // turn 90 degree
   
  }

  PID(Position);
  
}
