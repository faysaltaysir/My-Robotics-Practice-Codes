void setup()
{
  Serial.begin(115200);
  
  qtr.setTypeRC();
  qtr.setSensorPins((const uint8_t[]){10,11,12,13,14,15,16,17,18,20}, SensorCount);  //Declare the sensor pin with arduino
 // qtr.setEmitterPin(8);//LEDON PIN
 // 34,35,32,33,25,26,27,14,12,13
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(rightMotorPWM, OUTPUT);
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(leftMotorPWM, OUTPUT);

  // configure LED PWM functionalitites
  ledcSetup(ledChannel, freq, resolution);

  // attach the channel to the GPIO to be controlled
  ledcAttachPin(rightMotorPWM, ledChannel);
  ledcAttachPin(leftMotorPWM, ledChannel);
  
  int i =0 ;
  for (int i = 0; i < 100; i++) // calibrate for sometime by sliding the sensors across the line, or you may use auto-calibration instead
  {
   //comment this part out for automatic calibration 
    if ( i  < 25 || i >= 75 ) // turn to the left and right to expose the sensors to the brightest and darkest readings that may be encountered
    {
      RUN(1, 170, 1);   // ( left motor , speed , high or low )
      RUN(2, 170, 0);   // ( right motor , speed , high or low )
      Serial.println("BBBBBBBBBB");
    }
    else
    {
      RUN(1, 170, 0);   // ( left motor , speed , high or low )
      RUN(2, 170, 1);   // ( right motor , speed , high or low )
      Serial.println("vVvvvvvv");
    }
    qtr.calibrate();   
    delay(20);
  }
  wait();

  int touch =touchRead(33);
  Serial.println(touch);
  int t = 0;
  while(t==0){
    int touch =touchRead(33);
    if(touch<10)break;
  }
  Serial.println("OKK");
  
}  

