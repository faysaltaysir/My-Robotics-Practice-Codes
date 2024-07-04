// int s1,s2,s3,s4,s5,s6; // A0 - A5
// int s[6];
int reading; // storing the final value
int base[]={1,2,4,8,16,32};


void serialbegin(){
  Serial.begin (9600);
}

void sensorreading(){
  // Serial.print(analogRead(0));
  // Serial.print(" ");
  sensorRead(b); // ctrl + shift + n
   sensorShow(a);

  // motor

  // if (reading == 0b001100) forward();
  // if (reading == 0b110000) left();

}

