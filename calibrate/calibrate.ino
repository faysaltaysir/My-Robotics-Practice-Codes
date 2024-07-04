
void  callibrate()
{
  int max_value[20],min_value[20];
  int sensor_pins=10;
  float threshold_value[20];
  for(int i=0;i<sensor_pins;i++)
  {
     min_value[i]=analogRead(i);
     max_value[i]=analogRead(i);
  }
  for( int i=0;i<3000;i++)
  {
    /*digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    analogWrite(enA,50);
    digitalWrite(in1,LOW);
    digitalWrite(in1,HIGH);
    analogWrite(enB,50);*/

    for(int i=0;i<sensor_pins;i++)
    {
      if(analogRead(i)<min_value[i])
      {
        min_value[i]=analogRead(i);
      }
      if(analogRead(i)>max_value[i])
      {
        max_value[i]=analogRead(i);
      }
    }
  }
  for(int i=0;i<sensor_pins;i++)
  {
    threshold_value[i]=(min_value[i]+max_value[i])/2;
    
  }
}
