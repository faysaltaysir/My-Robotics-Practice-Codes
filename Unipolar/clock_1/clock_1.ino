#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 30, en = 32, d4 = 28, d5 = 26, d6 = 24, d7 = 22;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String date,time,current_time,on,off,h,m,x= " OFF";
int hour_0,minute_0,hour_1,minute_1,hour,minute,on_hour,off_hour,on_minute,off_minute;
int LED=10;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  input();lcd.setCursor(3, 0);lcd.print(date);
  while(1){
    String a=output(hour,minute);lcd.setCursor(3, 1);
    Serial.println(a);
    lcd.print(a);
    delay(1000);
  }
}

