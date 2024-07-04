void input(){
  while(Serial.available()==0){}
  date=Serial.readString();
  Serial.println(date);//lcd.print(date);

while(Serial.available()==0){}
  time=Serial.readString(); Serial.println(time);

while(Serial.available()==0){}
  on=Serial.readString(); Serial.println(on);

while(Serial.available()==0){}
  off=Serial.readString(); Serial.println(off);

    on_hour=convert_hour(on);
    on_minute=convert_minute(on);
    off_hour=convert_hour(off);
    off_minute=convert_minute(off);
    hour=convert_hour(time);
    minute=convert_minute(time);
}


int convert_hour(String time){
  hour_0=int(time[0])-48;   hour_1=int(time[1])-48;
  hour = hour_0 * 10 + hour_1; 
  return hour;
}
int convert_minute(String time){
  minute_0=int(time[3])-48; minute_1=int(time[4])-48;
  minute = minute_0 * 10 + minute_1;
  return minute;
}


String output(int &hour,int &minute){
  if(on_hour==hour && on_minute==minute){
      digitalWrite(LED,HIGH);x=" ON ";
  }
  else if(off_hour==hour && off_minute==minute){
      digitalWrite(LED,LOW);x=" OFF";
  }


  h=String(hour);
  m=String(minute);
  if(hour<10){
    if(minute<10) {
      current_time ='0'+h+':'+'0'+m + x;
    }
    else{
      current_time = '0' + h + ':' + m+ x;
    }
  }
  else{
    if(minute<10) {
      current_time = h + ':' + '0' + m+ x;
    }
    else{
      current_time = h + ':' + m+ x;
    }
  }
  
  minute++;
  if(minute>59){
    minute=0;hour++;
  }
  if(hour>23){
    hour=0;
  }
  
  return current_time;
}
