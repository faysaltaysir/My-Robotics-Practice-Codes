void pid(){
  float motor_speed,speed=70,left_motor_speed,right_motor_speed,MaxSpeed=100;
  //float kp = speed / 4500;
  int error,last_error=0;
 // uint16_t position_black = qtr.readLineBlack(sensorValues);

  error=sensorValues[3]-sensorValues[6];
  float P=error;
  float I=I+error;
  float D=error-last_error;
  last_error=error;
  motor_speed = kp * P + ki * I + kd * D;
  left_motor_speed=speed+motor_speed;
  right_motor_speed=speed-motor_speed;
  if (right_motor_speed > MaxSpeed) right_motor_speed = MaxSpeed;  // prevent the motor from going beyond max speed
  if (left_motor_speed > MaxSpeed) left_motor_speed = MaxSpeed;    // prevent the motor from going beyond max speed
  if (right_motor_speed < 0) right_motor_speed = 0;
  if (left_motor_speed < 0) left_motor_speed = 0;
 // Serial.print("    ");
  //Serial.print(left_motor_speed);
  //Serial.print("    ");
  //Serial.println(right_motor_speed);
  Run(1,left_motor_speed,1);
  Run(2,right_motor_speed,1);
 // Serial.print( P ); Serial.println(' ');
  //Serial.println(kd * D);
}
