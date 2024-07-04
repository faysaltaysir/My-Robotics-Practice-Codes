void motor(int e, int f){
  if(e>0){
    digitalWrite(left_motor_forward, 1);
    digitalWrite(left_motor_backward, 0);
  }
  else{
    e = -e;
    digitalWrite(left_motor_forward, 0);
    digitalWrite(left_motor_backward, 1);
  }
  if(f>0){
    digitalWrite(right_motor_forward, 1);
    digitalWrite(right_motor_backward, 0);
  }
  else{
    f = -f;
    digitalWrite(right_motor_forward, 0);
    digitalWrite(right_motor_backward, 1);
  }
  analogWrite(enA, e);  // enA == Left Motor Speed (lms)    255 -> 5V (max speed) 
  analogWrite(enB, f);  // enB == Right Motor Speed (rms)   255 -> 5V (max speed) 


}