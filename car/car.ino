int ena = 5; 
int enb = 6; 

int in1 = 8; 
int in2 = 9; 
int in3 = 10; 
int in4 = 11; 

 //speed controlling variable resistor
int mspeed = 70; // motor speed, the variable resistor value will be stored in this variable
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600); 
  pinMode(ena, OUTPUT); 
  pinMode(enb, OUTPUT); 

  pinMode(in1, OUTPUT); 
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

//  pinMode(sc, INPUT); 
 analogWrite(ena, 0); 
 analogWrite(enb, 0); 
}

void loop() {
mspeed = 0; 
mspeed = map(mspeed, 0, 1023, 0 , 255); 
analogWrite(ena, mspeed); 
analogWrite(enb, mspeed); 

 
  // forward
  digitalWrite(in1, HIGH); 
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);


   


}
