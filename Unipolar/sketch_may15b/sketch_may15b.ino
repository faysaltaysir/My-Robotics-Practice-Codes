const int k1 = 48;
const int k2 = 50,buttonState_1;
const int k3 = 52;
int a,b,c,value=0;
int b_priv = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(k1,INPUT);
pinMode(k2,INPUT);
pinMode(k3,INPUT);
Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
a = digitalRead(k1);b = digitalRead(k2);c = digitalRead(k3);
Serial.print("k1 : ");Serial.println(a);
Serial.print("k2 : ");Serial.println(b);
Serial.print("k3 : ");Serial.println(c);delay(100);
  
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
  // if(b_priv==0 && b==1){
  //   value = value -10;

  // }
  // else if(!c){
  //   value = value +10;
  // }
  // Serial.println(value);
}

