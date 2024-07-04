int pin=3;
void setup() {
  // put your setup code here, to run once:
pinMode(pin,OUTPUT);
Serial.begin(9600);
digitalWrite(pin,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
String a;
Serial.print("input your command: ");
while(Serial.available()==0){}
a=Serial.readString();
Serial.println(a);
if(a=="Lights on"){
  digitalWrite(pin,LOW);
}
if(a=="Lights off"){
  digitalWrite(pin,HIGH);
}
if(a=="alarm"){
  long int min,sec;
  Serial.println("input timer value: ");
  while(Serial.available()==0){}
  min= Serial.parseInt();
  sec=min*60000;
  Serial.print("timer set for ");Serial.print(min);Serial.println(" minute");
  
  delay(sec);
  for(int i=1;i<=10;i++){
    alarm();
  }
}
}
void alarm(){
  digitalWrite(pin,HIGH);delay(300);
  digitalWrite(pin,LOW);delay(300);
}
