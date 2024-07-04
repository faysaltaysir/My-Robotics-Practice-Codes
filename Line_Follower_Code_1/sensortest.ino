void sensorRead(int b){
  sensor = 0;
  sum=0;


  for(int i=0; i<6 ; i++){
    s[i]=analogRead(i);
    (s[i] > b) ? (s[i] = 1) : (s[i] = 0);  // condition for simplification
    sensor += s[i] * base[i];  // reading in binary
    sum+=s[i];
      
  }


  // s1=analogRead(0);
  // s2=analogRead(1);
  // s3=analogRead(2);
  // s4=analogRead(3);
  // s5=analogRead(4);
  // s6=analogRead(5);
}

void sensorShow(int a){

  // Analog to Digital

  if (s1 > a) s1 = 1; //black surface
  else s1 = 0; // white surface
  if (s2 > a) s2 = 1; //black surface
  else s2 = 0; // white surface
  if (s3 > a) s3 = 1; //black surface
  else s3 = 0; // white surface
  if (s4 > a) s4 = 1; //black surface
  else s4 = 0; // white surface
  if (s5 > a) s5 = 1; //black surface
  else s5 = 0; // white surface
  if (s6 > a) s6 = 1; //black surface -- reciever will give high reading
  else s6 = 0; // white surface

 // reading = s1*1 + s2*10 + s3*100 + s4*1000 + s5*10000 + s6*100000 ; --> it is in decimal
 // we have to do this in binary

  reading = s1*1 + s2*2 + s3*4 + s4*8 + s5*16 + s6*32 ;

  //for printing

  // for(int i=5; i>=0; i--){
  //   Serial.print(s[i]);
  //   Serial.print(" ");
  // }
  // Serial.println(string(sensor, 2));

  Serial.print(s1);
  Serial.print(" ");
  Serial.print(s2);
  Serial.print(" ");
  Serial.print(s3);
  Serial.print(" ");
  Serial.print(s4);
  Serial.print(" ");
  Serial.print(s5);
  Serial.print(" ");
  Serial.println(s6);



}