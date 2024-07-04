int sensor_value[20],threshold_value[20],min_value[20],max_value[20];
int total_value=0,line_value=0;

void setup(){
  pinMode(32,INPUT);
  pinMode(33,INPUT);
  pinMode(25,INPUT);
  pinMode(13,INPUT);
  pinMode(12,INPUT);
  pinMode(14,INPUT);
  pinMode(27,INPUT);
  pinMode(26,INPUT);
  pinMode(22,INPUT);
  pinMode(23,INPUT);
  Serial.begin(9600);
}//32,33,25,13,12,14,27,26,22,23
void loop(){
  callibrate();
  read_lines();
}
void read_lines() {
  for (int i = 0; i < 10; i++) {
    sensor_value[i] = analogRead(i);
    if (sensor_value[i] > threshold_value[i]) {
      sensor_value[i] = 1;
    } else {
      sensor_value[i] = 0;
    }
    Serial.println("sensor_value[i]");
    Serial.println(sensor_value[i]);
  }
  int line_value = 0;
  int total_value = 0;

  for (int i = 1; i <= 10; i++) {
    line_value = line_value + (sensor_value[i - 1] * i * 1000);
    total_value = total_value + sensor_value[i - 1];
  }
  int position=(line_value/total_value);
  Serial.println("position");
  Serial.println(position);
}
void  callibrate()
{
  for(int i=0;i<10;i++)
  {
    min_value[i]=analogRead(i);
    max_value[i]=analogRead(i);
  }
  for( int i=0;i<3000;i++)
  {
   /* digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    analogWrite(enA,50);
    digitalWrite(in1,LOW);
    digitalWrite(in1,HIGH);
    analogWrite(enB,50);*/

    for(int i=0;i<10;i++)
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
  for(int i=0;i<10;i++)
  {
    threshold_value[i]=(min_value[i]+max_value[i])/2;
    Serial.print(" ");Serial.print(threshold_value[i]);
  }
}