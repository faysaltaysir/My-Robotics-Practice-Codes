void setup() {
  // put your setup code here, to run once:
pinMode(5,INPUT);Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

int x=digitalRead(5);
Serial.println(x);
}
