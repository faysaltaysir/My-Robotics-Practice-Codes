
void  calibrate()
{
  
  for(int i=0;i<SensorCount;i++)
  {
     min_value[i]=1005;
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
//qtr.read(sensorValues);
qtr.readCalibrated(sensorValues);
    for(int i=0;i<SensorCount;i++)
    {
      if(sensorValues[i]<min_value[i])
      {
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
  for(int i=0;i<SensorCount;i++)
  {
    Serial.print(min_value[i]);Serial.print("         ");
    Serial.println(max_value[i]);
    threshold_value[i]=(min_value[i]+max_value[i])/2;
    Serial.print(threshold_value[i]);Serial.print("  ");
  }Serial.println("");
}

