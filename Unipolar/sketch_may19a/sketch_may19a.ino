
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int flag=0;
const int buttonPin = 6;const int buttonPin_2 = 5;
const int ledPin = 13;

int buttonState_1 = 0;
int counter_1 = 0;
int prevButtonState_1 = LOW;

int buttonState_2 = 0;
int counter_2 = 0;
int prevButtonState_2 = LOW;

int buttonState_3 = 0;
int counter_3 = 0;
int prevButtonState_3 = LOW;
int count2=0;
void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);lcd.begin(20, 4);
  Serial.begin(9600);
}
int button_state(int buttonPin,int k){
  if(k==5){
  buttonState_1 = digitalRead(buttonPin);
  if (buttonState_1 == HIGH && prevButtonState_1 == LOW) {
    counter_1++;
    delay(100);
  }
  prevButtonState_1 = buttonState_1;
  Serial.print("Counter_1: ");
  Serial.println(counter_1);

  counter_1 = counter_1 % 2;
  return counter_1;
  }
  if(k==2){
    buttonState_2 = digitalRead(buttonPin);
    if (buttonState_2 == HIGH && prevButtonState_2 == LOW) {
    counter_2++;
    delay(100);
  }
  prevButtonState_2 = buttonState_2;
  Serial.print("Counter_2: ");
  Serial.println(counter_2);

  counter_2 = counter_2 %2;
  return counter_2;
  }
  if(k==3){
    buttonState_3 = digitalRead(buttonPin);
    if (buttonState_3 == HIGH && prevButtonState_3 == LOW) {
    delay(100);
    return 1;
    }
    else return 0;
  }
  if(k==1){
    buttonState_1 = digitalRead(buttonPin);
    if (buttonState_1 == HIGH && prevButtonState_1 == LOW) {
    delay(100);
    return 1;
    }
    else return 0;
  }
}
void cursor_display(int x){
    if(x){
      lcd.setCursor(0, 1);
      lcd.print("  ");
      lcd.setCursor(0, 0);
      lcd.print("=>");
    }
    else{
      lcd.setCursor(0,0);
      lcd.print("  ");
      lcd.setCursor(0, 1);
      lcd.print("=>");
    }
  }
  void cursor_display_2(int x){int f=1;
    lcd.setCursor(2,1);
    lcd.print(" Yes");
    lcd.setCursor(10,1);
    lcd.print(" No");int key=-1;
    if(x){
      lcd.setCursor(8, 1);
      lcd.print("  ");
      lcd.setCursor(0, 1);
      lcd.print("=>");delay(500);
      
      key=1;
    }
    
    else{
      lcd.setCursor(0,1);
      lcd.print("  ");
      lcd.setCursor(8, 1);
      lcd.print("=>");
      int k = button_state(51,3);key=0;
    }
    
    int k = button_state(51,3);
    while(key==1 && k==0){
       if(f==0) {lcd.clear();f=1;}
      lcd.setCursor(0,1);
      lcd.print("Confirmed");
    }
    while(key==0 && k==0){
       if(f==0) {lcd.clear();f=1;}
      lcd.setCursor(0,1);
      lcd.print("Canceled");
    }
    
    //x = button_state(52,2);
    

    
  }
  

int y=0;

 void meal_display(){
      lcd.setCursor(3,0);
      lcd.print("1) Meal");
      lcd.setCursor(3, 1);
      lcd.print("2) Desert");
    }
    void rice_display(int a){
       if(a==0) {lcd.clear();a=1;}
        lcd.setCursor(3,0);
        lcd.print("1) Fried Rice");
        lcd.setCursor(3, 1);
        lcd.print("2) Chicken fry");
      }
      void icecream_display(int a){
         if(a==0) {lcd.clear();a=1;}//count=0;
           lcd.setCursor(3,0);
           lcd.print("1) Chocolate");
           lcd.setCursor(3, 1);
           lcd.print("2) Ice Cream");
      }
  void confirm(int &a){
            if(a==0) {lcd.clear();a=1;}
              lcd.setCursor(0,0);
              lcd.print("Order Confirm??");
           }




void loop() {
  int x,count=0;
  int z;  // switch
flag=0;
while(y==0 && flag==0){flag=1;
  meal_display();
  x = button_state(52,2);cursor_display(x);
  z = button_state(51,3);int a=0;
  while(x==1 && z==0 && flag==1){
    rice_display(a);
    int x_1 = button_state(52,2);cursor_display(x_1); 
    int z_1 = button_state(51,3);
    while(!button_state(51,3)){
      count2++;delay(50);int a_3=0;
        while(count2>20){
         confirm(a_3);
        }
      }
    }
    while(x==0 && z==0 && flag==1){
      icecream_display(a);
      int x_1 = button_state(52,2);cursor_display(x_1); int a_1=0;
      while(!button_state(51,3)){
        count++;delay(50);Serial.print(count);
        while(count>20){
          confirm(a_1);
          int x_2 = button_state(52,2);
          cursor_display_2(x_2);
        }
      }
      
    }

  }
}









