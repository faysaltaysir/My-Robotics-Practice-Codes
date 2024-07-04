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
    digitalWrite(leftMotorH, pin1);
    digitalWrite(leftMotorL, pin2);
    //ledcWrite(pwmChannel, speed);
    analogWrite( enable1Pin,speed);
    
  }
  if(motor==2){
    digitalWrite(rightMotorH,pin1);
    digitalWrite(rightMotorL,pin2);
    //ledcWrite(pwmChannel2,speed);
    analogWrite(enable2Pin,speed);
  }
}


void left_90() {
  int i;//wait();delay(500);
  for (i = 1; i < 500; i++) {
    Run(1, 50, 0);  //left
    Run(2, 50, 1); 
    //delay(100); //right
    uint16_t Position = qtr.readLineBlack(sensorValues);
    if (Position > 4000 && Position < 5000) break;
  }
}
void right_30() {
  int i;//
  for (i = 1; i < 500; i++) {
    Run(1, 150, 1);  //left
    Run(2, 0, 0);  //right
    //delay(100);
    uint16_t Position = qtr.readLineBlack(sensorValues); //Serial.print("   ");Serial.print(Position);
    if (Position > 4000 && Position < 5000) break; 
  }
}
void turn_30_R(){
  uint16_t Position = qtr.readLineBlack(sensorValues);
   Run(1, 70, 1);  //left
    Run(2, 70, 1);delay(250);wait();
    while(Position==0 && Position==9000){
      Run(1, 50, 1);  //left
      Run(2, 50, 0);
    }
}
void right_90() {
  int i;//
  for (i = 1; i < 1500; i++) {
    Run(1, 50, 1);  //left
    Run(2, 50, 0);  //right
    //delay(100);
    Serial.print("R90");
    uint16_t Position = qtr.readLineBlack(sensorValues); //Serial.print("   ");Serial.print(Position);
    if (Position > 4000 && Position < 5000) break; 
  }Serial.print("R OUT");
}

void u_turn() {
  int i;
  for (i = 1; i < 60; i++) {
    Run(1, 150, 0);
    Run(2, 150, 1);
    delay(20);
    uint16_t Position = qtr.readLineBlack(sensorValues); //Serial.print("   ");Serial.print(Position);
    if (Position > 4000 && Position < 5000) break; 
  }
}
void wait() {
  Run(1, 0, 1);
    Run(2, 0, 1);
}
