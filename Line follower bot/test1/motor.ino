void wait(){
  ledcWrite(leftMotorPWM, 0);
  ledcWrite(rightMotorPWM, 0);
}

void RUN(int motor, int speed, int direction){
  
  boolean inPin1=HIGH;
  boolean inPin2=LOW;
  
  if(direction == 1){
    inPin1 = HIGH;
    inPin2 = LOW;
    //1=FORWARD
  }  
  if(direction == 0){
    inPin1 = LOW;
    inPin2 = HIGH;
    //0=BACKWARD
  }

  if(motor == 1){
    digitalWrite(leftMotor1, inPin1);
    digitalWrite(leftMotor2, inPin2);
    ledcWrite(leftMotorPWM, speed);
    // 1=A
  }
  if(motor == 2){
    digitalWrite(rightMotor1, inPin1);
    digitalWrite(rightMotor2, inPin2);
    ledcWrite(rightMotorPWM, speed);
    // 2=B
  }  
}

void right_90(){
  int i;
  for(i=1; i<30; i++){
     RUN( 1 , 70 , 1);
     RUN( 2 , 70 , 0);
     delay(20);
  }
}

void left_90(){
  int i;
  for(i=1; i<30; i++){
     RUN( 1 , 70 , 0);
     RUN( 2 , 70 , 1);
     delay(20);
  }
}

void u_turn(){
  int i;
  for(i=1; i<60; i++){
     RUN( 1 , 70 , 0);
     RUN( 2 , 70 , 1);
     delay(20);
  }
}