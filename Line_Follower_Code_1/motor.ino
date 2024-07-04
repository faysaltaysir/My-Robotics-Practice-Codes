void motor(int e, int f){
  if(a>0){
    digitalWrite(left_motor_forward, 1);
    digitalWrite(left_motor_backward, 0);
  }
  else{
    a = -a;
    digitalWrite(left_motor_forward, 0);
    digitalWrite(left_motor_backward, 1);
  }
  if(b>0){
    digitalWrite(right_motor_forward, 1);
    digitalWrite(right_motor_backward, 0);
  }
  else{
    b = -b;
    digitalWrite(right_motor_forward, 0);
    digitalWrite(right_motor_backward, 1);
  }
  analogWrite(enA, a);  // enA == Left Motor Speed (lms)    255 -> 5V (max speed) 
  analogWrite(enB, b);  // enB == Right Motor Speed (rms)   255 -> 5V (max speed) 


}