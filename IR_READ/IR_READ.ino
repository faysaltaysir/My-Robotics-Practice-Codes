
void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);pinMode(A1,INPUT);pinMode(A2,INPUT);pinMode(A3,INPUT);
pinMode(A4,INPUT);pinMode(7,INPUT);pinMode(8,INPUT);pinMode(9,INPUT);
pinMode(10,INPUT);pinMode(11,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print(analogRead(A0)); Serial.print(" ");
Serial.print(analogRead(A1)); Serial.print(" ");
Serial.print(analogRead(A2)); Serial.print(" ");
Serial.print(analogRead(A3)); Serial.print(" ");
Serial.print(analogRead(A4)); Serial.print(" ");
Serial.print(analogRead(A5)); Serial.print(" ");
// Serial.print(analogRead(8)); Serial.print(" ");
// Serial.print(analogRead(9)); Serial.print(" ");
// Serial.print(analogRead(10));Serial.print(" ");
// Serial.print(analogRead(11));Serial.print(" ");
Serial.println();delay(1000);
}
