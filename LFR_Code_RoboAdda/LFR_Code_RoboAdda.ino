#define spl 20
#define spr 20
#define enA 11  // for left motor speed control with PWM
#define enB 5   // for right motor speed control with PWM
#define left_motor_forward 13
#define left_motor_backward 12
#define right_motor_forward 8
#define right_motor_backward 9

int s1, s2, s3, s4, s5, s6;  // A0 - A5
int s[6];
int threshold;
int base[] = { 1, 2, 4, 8, 16, 32 };
int sensor;  // storing the final value
int sum;
int pos;
int b = 300;  // calibrated sensor value
int c;
int reading;

int spd = 250;  // maximum speed

char flag = 's';

// things to do

// sensor calibration
// motor speed test
// sensor show turned off
// line follow


void setup() {

  pinMode(left_motor_forward, OUTPUT);
  pinMode(left_motor_backward, OUTPUT);
  pinMode(right_motor_forward, OUTPUT);
  pinMode(right_motor_backward, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  sensorRead(b);  // ctrl + shift + n
  linefollow();
  sensorShow();
}
