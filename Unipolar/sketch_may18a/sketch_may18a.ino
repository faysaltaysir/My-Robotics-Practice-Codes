#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
static int k1=6,k2=5,k3=4,v1,v2,v3;

int buttonState_1 = HIGH;        // Current state of the button
int lastButtonState_1 = HIGH;
int buttonState_2 = HIGH;        // Current state of the button
int lastButtonState_2 = HIGH;
int buttonState_3 = HIGH;        // Current state of the button
int lastButtonState_3 = HIGH; 
void print(){
  Serial.print("  v1: ");Serial.print(v1);
  Serial.print("  v2: ");Serial.print(v2);
  Serial.print("  v3: ");Serial.println(v3);
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(k1,INPUT);
  pinMode(k2,INPUT);
  pinMode(k3,INPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  while(digitalRead(k1)){
    
  }
  
  v2 = digitalRead(k2); 
  v3 = digitalRead(k3);
  //print();
  lcd.print(v1);
}
