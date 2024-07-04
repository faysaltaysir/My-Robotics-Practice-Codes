
void  calibrate()
{
  
  for(int i=0;i<SensorCount;i++)
  {
     min_value[i]=1005;
     max_value[i]=0;
     Serial.print(min_value[i]);Serial.print(" ");
     Serial.println(max_value[i]);
  }
  for( int i=0;i<3000;i++)
  {
    qtr.readCalibrated(sensorValues);
    for(int i=0;i<SensorCount;i++)
    {
      if(sensorValues[i]<min_value[i])
      {
        min_value[i]=sensorValues[i];
      }
    if(sensorValues[i]>max_value[i])
      {
        max_value[i]=sensorValues[i];
      }
     // Serial.print(min_value[i]);Serial.print(" ");
     //Serial.println(max_value[i]);
      //Serial.print(sensorValues[i]);Serial.print("  ");
    }//Serial.println("");
  }
  for(int i=0;i<SensorCount;i++)
  {
    Serial.print(min_value[i]);Serial.print("    ");
    Serial.print(max_value[i]);Serial.print("    ");
    threshold_value[i]=((min_value[i]+max_value[i])/2);
    Serial.println(threshold_value[i]);
  }Serial.println("");
}

