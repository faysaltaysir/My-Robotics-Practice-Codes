#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int k1 = 6, k2 = 5, k3 = 4;
int flag = 0, q = 1, k = 0, p = 1, g = 1;
static int a = 0, j = 0, b,num=0,num2=0;
String ice = "Ice Cream",milk = "Milk Shake",meal="Meal",desert="Desert",rice="Fried Rice",chicken = "Chicken",value="rice";

class Button{
  int buttonState;       
  int lastButtonState;   
  int buttonState_1;       
  int lastButtonState_1;   
  bool outputState;     
  int buttonPin,counter; 
  public:
  Button(int pin){
    buttonPin = pin;       
    buttonState = HIGH;        // Current state 
    lastButtonState = HIGH;    // Previous state 
    outputState = false;      // Current state 
    pinMode(buttonPin, INPUT); 
    counter=1;
  }
  bool longPress(){
  int count = 0;int x=1;
  while(!digitalRead(k3)){
    count++;
    delay(100);
    if(count>10){  
      j=1;
      if(x==1) {lcd.clear();x=0;}
      lcd.setCursor(3, 0);lcd.print("Confirmed ???");
      lcd.setCursor(3, 1);lcd.print("Yes");
      lcd.setCursor(12, 1);lcd.print("No");
      lcd.setCursor(0, 1);lcd.print("=>");
    }
  }
  return j;
  }
  bool onPress(){
    buttonState_1 = digitalRead(buttonPin);
    if (buttonState_1 == HIGH && lastButtonState_1 == LOW) {
      counter++;
      delay(100);
    }
    lastButtonState_1 = buttonState_1;
    counter = counter % 2;
    return counter;
  }

  bool press() {
    buttonState = digitalRead(buttonPin);
    if (buttonState != lastButtonState) {     
      delay(50);
      if (buttonState == LOW) {
        outputState = true;a=1;
        delay(200);
        return 1;
    }   
  }
  lastButtonState = buttonState;
  return 0;
  }   
};

void display_1(String a, String b){
    lcd.setCursor(3, 0);lcd.print("1) ");lcd.print(a);
    lcd.setCursor(3, 1);lcd.print("2) ");lcd.print(b);
}

void display_2(int x,int flag){
  int i,j,k,l;
  if(flag){
      i=0,j=1,k=9,l=1;
  }
  else{
      i=0,j=0,k=0,l=1;
  }
  if(x){
      lcd.setCursor(i, j);
      lcd.print("  ");
      lcd.setCursor(k, l);
      lcd.print("=>");
  }
  else{
    lcd.setCursor(k, l);
    lcd.print("  ");
    lcd.setCursor(i, j);
    lcd.print("=>");
  }
}
int confirm(Button c,int bPress){int m = 1 , n = 1;
  int cPress = c.onPress();
  cPress = c.press();
  if(digitalRead(k1)==0) {
    return 1;
  }
  if( !bPress && cPress ) {
  k = 1;
  while ( k == 1) {
    if(digitalRead(k1)==0){
      return 1;
    }
    
    if(q == 1 ) { lcd.clear(); q=0;}
    lcd.setCursor(0, 1);lcd.print("Order Confirmed");
    lcd.setCursor(3, 0);lcd.print(value);
    if(m == 1 ) { Serial.print("Order Confirmed : ");
    Serial.println(value); m=0;}
    
    }
  }
  else if( bPress && cPress ){k = 2;
  if(digitalRead(k1)==0){
    return 1;}
    while(k==2) {
    if(digitalRead(k1)==0){
      return 1;}
     
      if(p == 1) {lcd.clear(); p = 0;}
      lcd.setCursor(0, 1);lcd.print("Order Canceled:)");
      if(n == 1 ) {
        Serial.println("Order Canceled:)");n=0;
      }
    }
  }
}
void save(int a,int b){
       if (a==0 && b==1) value = rice;
  else if (a==1 && b==1) value = chicken;
  else if (a==0 && b==2) value = ice;
  else if (a==1 && b==2) value = milk;
}
void setup() {
  int bPress;
  Serial.begin(9600); lcd.begin(16, 2);
  Button a(k1), b(k2), c(k3), d(k1), e(k2), f(k3);
  m:
  int n = 1;
  if(n==1){ 
    lcd.clear(); 
    n = 0;
    flag=0;
  }
  while( 1 ) { 
    if(digitalRead(k1)==0){
      asm volatile ("  jmp 0");
    }
    if( !a.press() ) { 
      display_1( meal, desert );
      bPress= b.onPress();
      display_2( bPress, flag );
      int a=1;
      if( bPress ){
        int press = c.press();
        while( press ){
          if(digitalRead(k1)==0){
            asm volatile ("  jmp 0");
          }
          if(a == 1) {lcd.clear();a = 0;}
          display_1( ice, milk );
          bPress = b.onPress();              
          display_2(bPress, flag);int x = 1; 
          int longPress = c.longPress();
          save(bPress,2);
          while( longPress ) {
            if(digitalRead(k1)==0){
              asm volatile ("  jmp 0");
            }
            k=0;
            int bPress_3 = b.onPress();
            flag=1;
            display_2(bPress_3,flag);
            int k = confirm(c,bPress_3);
            if(k==0){
              asm volatile ("  jmp 0");
            }
          }  
        }
      }
      else{
        int fpress = f.press();
        while( fpress ){
          if(digitalRead(k1)==0){
            asm volatile ("  jmp 0");
          }
          if( g == 1 ) { lcd.clear(); g = 0;}

          display_1(rice, chicken);
          int ePress_1 = e.onPress();
          display_2 ( ePress_1, flag ); 
          int x = 1; 
          int longPress = f.longPress(); 
          save(ePress_1,1);
          while( longPress ) { 
            if(digitalRead(k1)==0){
              asm volatile ("  jmp 0");
            }
            k = 0;
            int ePress_2 = e.onPress ();
            flag = 1;
            display_2(ePress_2, flag);
            int h = confirm(f,ePress_2);
            if(h==0){
              asm volatile ("  jmp 0");
            }
          }
        }
      } 
    } 
  }
}
void loop(){ 
}


