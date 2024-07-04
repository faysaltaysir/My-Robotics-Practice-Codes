

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);


String date,time,current_time,on,off,h,m,x= " OFF";
int hour_0,minute_0,hour_1,minute_1,hour,minute,on_hour,off_hour,on_minute,off_minute;
int LED=13;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(1);
  input();lcd.setCursor(3, 0);lcd.print(date);
  while(1){
    String a=output(hour,minute);lcd.setCursor(3, 1);
    lcd.print(a);
    delay(1000);
  }
}

void input(){
  Serial.println("Input Date: ");
  while(Serial.available()==0){}
  date=Serial.readString();
  Serial.println(date);//lcd.print(date);
Serial.println("Input Current Time: ( HH:MM )");
while(Serial.available()==0){}
  time=Serial.readString(); Serial.println(time);
Serial.println("Input Light On Time : ( HH:MM )");
while(Serial.available()==0){}
  on=Serial.readString(); Serial.println(on);
Serial.println("Input Light Off Time : ( HH:MM )");
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










