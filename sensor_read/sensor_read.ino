#define left_motor_forward 4
#define left_motor_backward 3
#define right_motor_forward 8
#define right_motor_backward 7
#define left_motor_speed 5
#define right_motor_speed 6
#define head_light 13
#define spl 25 //left motor speed coeficient
#define spr 25 //right motor speed coeficient
int s[6]; //this is for storing analog value of each sensor
int thresould[] = {512, 512, 512, 512, 512, 512}; //this is the mid value for each sensor. use this array if you want to adjust midoint of each sensor individually
int base[6] = {1, 2, 4, 8, 16, 32}; //this is for binary to decimal conversion
int sensor; //this is to store final value after binary conversion
char flag = "s";
int sum = 0;
int pos;
void setup() {
  // put your setup code here, to run once:
  pinMode(left_motor_forward, OUTPUT);
  pinMode(left_motor_backward, OUTPUT);
  pinMode(left_motor_speed, OUTPUT);
  pinMode(right_motor_forward, OUTPUT);
  pinMode(right_motor_backward, OUTPUT);
  pinMode(right_motor_speed, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
// 
  reading();
//  line_follow();
 basic_line_follow();
  show_the_value();
//  motor(10*spl,10*spr);

}
