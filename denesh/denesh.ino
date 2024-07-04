int motor1pin1 = 4;//LOW// FORWARD
int motor1pin2 = 7;//HIGH  

int motor2pin1 = 9;//LOW
int motor2pin2 = 8;//HIGH
int ena=5;//PWM
int enb=6;//PWM
int mspeed=70;
void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  analogWrite(ena, mspeed); 
  analogWrite(enb, mspeed); 
}

void loop() {
  // put your main code here, to run repeatedly:   
 //backWARD 
  /*digitalWrite(motor1pin1, 0);
  digitalWrite(motor1pin2, 1);

  digitalWrite(motor2pin1, 1);
  digitalWrite(motor2pin2, 0);
  delay(2000);
  
//backWARD 
  digitalWrite(motor1pin1, 1);
  digitalWrite(motor1pin2, 0);

  digitalWrite(motor2pin1, 0);
  digitalWrite(motor2pin2, 1);
  delay(2000);
  */
   digitalWrite(motor1pin1, 0);
  digitalWrite(motor1pin2, 0);
  digitalWrite(motor2pin1, 0);//back
  digitalWrite(motor2pin2, 1);
  
}
