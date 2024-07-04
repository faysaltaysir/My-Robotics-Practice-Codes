int arr[11]={13,12,14,27,26,25,33,32,35,34};
void setup() {
  // put your setup code here, to run once:
for(int i=0;i<10;i++){
  pinMode(arr[i],OUTPUT);
}
Serial.begin(9600);
int max=0;int min=0;

}

void loop() {
  // put your main code here, to run repeatedly:
 
for(int i=0;i<10;i++){
  Serial.print(analogRead(arr[i]));
  Serial.print(" ");
}
Serial.print("\n");
 
}
