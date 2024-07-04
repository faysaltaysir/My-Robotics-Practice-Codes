
int leftMotorH =4; 
int leftMotorL =3; 
//int enable1Pin =2; 
int rightMotorH =5; 
int rightMotorL = 6; 
//int enable2Pin = 7;

int speed=255;


void setup() {
  
 pinMode(leftMotorH, OUTPUT);
  pinMode(leftMotorL, OUTPUT);
 // pinMode(enable1Pin, OUTPUT);
  pinMode(rightMotorH, OUTPUT);
  pinMode(rightMotorL, OUTPUT);
  //pinMode(enable2Pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(rightMotorH,LOW);
digitalWrite(rightMotorL,HIGH);
//analogWrite(enable1Pin, speed);
digitalWrite(leftMotorH,HIGH);
digitalWrite(leftMotorL,LOW);
//analogWrite(enable2Pin, speed);

}
