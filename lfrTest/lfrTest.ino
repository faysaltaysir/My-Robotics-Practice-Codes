//int arr[] = { A0,A1,A2,A3,A4,A5,A7,A8,A10,A11,A12,A13,A14,A15};
int arr[] = { A15,A13,A11,A7,A1,A3,A14,A12,A10,A5,A4,A8,A2,A0};
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
for(int i=0;i<14;i++){
  pinMode(A0,INPUT);
}

}

void loop() {

for(int i=0;i<14;i++){
  Serial.print(analogRead(arr[i]));Serial.print(" ");
}
Serial.println(" ");delay(100);
}
