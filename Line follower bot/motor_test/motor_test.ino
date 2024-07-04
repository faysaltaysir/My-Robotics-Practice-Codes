int kp,ki,kd; 
int leftMotorH =17; 
int leftMotorL =16; 
int enable1Pin =4; 
int rightMotorH =19; 
int rightMotorL = 18; 
int enable2Pin = 21;
// Setting PWM properties
const int freq = 30000;
const int pwmChannel = 0;
const int pwmChannel2 = 1;
const int resolution = 8;
int dutyCycle = 200;int speed=255;

void motor_setup(){
  pinMode(leftMotorH, OUTPUT);
  pinMode(leftMotorL, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  pinMode(rightMotorH, OUTPUT);
  pinMode(rightMotorL, OUTPUT);
  pinMode(enable2Pin, OUTPUT);
  // configure LED PWM functionalitites
  ledcSetup(pwmChannel, freq, resolution);
  ledcSetup(pwmChannel2, freq, resolution);
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(enable1Pin, pwmChannel);
  ledcAttachPin(enable2Pin, pwmChannel2);
}
void setup() {
  // put your setup code here, to run once:
 motor_setup();
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(rightMotorH,1);
digitalWrite(rightMotorL,0);
ledcWrite(pwmChannel2, speed-100);
digitalWrite(leftMotorH,1);
digitalWrite(leftMotorL,0);
ledcWrite(pwmChannel, speed+4-100);

}
