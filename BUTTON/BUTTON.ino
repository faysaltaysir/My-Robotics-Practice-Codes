#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int k1 = 6, k2 =5, k3 = 4;
static int a=0,j=0,b;
class Button{
  int buttonState;        // Current state of the button
  int lastButtonState;    // Previous state of the button
  int buttonState_1;        // Current state of the button
  int lastButtonState_1;    // Previous state of the button
  bool outputState;      // Current state of the output (OFF by default)
  int buttonPin,counter=0; 
  public:
  Button(int pin){
    buttonPin = pin;       // Pin connected to the button
    buttonState = HIGH;        // Current state of the button
    lastButtonState = HIGH;    // Previous state of the button
    outputState = false;      // Current state of the output (OFF by default)
    pinMode(buttonPin, INPUT);  // Set buttonPin as input with internal pull-up resistor
  }
  static void display_1(){
      lcd.setCursor(3, 0);
      lcd.print("1) Meal");lcd.setCursor(3, 1);
      lcd.print("2) Desert");
  }
  static void display_2(int x,int flag){
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
  static bool longPress(){
  int count = 0;int x=1;
  while(!digitalRead(k3)){
    count++;
    delay(100);
    Serial.println(count); 
    if(count>12){  
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
  int onPress(){
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
      return 1;
    }
    else {
      outputState = false;
      return 0;
    }
  }return 0;
  lastButtonState = buttonState;
  }   
};
int flag = 0, q = 1, k = 0, p = 1, g = 1, bPress;
void setup() {
  
  Serial.begin(9600); lcd.begin(16, 2);
 Button a(k1), b(k2), c(k3), d(k1), e(k2), f(k3);
  while( 1 ) { 
    if( a.press() ) { 
      Button :: display_1();
      bPress = b.onPress();
      Button :: display_2( bPress, flag );
      int a=1;
      if( bPress ){
        int press = c.press();
        while( press ){
          if(a == 1) { lcd.clear(); a = 0;}
          lcd.setCursor(3, 0);lcd.print("1) Ice Cream");
          lcd.setCursor(3, 1);lcd.print("2) Milk Shake");
          int bPress = !b.onPress();              
          Button :: display_2(bPress, flag);int x = 1; 
          int longPress = Button :: longPress(); 
          while( longPress ) {k=0;
            Serial.println("Done");
            int bPress = b.onPress();flag=1;
            Button::display_2(bPress,flag);
            int cPress = c.onPress();
            cPress = c.press();Serial.print(cPress);
            if( !bPress && cPress ){
            k = 1;
            while ( k == 1) {
              delay( 200 );
              if(q == 1 ) { lcd.clear(); q=0;}
              lcd.setCursor(0, 0);lcd.print("Confirmed Order");
            }
          }
          else if( bPress && cPress ){k = 2;Serial.print(k);
            while(k==2) {
              delay(200);
              if(p == 1) {lcd.clear(); p = 0;}
              lcd.setCursor(0, 0);lcd.print("Order Canceled:)");
            }
          }
        }  
      }
    }
      else{
        int fpress = f.press();
        while(fpress){
          if(g==1) {lcd.clear();g=0;}
          lcd.setCursor(3, 0);lcd.print("1) Fried Rice");
          lcd.setCursor(3, 1);lcd.print("2) Chicken");
          int ePress = e.onPress();
          Button::display_2(ePress,flag); int x=1; 
          int longPress = Button::longPress(); 
          while(longPress) {k=0;
            Serial.println("Done");
          int ePress = e.onPress();flag=1;
          Button::display_2(ePress,flag);
          int cPress = f.onPress();
          cPress = f.press();Serial.print(cPress);
          if(!ePress && cPress){
            k=1;
            while(k==1) {
              delay(200);
              if(q==1) {lcd.clear();q=0;}
              lcd.setCursor(0, 0);lcd.print("Confirmed Order");Serial.print("dadaa");
            }
          }
          else if(ePress && cPress){k=2;Serial.print(k);
          while(k==2) {
            delay(200);
             if(p==1) {lcd.clear();p=0;}
             lcd.setCursor(0, 0);lcd.print("Order Canceled:)");Serial.print("dad");
          }
          }
          }
        }
      }
       
    } 
  }
}
void loop(){ 

}


