/*********
  Rui Santos
  Complete project details at http://randomnerdtutorials.com  
*********/

// Motor A
int motor1Pin1 = 7; 
int motor1Pin2 = 8; 
int enable1Pin = 11; 

//int motor2Pin1 = 36; 
//int motor2Pin2 = 38; 

int enable2Pin = 10; 
/*
// Setting PWM properties
const int freq = 30000;
const int pwmChannel = 0;
const int pwmChannel2 = 1;
const int resolution = 8;
int dutyCycle = 70;*/

void setup() {
  // sets the pins as outputs:
  //pinMode(motor1Pin1, OUTPUT);
  //pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(enable2Pin, OUTPUT);

  // configure LED PWM functionalitites
  //ledcSetup(pwmChannel, freq, resolution);
  //ledcSetup(pwmChannel2, freq, resolution);
  // attach the channel to the GPIO to be controlled
  //ledcAttachPin(enable1Pin, pwmChannel);
  //ledcAttachPin(enable2Pin, pwmChannel);
  Serial.begin(9600);

  // testing
  Serial.print("Testing DC Motor...");
}

void loop() {
  // Move the DC motor forward at maximum speed
  Serial.println("Moving Forward");
  //analogWrite(enable1Pin,0);
 // analogWrite(enable2Pin,200);
 // digitalWrite(motor1Pin1, HIGH);
  //digitalWrite(motor1Pin2, HIGH); 
  analogWrite(enable1Pin,255);
  analogWrite(enable2Pin,0);
  analogWrite(3,255);
  analogWrite(5,0);
  //digitalWrite(motor2Pin1, LOW);
  //digitalWrite(motor2Pin2, HIGH); 
 // delay(2000);
/*
  // Stop the DC motor
  Serial.println("Motor stopped");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  delay(1000);

  // Move DC motor backwards at maximum speed
  Serial.println("Moving Backwards");
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW); 
  delay(2000);

  // Stop the DC motor
  Serial.println("Motor stopped");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  delay(1000);

  // Move DC motor forward with increasing speed
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  while (dutyCycle <= 255){
    ledcWrite(pwmChannel, dutyCycle);   
    Serial.print("Forward with duty cycle: ");
    Serial.println(dutyCycle);
    dutyCycle = dutyCycle + 5;
    delay(500);
  }
  dutyCycle = 200;*/
}