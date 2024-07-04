
#define Kp 0.003  // find the best value speed controll
#define Ki 0.01
double Kd = .00543;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(Kp);
Serial.println(Ki);
Serial.println(Kd,4);

}
