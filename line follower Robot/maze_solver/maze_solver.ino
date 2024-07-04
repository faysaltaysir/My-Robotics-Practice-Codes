//maze solver
// 1) Connect the sensor and scan for the junctions
// 2) Record the path and make the robot move
// 3) check if the destination is reached by the robot
// 4) optimize the recorded path
// 5) indicate the readiness of the user to follow line 

#include <AFMotor.h>
AF_DCMotor motor1(3);
AF_DCMotor motor2(4);

String path;    // path recorder

void setup(){
  Serial.begin(9600);
  for(int i=14;i<20;i++){
    pinMode(i, INPUT);
  }
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
void loop(){
  // SENSOR POSITION
  // 14 15 16 17 18 19 20
  // scan the  path

  // FORWARD CONDITION
  if(   ){
    //Serial.println("MOVE FORWARD");
    // path = path + 's'
    path += 'S';
    front();
  }
  // BACKWARD
  // middle sensors white
  if(       ){
    //move one inch ahead
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    delay(1000);
    if(   ){
      Serial.println("Move BACK");
      path += 'B';
      back();
    }
    else{
      // do something here 
      motor1.run(FORWARD);
    motor2.run(FORWARD);
    delay(1000);
    }
   
  }
  // LEFT
  if(  ){

  }

}
String path_optimize(){
  path.replace("LBL", "S");
  path.replace("LBS", "R");
  path.replace("RBL", "B");
  path.replace("SBS", "B");
  path.replace("SBL", "R");
  path.replace("LBR", "B");
  return path;
}












