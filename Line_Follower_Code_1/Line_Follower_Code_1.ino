#define spl 18
#define spr 18
#define enA 11   // for left motor speed control with PWM
#define enB 5    // for right motor speed control with PWM
#define left_motor_forward 13
#define left_motor_backward 12
#define right_motor_forward 9
#define right_motor_backward 8

int s1, s2, s3, s4, s5, s6;  // A0 - A5
int s[6];
int threshold;
// int base[] = { 1, 2, 4, 8, 16, 32 };
int sensor;  // storing the final value
int sum;
int pos;
int a = 300;
int b = 300;
int c;

int spd = 250;

char flag = 's';

// sensor calibration
// motor speed test
// sensor show turned off
// line follow


void setup() {
  pinMode(left_motor_forward, OUTPUT);
  pinMode(left_motor_backward, OUTPUT);
  pinMode(right_motor_forward, OUTPUT);
  pinMode(right_motor_backward, OUTPUT);
  // pinMode(enA, OUTPUT);
  // pinMode(enB, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // Serial.print(analogRead(0));
  // Serial.print(" ");
   //sensorRead(b);  // ctrl + shift + n
  linefollow();
   //sensorShow(a);


  //if (reading == 0b001100) forward();
  //if (reading == 0b110000) left();
}
