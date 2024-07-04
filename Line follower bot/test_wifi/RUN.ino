bool pin1,pin2;

void Run(int motor,float speed,int direction){
  if(direction==1){
    pin1=HIGH;
    pin2=LOW;
  }
  if(direction==0){
    pin1=LOW;
    pin2=HIGH;
  }
  if(motor==1){
    digitalWrite(leftMotor1, pin1);
    digitalWrite(leftMotor2, pin2);
    ledcWrite(pwmChannel, speed);
  }
  if(motor==2){
    digitalWrite(rightMotor1,pin1);
    digitalWrite(rightMotor2,pin2);
    ledcWrite(pwmChannel2,speed);
  }
}
