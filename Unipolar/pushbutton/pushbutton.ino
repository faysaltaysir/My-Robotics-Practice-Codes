#include <LiquidCrystal.h>
int i=0;
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 30, en = 32, d4 = 28, d5 = 26, d6 = 24, d7 = 22;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int flag=0;
int but=52,but2=53;
void setup() {
  // put your setup code here, to run once:
pinMode(but,INPUT);
Serial.begin(9600);lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
int x=!digitalRead(but);delay(50);int count=0,count2=0;
if(x){
    lcd.setCursor(3, 0);
    lcd.print("1) Meal");lcd.setCursor(3, 1);
    lcd.print("2) Desert");
  }



if(digitalRead(but2)==0){
  while(digitalRead(but2)==0){

  }i++;
}
if(i==10){
  i=0; 
   if(flag==0){
      lcd.setCursor(0, 1);
      lcd.print("  ");
      lcd.setCursor(0, 0);
      lcd.print("=>");flag=1;
    }
    else if(flag){
       lcd.setCursor(0, 0);
      lcd.print("  ");
      lcd.setCursor(0, 1);
      lcd.print("=>");flag=0;
    }
}
    //lcd.setCursor(0, 0);
    //lcd.print("=>");lcd.setCursor(3, 1);
   
    
    //lcd.print("2) Desert");
  


Serial.println(count);
}
