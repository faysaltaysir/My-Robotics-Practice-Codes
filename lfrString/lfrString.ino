
#define echoPin 2 
#define trigPin 3

class name{String roll;long duration;int distance;
  public:
  name(){
    
  }
  void read_roll(){
  	Serial.println("Enter your Roll.");  
  	while (Serial.available() == 0){  }  
    roll = Serial.readString();
  }
  void read_val(){
    digitalWrite(trigPin, LOW);
  	delayMicroseconds(2);
  	digitalWrite(trigPin, HIGH);
  	delayMicroseconds(10);
  	digitalWrite(trigPin, LOW);
  	duration = pulseIn(echoPin, HIGH);
  	distance = duration * 0.034 / 2;
  }
  void show_val(){
    Serial.print("Height: ");
	Serial.print(distance);
    Serial.println(" cm");
  }
  void show_roll(){
    Serial.print("Roll: ");
    Serial.print(roll);
    Serial.print(" ");
  }
  
};

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); pinMode(5,OUTPUT);
  Serial.begin(9600); 
  Serial.println("Ultrasonic Sensor HC-SR04 Test");
  Serial.println("with Arduino UNO R3");
  name x[15];int n;
  Serial.println("Enter number of students: ");  
  while (Serial.available() == 0){  }  
  n = Serial.parseInt();
  for(int i=0;i<n;i++){
 	x[i].read_roll();x[i].show_roll();x[i].read_val();x[i].show_val();
  	
  }
  
  Serial.println("press '1' to see the inputted list ");
  while (Serial.available() == 0){  }  
  int t = Serial.parseInt();
  if(t==1){
  	for(int j=0;j<n;j++){
 		x[j].show_roll();x[j].show_val();
  	}
  }
  
}
void loop() {
  
  }