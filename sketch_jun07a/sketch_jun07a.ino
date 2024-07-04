/***************left side****/
int r_pwmL=10;    // Black
int l_pwmL=11;    // White
int   renL=9;    //  Red
int   lenL=8;    //  brown
/**************Right*******/
int r_pwmR=6;     // Yellow
int l_pwmR=5;     // orange
int   renR=4;     // violet
int   lenR=3;     // Blue

int runSpd=200;

char val;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(r_pwmL,OUTPUT);
  pinMode(l_pwmL,OUTPUT);
  pinMode(renL,OUTPUT);
  pinMode(lenL,OUTPUT);
 
  pinMode(r_pwmR,OUTPUT);
  pinMode(l_pwmR,OUTPUT);
  pinMode(renR,OUTPUT);
  pinMode(lenR,OUTPUT);
  digitalWrite(renL,HIGH);
  digitalWrite(lenL,HIGH);
  digitalWrite(renR,HIGH);
  digitalWrite(lenR,HIGH);

}

void loop() {
analogWrite(r_pwmL,0);
analogWrite(l_pwmL,0);
analogWrite(r_pwmR,0);
analogWrite(l_pwmR,0);
}
