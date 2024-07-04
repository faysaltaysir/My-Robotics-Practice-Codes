void motor(int a, int b){
  if(a>=0){
    digitalWrite(left_motor_forward, 1);
    digitalWrite(left_motor_backward, 0);
//    Serial.print("left e ase right e jabe");
  }
  else{
    a=-a;
    digitalWrite(left_motor_forward, 0);
    digitalWrite(left_motor_backward, 1);
//     Serial.print("left e ase right e jabe");
  }
  if(b>=0){
    digitalWrite(right_motor_forward, 1);
    digitalWrite(right_motor_backward, 0);
//     Serial.print("right e ase left e jabe");
  }
  else{
    b=-b;
    digitalWrite(right_motor_forward, 0);
    digitalWrite(right_motor_backward, 1);
//    Serial.print("right e ase left e jabe");
    
  }
  analogWrite(left_motor_speed,a);
  analogWrite(right_motor_speed,b);
}
